#include <opencv2\opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

class xmlDetection{
	CascadeClassifier face_cascade;
public:
	vector<Rect> faces;
	xmlDetection(){
		face_cascade.load("haarcascade_frontalface_alt2.xml"); //加载训练样本
	}
	bool detect(Mat &img,Rect &rec){
		Mat img_gray;
		/*
		if(img.channels()!=1)
		{
			cvtColor(img,img_gray,CV_BGR2GRAY);
		}else{
			return false;
		}
		equalizeHist(img_gray,img_gray); // 使灰度图象直方图均衡化
		*/
		face_cascade.detectMultiScale(img,faces,1.1,3,0|CV_HAAR_SCALE_IMAGE,Size(30,30));
		if(faces.size()==0) return false;
		int maxn = 0;
		for(int i = 0;i<faces.size(); i++){
			if(faces[i].area() > maxn){
				rec = faces[i];
				maxn = rec.area();
			}
		}
		return true;
		

	}
};