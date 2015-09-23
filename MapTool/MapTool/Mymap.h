#pragma once
#include "stdafx.h"
#include <cstdlib>
#include "string.h"
#include "windows.h"
#include <queue>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"
/*
  Author ：lcm
  Date : 2014.12.16
  读取xml并保存各地图节点、道路
  使用了rapidxml库
*/

#define NMAX 100
class Node;
class Mymap;
const int WAY_UNDEFINED = 0xFF;
const int WAY_MOTORWAT = 0x01;
const int WAY_MOTORWAT_LINK = 0x02;
const int WAY_TRUNK = 0x03;
const int WAY_PRIMARY = 0x04;
const int WAY_PRIMARY_LINK = 0x05;
const int WAY_SECONDARY = 0x06;
const int WAY_TERTIARY = 0x07;
const int WAY_UNCLASSIFIED = 0x08;
const int WAY_SERVICE = 0x09;
const int WAY_TRACK = 0x0A;
const int WAY_FOOTWAY = 0x0B;
const int WAY_WATERWAY = 0x0C;
const int WAY_OTHER = 0x0F;

double begin_lat,begin_lon,end_lat,end_lon;

using namespace rapidxml; //使用rapidxml命名空间

long long CharToInt64(const char*str) //将字符串转成long long
{
	int l = strlen(str);
	long long ans = 0;
	for(int i = 0;i<l;i++) ans = ans * 10 + str[i] - '0';
	return ans;
}



struct Link
{
	Node * nd;
	Link * next;
};

struct edge //邻接表保存图
{
	Node * nd;
	long double w;
	edge * next;
};
struct way
{
	Link * lk; //每条路所连接的点的链表
	way* next; //指向下一条路
	char * name; //路的名称，可无
	int size,flag;//flag记录路的类型
	way()
	{
		lk = NULL;
		next = NULL;
		name = NULL;
		size = 0;
		flag = WAY_UNDEFINED;
	}
};

void ClearLink(Link*);
void ClearEdge(edge*);
long double GetNodesDistance(Node*,Node*);
class Node
{
	edge* endLink;
public:
	long long id; 
	int my_id; //自己定义的id号
	double lat,lon;
	edge * Noderoad;
	Node()
	{
		id = 0;
		lat = lon = 0;
		Noderoad = NULL;
		endLink = NULL;
	}
	~Node()
	{
		if(Noderoad) ClearEdge(Noderoad);
	}
	Node(long long id,double lat,double lon)
	{
		this->id = id;
		this->lat = lat;
		this->lon = lon;
	}
	void AddConnentNode(Node* n)
	{
		if(n==NULL) return;
		edge * newLink = new edge;
		newLink->nd = n;
		newLink->w = GetNodesDistance(this,n);
		newLink->next = NULL;
		if(endLink)
		{
			endLink->next = newLink;
			endLink = newLink;
		}else
		{
			endLink = newLink;
			Noderoad = newLink;
		}
	}
};

//求两点距离，用long double 表示，减少精度误差
long double GetNodesDistance(Node* n1,Node* n2)
{
	long long lat1,lon1,lat2,lon2;
	lat1 = (long long)(n1->lat * 10000000);
	lon1 = (long long)(n1->lon * 10000000);
	lat2 = (long long)(n2->lat * 10000000);
	lon2 = (long long)(n2->lon * 10000000);
	return sqrt((lat1-lat2)*(lat1-lat2) + (lon1-lon2)*(lon1-lon2));

}

