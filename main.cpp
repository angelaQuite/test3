//���������Ƶĵ�һ����ҵ������,Ŀ�����Զ�����30���������㣬Ҫ��֧�����������������
//2016/3/3

#include <iostream>
#include <cmath>
using namespace std;

//main����
void main()
{
	int ran1,ran2,ran3,ran4,oper;
	for(int i=0;i<30;i++)
	{
		ran1=rand()%100;//������һ�������
		ran2=rand()%100;//�����ڶ��������
		if(ran1>ran2)
		{
			int y=ran1;
			ran1=ran2;
			ran2=y;
		}
		if(ran2==0)
			ran2=rand()%100;
		ran3=rand()%100;
		ran4=rand()%100;
		if(ran4==0)
			ran4=rand()%100;
		if(ran3>ran4)
		{
			int y=ran3;
			ran3=ran4;
			ran4=y;
		}
		oper=rand()%4;//oper������������ʲô��������
		switch(oper)
		{
		case 0:
			cout<<"("<<ran1<<"/"<<ran2<<")"<<"+"<<"("<<ran3<<"/"<<ran4<<")"<<"="<<endl;//���м�����
			break;
		case 1:
			cout<<"("<<ran1<<"/"<<ran2<<")"<<"*"<<"("<<ran3<<"/"<<ran4<<")"<<"="<<endl;//���г�����
			break;
		case 2:
			cout<<"("<<ran1<<"/"<<ran2<<")"<<"-"<<"("<<ran3<<"/"<<ran4<<")"<<"="<<endl;//���м�����
			break;
		case 3:
			cout<<"("<<ran1<<"/"<<ran2<<")"<<"/"<<"("<<ran3<<"/"<<ran4<<")"<<"="<<endl;//���г�����
			break;
		}
	}
}