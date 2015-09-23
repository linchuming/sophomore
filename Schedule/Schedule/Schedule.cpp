// Schedule.cpp : 定义控制台应用程序的入口点。
//

/*
	Author : lcm
	Date : 2015.3.24
	Main program of schedule
*/

#include "stdafx.h"
#include "key.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int n; //总人数
int random[MAX_NUM];
int randid[CLASS_NUM];


void Randomize(int n)
{
	srand((int)time(0));
	int i,j,t;
	for(i=1;i<=n;i++)
	{
		j = rand() % n + 1;
		t = random[i];
		random[i] = random[j];
		random[j] = t;
	}
}

void RandomizeId(int n)
{
	srand((int)time(0));
	int i,j,t;
	for(i=1;i<=n;i++)
	{
		j = rand() % n + 1;
		t = randid[i];
		randid[i] = randid[j];
		randid[j] = t;
	}
}

int InvertClassId(int x)
{
	if(x<10 || (x%10)>=4) return 0;
	return (x/10-1)*3 + (x%10);
}

int ShowClassId(int x)
{
	return ((x-1)/3+1)*10 + ((x-1)%3)+1;
}

void FindClassId(int stu_id,string str)
{
	int id = 0,i;
	for(i=0;i<str.length();i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			id = id * 10 + str[i] - '0';
		}else{
			if(id>0)
			{
				if(id%10)
					stus[stu_id].AddClassPlan(InvertClassId(id));
				else
				{
					stus[stu_id].AddClassPlan(InvertClassId(id+1));
					stus[stu_id].AddClassPlan(InvertClassId(id+2));
					stus[stu_id].AddClassPlan(InvertClassId(id+3));
				}

			}
			id = 0;
		}
	}
	if(id>0){
				if(id%10)
					stus[stu_id].AddClassPlan(InvertClassId(id));
				else
				{
					stus[stu_id].AddClassPlan(InvertClassId(id+1));
					stus[stu_id].AddClassPlan(InvertClassId(id+2));
					stus[stu_id].AddClassPlan(InvertClassId(id+3));
				}
	}
}
void Readln()
{
	if(freopen("1.txt","r",stdin)==NULL)
	{
		cout<<"找不到1.txt文件！"<<endl;
		freopen("CON","r",stdin);
		system("pause");
		exit(0);
	}
	int id,superior,i; string str,tmp;
	n = 0;
	while(cin>>id)
	{
		//cin>>id>>str>>superior>>p;
		cin>>str>>superior;
		stus[id].id = id;
		if(superior!=0 && superior!=1)
		{
			cout<<"编号为"<<id<<"的数据有误，请检查！"<<endl;
			system("pause");
			exit(0);
		}
		if(superior) stus[id].isSuperior = true;
		stus[id].name = str;
		getline(cin,tmp);
		FindClassId(id,tmp);

    
		n++;
	}

	for(i=1;i<=n;i++) random[i] = i;
	for(int k=1;k<=n;k++) Randomize(n);
	int j;
	for(i=1;i<CLASS_NUM;i++)
	{
		for(int k=1;k<=n;k++) Randomize(n);
		for(j=1;j<=n;j++)
			if(stus[random[j]].plan[i])
				wt[i].AddStuPlan(&stus[random[j]]);
	}
	
}

