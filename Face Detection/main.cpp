#include "skinDetection.h"
#include "xmlDetection.h"
#include <string>
#include <io.h>
int main()
{
	skinDetection sd;
	xmlDetection xd;
	Rect rec;
	const char* to_search ="photo\\*.jpg";
	intptr_t handle;
	string str;

	freopen("E:\\facerect.txt","w",stdout);

	_finddata_t fileinto;
	handle = _findfirst(to_search,&fileinto);
	if(handle == -1) return 0 ;
	Mat img; 
	str = fileinto.name;
	img = imread("photo\\" + str);
	/*
	if(!xd.detect(img,rec)){
		sd.detectRect(img,rec);
		for(int i = 0; i<sd.faces.size(); i++) rectangle(img,sd.faces[i],Scalar(0,255,255),2);
	}else{
		for(int i = 0; i<xd.faces.size(); i++) rectangle(img,xd.faces[i],Scalar(0,255,255),2);
	}*/
	
	if(!xd.detect(img,rec)) sd.detectRect(img,rec);
	rectangle(img,rec,Scalar(0,255,255),2);
	
	//imshow("str",img);
	//waitKey();
	imwrite("E:\\result3\\" + str,img);
	//cout<<str<<endl;
	cout<<rec.x<<" "<<rec.x+rec.width<<" "<<rec.y<<" "<<rec.y+rec.height<<endl;
	while(!_findnext(handle,&fileinto)){
		str = fileinto.name;
		img = imread("photo\\" + str);
		/*
		if(!xd.detect(img,rec)){
			sd.detectRect(img,rec);
			for(int i = 0; i<sd.faces.size(); i++) rectangle(img,sd.faces[i],Scalar(0,255,255),2);
		}else{
			for(int i = 0; i<xd.faces.size(); i++) rectangle(img,xd.faces[i],Scalar(0,255,255),2);
		}*/
		
		if(!xd.detect(img,rec)) {
			sd.detectRect(img,rec);
			rectangle(img,rec,Scalar(0,0,255),2);
		}else{
			rectangle(img,rec,Scalar(0,255,255),2);
		}
		
		//imshow("str",img);
		//waitKey();
		imwrite("E:\\result3\\" + str,img);
		//cout<<str<<endl;
		cout<<rec.x<<" "<<rec.x+rec.width<<" "<<rec.y<<" "<<rec.y+rec.height<<endl;
	}
	waitKey();
	_findclose(handle);
	return 0;
}