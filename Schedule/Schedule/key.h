/*
	Author : lcm
	Date : 2015.3.24
	Define schedule's module and function
*/

#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define CLASS_NUM 22
#define MAX_NUM 2000

//int _sj[CLASS_NUM] = {0,2,1,3,2,1,3,2,1,3,2,1,3,2,1,3,2,3,3,2,3,3}; //����ʱ��Ȩֵ
int _sj[CLASS_NUM] = {0,3,2,5,3,2,5,3,2,5,3,2,5,3,2,5,3,5,5,3,5,5};

void RandomExchangeArray(int *arr,int l,int r) //�������ֵ��λ��
{
	if(!arr || l>=r) return;
	int count = 100 , i,j,t;
	srand((int)time(0));
	while(count--)
	{
		i = rand() % (r-l+1) + l;
		j = rand() % (r-l+1) + l;
		t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}

}
bool isError = false;
class Compare;
class student;
class student
{
public:
	int id;
	string name;
	bool plan[CLASS_NUM]; //���İ�
	bool result[CLASS_NUM]; //��ѡ�ϵİ�
	int num; //��������
	int resultnum; //��ѡ�ϵİ�����
	int w_time; //ʱ��Ȩֵ
	bool isSuperior; //�Ƿ�Ϊ�и߲�
	bool isPlan; //�Ƿ��б���
	friend Compare;
	student()
	{
		for(int i = 0;i <CLASS_NUM ; i++)
		{
			plan[i] = false;
			result[i] = false;
		}
		num = resultnum = w_time = 0;
		isSuperior = false;
	}

	void AddClassPlan(int class_id)
	{
		if(class_id<=0 || class_id>=CLASS_NUM)
		{
			cout<<"�����������������ţ�"<<id<<endl;
			isError = true;
			return;
		}
		plan[class_id] = true;
		isPlan = true;
		num++;
	}

	void SelectClass(int class_id)
	{
		result[class_id] = true;
		resultnum++;
		w_time += _sj[class_id];
	}

	void CancelClass(int class_id)
	{
		result[class_id] = false;
		resultnum--;
		w_time -= _sj[class_id];
	}
	/*
	bool lessthen(const student* a) const
	{
		if(!resultnum && a->resultnum) return false;
		else if(resultnum && !a->resultnum) return true;
		//else if(resultnum == a->resultnum) return a->num<num;
		else if(resultnum == a->resultnum)
		{
			if(num<a->num) return false;
			else if(num>a->num) return true;
			if(isSuperior && a->isSuperior) return a->num<num;
			if(isSuperior) return true;
			if(a->isSuperior) return false;
			return a->num<num;
		}
		else
		{
			return a->resultnum<resultnum;
		}
	}
	*/
	bool lessthen(const student* a) const
	{
		if(!w_time && a->w_time) return false;
		else if(w_time && !a->w_time) return true;
		//else if(resultnum == a->resultnum) return a->num<num;
		else if(w_time == a->w_time)
		{
			if(num<a->num) return false;
			else if(num>a->num) return true;
			/*
			if(isSuperior && a->isSuperior) return a->num<num;
			if(isSuperior) return true;
			if(a->isSuperior) return false;
			*/
			return a->num<num;
		}
		else
		{
			return a->w_time<w_time;
		}
	}
}stus[MAX_NUM];

class Compare
{
public:
	bool operator () (student * a,student *b) const
	{
		return a->lessthen(b);
	}
};

class WTime
{
	int maxnum; //ÿ�����������
	bool planSuperior;
public:
	int id; //�ð��id

	int stu_id[MAX_NUM]; //��¼�����ð�ε�ѧ��id
	int result_id[MAX_NUM]; //��¼�ɹ������ð��ѧ��id
	int plan_num; //��¼�����ð������
	int result_num; //��¼�ɹ������ð��ѧ������
	int superior_id;
	priority_queue<student*,vector<student*>,Compare> superior;
	priority_queue<student*,vector<student*>,Compare> stu;

	WTime()
	{
		superior_id = -1;
		plan_num = 0;
		result_num = 0;
		maxnum = 6;
		planSuperior = false;
	}

	void AddStuPlan(student * stu)
	{
		stu_id[plan_num++] = stu->id;	
	}

	void SetMaxNumber(int n)
	{
		maxnum = n;
	}

	void SetPlanSuperior(bool select)
	{
		planSuperior = select;
	}

	void solve()
	{
		int i;
		student * s;
		if(planSuperior)
		{
			for(i = 0;i<plan_num;i++)
				if(stus[stu_id[i]].isSuperior)
					superior.push(&stus[stu_id[i]]);
			if(!superior.empty())
			{
				s  = superior.top();
				superior_id = s->id;
				s->SelectClass(id);
				result_id[result_num++] = s->id;
				plan_num--;
			}
		}
		for(i=0;i<plan_num;i++)
		{
			if(stu_id[i]!=superior_id)
				stu.push(&stus[stu_id[i]]);
		}
		while(!stu.empty() && result_num<maxnum)
		{
			s = stu.top();
			stu.pop();
			s->SelectClass(id);
			result_id[result_num++] = s->id;
		}
		for(i = 0;i<plan_num;i++) stus[stu_id[i]].num--;
		RandomExchangeArray(result_id,0,result_num-1);
	}

	


}wt[CLASS_NUM];

void CheckExchangeClass(student * a,student * b) //�ð�ԭ����
{
	int i,j;
	if(a->id == b->id) return;

		for(i=1;i<CLASS_NUM;i++)
		{
			if(b->result[i] && a->plan[i] && !a->result[i] && wt[i].superior_id!=b->id && a->w_time+_sj[i]<=b->w_time-_sj[i])
			{
				cout<<b->name<<"�ð����"<<a->name<<endl;
				b->CancelClass(i);
				a->SelectClass(i);
				for(j=0;j<wt[i].result_num;j++)
					if(wt[i].result_id[j] == b->id)
					{
						wt[i].result_id[j] = a->id;
						return;
					}
			}else if(b->result[i] && a->plan[i] && !a->result[i] && wt[i].superior_id==b->id && a->w_time+_sj[i]<=b->w_time-_sj[i])
			{
				int k;
				for(k=1;k<wt[i].result_num;k++) //Ѱ�ҿ��滻�ľ���
					if(stus[wt[i].result_id[k]].isSuperior)
					{
						cout<<b->name<<"�ð����"<<a->name<<endl;
						wt[i].superior_id = wt[i].result_id[k];
						wt[i].result_id[0] = wt[i].result_id[k];
						wt[i].result_id[k] = a->id;
						b->CancelClass(i);
						a->SelectClass(i);
						return;
					}
			}
		}
}



void BookCheck(WTime * a,WTime *b) //�����ѡһ�����ൽ��ͤ
{
	int i,j,t;
	for(i=1;i<a->result_num;i++)
		for(j=1;j<b->result_num;j++)
			if(a->result_id[i] == b->result_id[j])
			{
				t = a->result_id[i];
				a->result_id[i] = a->result_id[a->result_num-1];
				a->result_id[a->result_num-1] = t;
				t = b->result_id[j];
				b->result_id[j] = b->result_id[b->result_num-1];
				b->result_id[b->result_num-1] = t;
			}
}