void ExportCSV() //将排班表导出到CSV格式
{
	freopen("Schedule.csv","w",stdout);
	cout<<",周一,周二,周三,周四,周五,周六,周日"<<endl;
	cout<<"A班：";
	int i,j,k;
	for(i=0;i<7;i++)
	{
		j = 1; 
		for(k=0;k<7;k++)
		{
			if(i<wt[j].result_num) 
				cout<<","<<stus[wt[j].result_id[i]].name;
			else
				cout<<",";
			j+=3;
		}
		cout<<endl;
	}
	cout<<","<<endl;
	cout<<"B班：";
	for(i=0;i<7;i++)
	{
		j = 2; 
		for(k=0;k<7;k++)
		{
			if(i<wt[j].result_num) 
				cout<<","<<stus[wt[j].result_id[i]].name;
			else
				cout<<",";
			j+=3;
		}
		cout<<endl;
	}
	cout<<","<<endl;
	cout<<"C班：";
	for(i=0;i<7;i++)
	{
		j = 3; 
		for(k=0;k<7;k++)
		{
			if(i<wt[j].result_num) 
				cout<<","<<stus[wt[j].result_id[i]].name;
			else
				cout<<",";
			j+=3;
		}
		cout<<endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	Readln();
	freopen("CON","r",stdin ); 
	if(isError)
	{
		system("pause");
		return 0;
	}
	cout<<"读入1.txt文件数据完毕！"<<endl;
	int i,j;
	for(i=1;i<CLASS_NUM;i++) { wt[i].id = i; randid[i] = i; }
	for(i=1;i<CLASS_NUM;i++) RandomizeId(7);
	//wt[15].SetMaxNumber(7);
	//wt[15].SetPlanSuperior(false);
	/*
	for(i=1;i<=7;i++)
	{
		j = (randid[i]-1) * 3;
		wt[j+1].solve();
		wt[j+2].solve();
		wt[j+3].solve();
		
	}*/

	//按班的报名人数升序排班
	cout<<"正在按每班报名人数升序排班！"<<endl;
	int min = (1<<31) - 1 , dmin;
	bool vis[CLASS_NUM];
	for(i = 1; i<CLASS_NUM; i++) vis[i] = false;
	for(i = 1;i < CLASS_NUM; i++)
	{
		min = (1<<31) - 1;
		for(j = 1; j < CLASS_NUM; j++)
		{
			if(!vis[j] && min>wt[j].plan_num)
			{
				min = wt[j].plan_num;
				dmin = j;
			}
		}
		vis[dmin] = true;
		if(min!=0) wt[dmin].solve();
	}
	cout<<"排班完毕，下面进行让班原则："<<endl;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			CheckExchangeClass(&stus[random[i]],&stus[j]); //让班原则
	cout<<"让班处理完毕，下面进行书亭连班处理："<<endl;
	//尽量让书亭连班。
	BookCheck(&wt[1],&wt[2]);
	BookCheck(&wt[4],&wt[5]);
	BookCheck(&wt[7],&wt[8]);
	BookCheck(&wt[10],&wt[11]);
	BookCheck(&wt[13],&wt[14]);
	cout<<"书亭连班处理完毕！"<<endl;
	freopen("detail.txt","w",stdout);
	int count= 0;
	for(i=1;i<=n;i++)
	{
		student& out = stus[i];
		cout<<out.id<<" "<<out.name<<" "<<out.resultnum<<" ";
		count+=out.resultnum;
		for(j=1;j<CLASS_NUM;j++)
			if(out.result[j])
				cout<<ShowClassId(j)<<" ";
		cout<<"W："<<out.w_time<<" ";
		cout<<endl;
	}
	//cout<<count<<endl;
	cout<<endl;
	cout<<"有报班但没有排上的员工：";
	for(i=1;i<=n;i++)
	{
		if(stus[i].isPlan && !stus[i].resultnum) cout<<stus[i].name<<" "; 
	}
	cout<<endl; cout<<endl;
	
	cout<<"------------------------以下是排班表------------------------"<<endl;
	for(int i=1;i<CLASS_NUM;i++)
	{
		cout<<ShowClassId(i)<<":";
		for(j=0;j<wt[i].result_num;j++)
			cout<<stus[wt[i].result_id[j]].name<<" ";
		cout<<endl;
	}
	
	ExportCSV();
	freopen("CON","w",stdout ); 
	cout<<"排班表生成完毕！\n请在Schedule.csv查看排班表，更多细节可查看detail.txt！"<<endl;
	system("pause");
	return 0;
}