/*
	如下一些释放内存操作
*/
	void ClearNode(Link * l) //用于清除hashlink下接的链表以及对应的node
	{
		Link * p = l->next,*tmp;
		if(l->nd) delete l->nd;
		while(p)
		{
			tmp = p->next;
			if(p->nd) delete p->nd;
			delete p;
			p = tmp;
		}
	}
	void ClearLink(Link * lk)
	{
		Link* p = lk,*tmp;
		while(p)
		{
			tmp = p->next;
			delete p;
			p = tmp;
		}
		

	}
	void ClearEdge(edge * lk)
	{
		edge* p = lk,*tmp;
		while(p)
		{
			tmp = p->next;
			delete p;
			p = tmp;
		}
		

	}
	void ClearWay(way * w) //清除所有的way
	{
		way * p = w,*tmp;
		while(p)
		{
			tmp = p->next;
			ClearLink(p->lk);
			if(p->name) delete p->name;
			delete p;
			p = tmp;
		}
		
	}
	int ClassifyWay(char * str) //道路分类
	{
		if(strcmp(str,"motorway") == 0)
			return WAY_MOTORWAT;
		else if(strcmp(str,"motorway_link") == 0)
			return WAY_MOTORWAT_LINK;
		else if(strcmp(str,"trunk") == 0)
			return WAY_TRUNK;
		else if(strcmp(str,"primary") == 0)
			return WAY_PRIMARY;
		else if(strcmp(str,"primary_link") == 0)
			return WAY_PRIMARY_LINK;
		else if(strcmp(str,"secondary") == 0)
			return WAY_SECONDARY;
		else if(strcmp(str,"tertiary") == 0)
			return WAY_TERTIARY;
		else if(strcmp(str,"unclassified") == 0)
			return WAY_UNCLASSIFIED;
		else if(strcmp(str,"residential") == 0)
			return WAY_UNCLASSIFIED;
		else if(strcmp(str,"service") == 0)
			return WAY_SERVICE;
		else if(strcmp(str,"track") == 0)
			return WAY_TRACK;
		else if(strcmp(str,"footway") == 0)
			return WAY_FOOTWAY;
		else return WAY_OTHER;
	}

	/*
	以下是Mymap的定义
	*/
