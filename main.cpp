//这是张晓菲的第一个作业的完善,目的是自动生成30个四则运算，要求支持真分数的四则运算
//2016/3/3

#include <iostream>
#include <cmath>
using namespace std;

//main函数
void main()
{
	int ran1,ran2,ran3,ran4,oper;
	for(int i=0;i<30;i++)
	{
		ran1=rand()%100;//产生第一个随机数
		ran2=rand()%100;//产生第二个随机数
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
		oper=rand()%4;//oper用来决定进行什么四则运算
		switch(oper)
		{
		case 0:
			cout<<"("<<ran1<<"/"<<ran2<<")"<<"+"<<"("<<ran3<<"/"<<ran4<<")"<<"="<<endl;//进行加运算
			break;
		case 1:
			cout<<"("<<ran1<<"/"<<ran2<<")"<<"*"<<"("<<ran3<<"/"<<ran4<<")"<<"="<<endl;//进行乘运算
			break;
		case 2:
			cout<<"("<<ran1<<"/"<<ran2<<")"<<"-"<<"("<<ran3<<"/"<<ran4<<")"<<"="<<endl;//进行减运算
			break;
		case 3:
			cout<<"("<<ran1<<"/"<<ran2<<")"<<"/"<<"("<<ran3<<"/"<<ran4<<")"<<"="<<endl;//进行除运算
			break;
		}
	}
}