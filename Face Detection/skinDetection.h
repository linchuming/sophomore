#include <opencv2\opencv.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace cv;
using namespace std;

struct myRect{
	int bottom,top,left,right;
};

class rect_cmp{
public:
	bool operator () (const Rect& a,const Rect& b){
		return a.size().area() < b.size().area(); 
	}
};

class skinDetection{

	double _Cr(double p)
	{
		const int l = 125, h = 188;
		if(p < l ) return 154-10*(l-p) / 109.0;
		else if(p >= h) return 154-22*(p-h) / 47.0;
		else return p;
	}

	double _Cb(double p)
	{
		const int l = 125, h = 188;
		if(p < l) return 108+10*(l-p)/ 109.0;
		else if(p >= h) return 108+10*(p-h)/ 47.0;
		else return p;
	}

	double wCr(double y)
	{
		const int l = 125, h = 188;
		const double minn = 16, maxn = 235, wlc = 20, whc = 10;
		if(y < l) return wlc + (y-minn)*18.76/ 109.0;
		else if(y >= h) return whc + (maxn - y)*28.76/47.0;
		else return y;
	}

	double wCb(double y)
	{
		const int l = 125, h = 188;
		const double minn = 16, maxn = 235, wlb = 23, whb = 14;	
		if(y < l) return wlb + (y-minn)*23.97/ 109.0;
		else if(y >= h) return whb + (maxn - y)*32.97/47.0;
		else return y;
	}

	double CheckYCrCb(double y,double cr,double cb)
	{
		const int l = 125, h = 188;
		if(y < l || y > h ) {
			cr = (cr - _Cr(y)) * 38.76 / wCr(y) +_Cr(h);
			cb = (cb - _Cb(y)) * 46.97 / wCb(y) + _Cb(h);
		}
		cr = cr - 152.02; cb = cb - 109.38;
		double x1,y1;
		x1 = cb*cos(2.53) + cr*sin(2.53);
		y1 = cb*(-sin(2.53)) + cr*cos(2.53);
		return (x1-1.6)*(x1-1.6)/(25.39*25.39) + (y1-2.41)*(y1-2.41)/(14.03*14.03);
	}

	void SearchPoint(Mat& img,int x,int y,myRect &rec){
		if(x<0 || y<0 || x>=img.size().height || y>=img.size().width) return;
		Vec3b * p =img.ptr<Vec3b>(x,y);
		if((*p)[0]!=255) return;
		else{
		(*p)[0] = 0;
		queue<Point> q;
		q.push(Point(x,y));

		while(!q.empty()){
			x = q.front().x; y = q.front().y;
			q.pop();
			if(rec.top==-1){
			rec.bottom = rec.top = x;
			rec.left = rec.right = y;
			}
			if(rec.bottom > x ) rec.bottom = x;
			if(rec.top < x) rec.top = x;
			if(rec.left > y ) rec.left = y;
			if(rec.right < y ) rec.right = y;		
			if(y-1>=0){
				p = img.ptr<Vec3b>(x,y-1);
				if((*p)[0]==255){
					(*p)[0] = 0;
					q.push(Point(x,y-1));
				}
			}
			if(y+1<img.size().width){
				p = img.ptr<Vec3b>(x,y+1);
				if((*p)[0]==255){
					(*p)[0] = 0;
					q.push(Point(x,y+1));
				}
			}
			if(x-1>=0){
				p = img.ptr<Vec3b>(x-1,y);
				if((*p)[0]==255){
					(*p)[0] = 0;
					q.push(Point(x-1,y));
				}
			}
			if(x+1<img.size().height){
				p = img.ptr<Vec3b>(x+1,y);
				if((*p)[0]==255){
					(*p)[0] = 0;
					q.push(Point(x+1,y));
					}
				}
			}
		}
	}

	bool FindFlag(Mat &mval,Rect &output)
	{
		Rect rec;
		myRect r;
		int h,w;
		priority_queue<Rect,vector<Rect>,rect_cmp> rq;
		h = mval.size().height;
		w = mval.size().width;
		for(int i = 0;i<h; i++){
			for(int j = 0;j<w; j++){
				r.top = -1;
				SearchPoint(mval,i,j,r);
				if(r.top!=-1){
					rec.y = r.bottom;
					rec.x = r.left;
					rec.height = r.top - r.bottom;
					rec.width = r.right - r.left;
					double len = (double)rec.height/rec.width;
					if(len>=0.5&&len<=2.4) {
						rq.push(rec);
						faces.push_back(rec);
					}
				}

			}
		}
		if(!rq.empty()) {
			output = rq.top();
			return true;
		}else return false;
	}
	public:
		vector<Rect> faces;
		bool detectRect(Mat & img,Rect & rec)
		{
			if(img.channels()==1) return false;
			Mat l1,m1,result;
			cvtColor(img,m1,CV_BGR2YCrCb);
			result.create(img.size(),img.type());
			vector<Mat> ch;
			split(m1,ch);
			uchar *y = ch.at(0).ptr<uchar>(0,0);
			uchar *cr = ch.at(1).ptr<uchar>(0,0);
			uchar *cb = ch.at(2).ptr<uchar>(0,0);
			MatIterator_<Vec3b> it = result.begin<Vec3b>();
			int len = m1.size().width * m1.size().height;
			for(int i=0 ; i < len; i++){
				if(CheckYCrCb(*y,*cr,*cb)>=1.0){
					(*it)[0] = (*it)[1] = (*it)[2] = 0;
				}else{
					(*it)[0] = (*it)[1] = (*it)[2] = 255;
				}
				it++;
				y++; cr++; cb++;
			}
			erode(result,result,NULL,Point(-1,-1),5);
			dilate(result,result,NULL,Point(-1,-1),5);
			faces.clear();
			return FindFlag(result,rec);

		}

};