class Mymap
{
	const static int mod = 1000003; //取模hash
	Link*hashlink; //hash节点
	way * rootway; //way的root节点
	file<> * fdoc;
	xml_document<> * doc;
	xml_node<> * root , *pEle;
	xml_attribute<> * attr;
	int size;

public:
	double minlat,minlon,maxlat,maxlon; //保存osm给定的数据范围
	Mymap()
	{
		hashlink = new Link[mod+1];
		for(int i = 0;i<mod;i++)
		{
			hashlink[i].nd =  NULL;
			hashlink[i].next = NULL;
		}
		root = NULL;
		rootway = NULL;
		minlat = minlon = 1000;
		maxlat = maxlon = -1000;
		size = 0;
	}
	~Mymap()
	{
		for(int i = 0;i<mod;i++)
			ClearNode(&hashlink[i]);
		delete[] hashlink;
		ClearWay(rootway);
	}
	bool LoadMapFile(char * filename)
	{
		fdoc = new file<>(filename);
		doc = new xml_document<>;
		doc->parse<0>(fdoc->data());
		if(!doc) return false; //打开文件失败处理
		root = doc->first_node();
		if(!root) return false;
		if(strcmp(root->name(),"osm")) return false; //打开非osm文件处理
		//读取数据范围
		pEle = root->first_node("bounds");
		attr = pEle->first_attribute("minlat");
		minlat = strtod(attr->value(),NULL);
		attr = pEle->first_attribute("minlon");
		minlon = strtod(attr->value(),NULL);
		attr = pEle->first_attribute("maxlat");
		maxlat = strtod(attr->value(),NULL);
		attr = pEle->first_attribute("maxlon");
		maxlon = strtod(attr->value(),NULL);
		//读取node点
		pEle = root->first_node("node");
		while(pEle)
		{
			Node * n = new Node(); size++;
			n->my_id = size; //my_id 记录自己是当前第几个点
			attr = pEle->first_attribute("id"); //找到node的属性id
			n->id = CharToInt64(attr->value());
			attr = attr->next_attribute("lat");
			n->lat = strtod(attr->value(),NULL);
			attr = attr->next_attribute("lon");
			n->lon = strtod(attr->value(),NULL);
			//存入hash链表
			int i = n->id % mod;
			Link*lk = &hashlink[i];
			
			if(!lk->nd) lk->nd = n;
			else
			{
				while(lk->next) lk = lk ->next;
				Link*nk = new Link;
				nk->next = NULL; nk->nd = n;
				lk->next = nk;
			}
			pEle = pEle->next_sibling("node"); //寻找下一个node
		}
		//读取way点
		pEle = root->first_node("way");
		rootway = new way;
		way * w; Link * lk;
		xml_node<> * nd;
		Node * node,*prenode; long long id;
		w = rootway; w->lk = NULL; w->next = NULL;
		while(pEle)
		{

			lk = new Link;
			lk->nd = NULL; lk->next = NULL;
			if(!rootway->lk) rootway->lk = lk;
			else
			{
				way * nw = new way;
				nw->lk = lk; nw->next = NULL;
				w->next = nw; w = nw;
			}
			nd = pEle->first_node("nd");
			prenode = NULL;
			while(nd)
			{
				attr = nd->first_attribute("ref");
				id = CharToInt64(attr->value());
				node = HashNode(id);
				if(node)
				{
					if(prenode) //如果上个节点不为空，则上个节点与本节点连接加边
					{
						prenode->AddConnentNode(node);
						node->AddConnentNode(prenode);
					}
					prenode = node;
					if(!lk->nd) lk->nd = node;
					else
					{
						Link*nk = new Link;
						nk->nd = node; nk->next = NULL;
						lk->next = nk; lk = nk;
						w->size++;
					}
				}
				nd = nd->next_sibling("nd");
			}
			nd = pEle->first_node("tag");
			while(nd)
			{
				attr = nd->first_attribute();
				if(strcmp(attr->value(),"name") == 0)
				{
					attr = attr->next_attribute();
					w->name = new char[NMAX];
					wchar_t sz[100] = {0};
					MultiByteToWideChar(CP_UTF8, 0, attr->value(), -1, sz, 100); //ansi char TO Unicode
					WideCharToMultiByte(CP_ACP,0,sz,-1,w->name,NMAX,NULL,NULL); //Unicode to ansi char
				}else if(strcmp(attr->value(),"highway") == 0) //给道路分类
				{
					attr = attr->next_attribute();
					w->flag = ClassifyWay(attr->value());

				}else if(strcmp(attr->value(),"waterway") == 0)
					w->flag = WAY_WATERWAY;
				nd = nd->next_sibling("tag");
			}
			pEle = pEle->next_sibling("way");
		}
		delete doc;
		delete fdoc;
		return true;
	

	}
	Node * HashNode(long long hash) //根据id返回node
	{
		int n = hash % mod;
		Link* lk = &hashlink[n];
		if(lk->nd == NULL) return NULL;
		while(lk && lk->nd->id != hash) lk = lk->next;
		if(lk) return lk->nd; else return NULL;
	}

	int Size()
	{
		return size;
	}

	way* GetWay()
	{
		return rootway;
	}
	
};

struct Prenode
{
	Node * node;
	int id;
};

class ShortestPath
{
	Node * begin_node,*end_node;
	way* ways;
	Prenode * pre;
	int size;
	
	//spfa init
	bool * v;
	long double * d;
	Node * q[1000001];
	//end_spfa
	Node* FindNode(double lat,double lon,way* ways)
	{
		if(ways==NULL) return NULL;
		long long lat1,lat2,lon1,lon2;
		long long minn = 9223372036854775807L,dis; Node * node = NULL; way* lw = ways;
		Link *lk;
		lat1 = lat * 10000000; lon1 = lon * 10000000;
		while(lw)
		{
			if(lw->flag!=WAY_UNDEFINED && lw->flag!=WAY_WATERWAY)
			{
				lk = lw->lk;
				while(lk)
				{
					lat2 = lk->nd->lat*10000000;
					lon2 = lk->nd->lon*10000000;
					dis = (lat1-lat2)*(lat1-lat2) + (lon1-lon2)*(lon1-lon2);
					if(minn>dis)
					{
						minn = dis;
						node = lk->nd;
					}
					lk=lk->next;
				}
			}
			lw = lw->next;
		}
		return node;
	}
public:
	long double distance;
	ShortestPath()
	{
		begin_node = end_node = NULL;
		ways = NULL; pre = NULL;
		size = 0;
	}
	~ShortestPath()
	{
		if(pre) delete[] pre;
		if(v) delete[] v;
		if(d) delete[] d;
	}
	void InitPath(Mymap * map)
	{
		ways = map->GetWay();
		size = map->Size();
		pre = new Prenode[size+1]; //记录路径的pre数组
		v = new bool[size+1];
		d = new long double [size+1];
	}
	Prenode * GetPathInfo()
	{
		return pre;
	}
	Node* SetBeginPath(double lat,double lon)
	{
		begin_node = FindNode(lat,lon,ways);
		return begin_node;
	}
	Node* SetEndPath(double lat,double lon)
	{
		end_node = FindNode(lat,lon,ways);
		return end_node;
	}

	Prenode * FindShortPath() //Use spfa algorithm
	{
		if(!begin_node || !end_node) return NULL;
		int i,h,l;
		Node * u;
		edge * lk;
		long long dis;
		long long maxn = 9223372036854775807L;
		for(i=0;i<=size;i++) 
		{
			d[i] = maxn;
			v[i] = false;
		}
		d[begin_node->my_id] = 0; h = 0; l =1; q[1] = begin_node;
		v[begin_node->my_id] = true;
		pre[begin_node->my_id].id = 0;
		while(h!=l)
		{
			h++; if(h>1000000) h = 1;
			u = q[h];
			lk = u->Noderoad;
			while(lk)
			{
				dis = lk->w;

				if(d[lk->nd->my_id] > d[u->my_id] + dis )
				{
					d[lk->nd->my_id] = d[u->my_id] + dis;
					pre[lk->nd->my_id].id = u->my_id;
					pre[lk->nd->my_id].node = u;
					if(!v[lk->nd->my_id])
					{
						l++; if(l>1000000) l = 1;
						q[l] = lk->nd;
						v[lk->nd->my_id] = true;
					}
				}
				lk = lk->next;
			}
			v[u->my_id] = false;
		}
		distance = d[end_node->my_id];
		return pre;

	}
	struct state
	{
		long double d,d1;
		Node * nd;
		state()
		{
			nd = NULL;
		}
		bool operator < (const state & a) const
		{
			return d>a.d;
		}
	};
	Prenode * FindShortPath2() //use dijkstra + priority_queue + A*
	{
		if(!begin_node || !end_node) return NULL;
		long long maxn = 9223372036854775807L;
		std::priority_queue<state> q;
		int i;
		for(i=0;i<=size;i++) d[i] = maxn;
		d[begin_node->my_id] = 0;
		state t,p;
		edge * lk;
		t.nd = begin_node;
		t.d = 0; t.d1 = 0;  q.push(t);
		pre[begin_node->my_id].id = 0;
		while(!q.empty())
		{
			t = q.top(); q.pop();
			if(t.nd->my_id == end_node->my_id) { distance = d[end_node->my_id];return pre; }
			lk = t.nd->Noderoad;
			while(lk)
			{
				p.nd = lk->nd;
				p.d1 = d[t.nd->my_id]+lk->w;
				if(p.d1<d[p.nd->my_id])
				{
					d[p.nd->my_id] = p.d1;
					p.d = p.d1 + GetNodesDistance(p.nd,end_node);
					pre[p.nd->my_id].id = t.nd->my_id;
					pre[p.nd->my_id].node = t.nd;
					q.push(p);
				}
				lk = lk->next;
			}
		}
		return pre;
	}
};