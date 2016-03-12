//张晓菲，2016/3/11
//要求：1、题目避免重复；
//      2、可定制（数量、打印方式）；
//      3、可以控制下列参数：是否有乘除法、是否有括号、数值范围、加减有无负数、除法有无余数。

#include<iostream>
#include<time.h>
#include <cmath>
#include<string>
#include<fstream>
using namespace std;

void main()
{
	srand( (unsigned)time( NULL ) );//时间种子防止每次产生的随机数相同
	int num1,num2,max,oper,mean1;
	int ran[10];
	int i;
	//ofstream fout;
	ofstream fout("1.txt"); 
	

	cout<<"请输入要打印的数量：";
	cin>>num1;
	if(num1<=0)
	{
		cout<<"请重新输入要打印的数量：";
		cin>>num1;
	}

	cout<<"请输入打印方式：(1、输出到文件 0、输出到屏幕)";
	cin>>mean1;

	cout<<"请输入可以允许随机产生的最大数值：";
	cin>>max;
	if(max<=0)
	{
		cout<<"请重新输入可以允许的最大数值：";
		cin>>max;
	}

	cout<<"请输入允许几个操作数：";
	cin>>num2;
	if(num2<=1)
	{
		cout<<"请重新输入允许几个操作数（1<x<=3）：";
		cin>>num2;
	}

	cout<<"请选择是否有乘除法（1：是 0：否）：";
	cin>>i;
	if(i!=1 && i!=0)
	{
		cout<<"请重新选择是否有乘除法（1：是 0：否）：";
		cin>>i;
	}

	for(int x=0;x<num1;x++)
		{
			for(int j=0;j<num2;j++)
			{
				ran[j]=rand()%(max+1);
			}
			oper=rand()%4;//oper用来决定进行什么四则运算
			switch(i)//用于选择是否有乘除法
			{
			case 0://没有乘除
				switch(num2)
			{
				case 2://有两个操作数
					switch(oper)
					{
					case 0:
					case 1:
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"+"<<ran[1]<<"="<<endl;//进行加运算
							break;
						case 0:
							cout<<ran[0]<<"+"<<ran[1]<<"="<<endl;//进行加运算
							break;
						}
						break;
					case 2:
					case 3:
						if(ran[0]<ran[1])
						{
							int a=ran[0];
							ran[0]=ran[1];
							ran[1]=a;
						}
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"-"<<ran[1]<<"="<<endl;//进行减运算
							break;
						case 0:
							cout<<ran[0]<<"-"<<ran[1]<<"="<<endl;
							break;
						}
						break;
					}
					break;
				case 3://有3个操作数
					switch(oper)
					{
					case 0:
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"+"<<ran[1]<<"+"<<ran[2]<<"="<<endl;
							break;
						case 0:
							cout<<ran[0]<<"+"<<ran[1]<<"+"<<ran[2]<<"="<<endl;
							break;
						}
						break;
					case 1:
						if(ran[1]<ran[2])
						{
							int a=ran[1];
							ran[1]=ran[2];
							ran[2]=a;
						}
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"+"<<ran[1]<<"-"<<ran[2]<<"="<<endl;
							break;
						case 0:
							cout<<ran[0]<<"+"<<ran[1]<<"-"<<ran[2]<<"="<<endl;
							break;
						}
						break;
					case 2:
						if((ran[0]-ran[1]-ran[2])<0)//判断结果是否为负数，如果是，则将减号变为加号输出
						{ 
							switch(mean1)
							{
							case 1:
								fout<<ran[0]<<"+"<<ran[1]<<"+"<<ran[2]<<"="<<endl;
								break;
							case 0:
								cout<<ran[0]<<"+"<<ran[1]<<"+"<<ran[2]<<"="<<endl;
								break;
							}
						}
						else
							switch(mean1)
							{
							case 1:
								fout<<ran[0]<<"-"<<ran[1]<<"-"<<ran[2]<<"="<<endl;
								break;
							case 0:
								cout<<ran[0]<<"-"<<ran[1]<<"-"<<ran[2]<<"="<<endl;
								break;
							}
						break;
					case 3:
						if(ran[0]<ran[1])//判断ran[0]-ran[1]是否大于0，小于则交换位置
						{
							int a=ran[0];
							ran[0]=ran[1];
							ran[1]=a;
						}
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"-"<<ran[1]<<"+"<<ran[2]<<"="<<endl;
							break;
						case 0:
							cout<<ran[0]<<"-"<<ran[1]<<"+"<<ran[2]<<"="<<endl;
							break;
						}
						break;
					}
					break;
				}
				break;
			case 1://有乘除
				switch(num2)
				{
					//如果有两个操作数
				case 2:
					switch(oper)
					{
					case 0:
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"+"<<ran[1]<<"="<<endl;//进行加运算
							break;
						case 0:
							cout<<ran[0]<<"+"<<ran[1]<<"="<<endl;//进行加运算
							break;
						}
						break;
					case 1:
						if(ran[0]<ran[1])
						{
							int a=ran[0];
							ran[0]=ran[1];
							ran[1]=ran[0];
						}
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"-"<<ran[1]<<"="<<endl;//进行减运算
							break;
						case 0:
							cout<<ran[0]<<"-"<<ran[1]<<"="<<endl;//进行减运算
							break;
						}
						break;
					case 2:
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"*"<<ran[1]<<"="<<endl;
							break;
						case 0:
							cout<<ran[0]<<"*"<<ran[1]<<"="<<endl;
							break;
						}
						break;
					case 3:
						if(ran[1]==0)
							ran[1]=rand()%100;//判断除数是否为0，如果是，则重新生成
						if(ran[0]%ran[1]!=0)
							ran[0]=ran[0]-ran[0]%ran[1];
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"/"<<ran[1]<<"="<<endl;//进行除运算
							break;
						case 0:
							cout<<ran[0]<<"/"<<ran[1]<<"="<<endl;//进行除运算
							break;
						}
						break;
					}
					break;

					//如果有三个操作数
				case 3:
					int oper1,oper2;
					oper1=rand()%16;
					oper2=rand()%16;
					string list[16];
					//固定表达式的形式，一共四种：A+B-C、A-B*C、A*B/C、A/B+C
					switch(oper1)
					{
					case 0:
					case 1:
					case 2:
					case 3:
						list[oper1]='+';
						list[oper2]='-';
						break;
					case 4:
					case 5:
					case 6:
					case 7:
						list[oper1]='-';
						list[oper2]='*';
						break;
					case 8:
					case 9:
					case 10:
					case 11:
						list[oper1]='*';
						list[oper2]='/';
						break;
					case 12:
					case 13:
					case 14:
					case 15:
						list[oper1]='/';
						list[oper2]='+';
						break;
					}
						//形如A/B+C的式子，判断B是否为0以及A/B是否能除尽
						if(oper1==12||oper1==13||oper1==14||oper1==15)
						{
							if(ran[1]==0)
								ran[1]=rand()%(max+1);
							if(ran[0]%ran[1]!=0)
								ran[0]=ran[0]-ran[0]%ran[1];
							switch(mean1)
							{
							case 1:
								fout<<ran[0]<<list[oper1]<<ran[1]<<list[oper2]<<ran[2]<<endl;
								break;
							case 0:
								cout<<ran[0]<<list[oper1]<<ran[1]<<list[oper2]<<ran[2]<<endl;
								break;
							}
						}
						//形如A+B/C的式子，判断C是否为0以及B/C是否能除尽
						if(oper1==8||oper1==9||oper1==10||oper1==11)
						{
							if(ran[2]==0)
								ran[2]=rand()%(max+1);
							if(ran[1]%ran[2]!=0)
								ran[1]=ran[1]-ran[1]%ran[2];
							switch(mean1)
							{
							case 1: 
								fout<<ran[0]<<list[oper1]<<ran[1]<<list[oper2]<<ran[2]<<endl;
								break;
							case 2:
								cout<<ran[0]<<list[oper1]<<ran[1]<<list[oper2]<<ran[2]<<endl;
								break;
							}
						}
						//形如A-B*C的式子，判断结果是否为负数，如果为负数，则判断A-B是否小于0，不小于则直接输出（A-B）*C,小于则交换AB位置
						if(oper1==4||oper1==5||oper1==6||oper1==7)
						{
							if((ran[0]-(ran[1]*ran[2]))<0)
							{
								if(ran[0]-ran[1]>=0)
								{
									switch(mean1)
									{
									case 1:
										fout<<'('<<ran[0]<<list[oper1]<<ran[1]<<')'<<list[oper2]<<ran[2]<<endl;
										break;
									case 0:
										cout<<'('<<ran[0]<<list[oper1]<<ran[1]<<')'<<list[oper2]<<ran[2]<<endl;
										break;
									}
								}
								else
								{
									int a=ran[0];
									ran[0]=ran[1];
									ran[1]=a;
									switch(mean1)
									{
									case 1:
										fout<<'('<<ran[0]<<list[oper1]<<ran[1]<<')'<<list[oper2]<<ran[2]<<endl;
										break;
									case 0:
										cout<<'('<<ran[0]<<list[oper1]<<ran[1]<<')'<<list[oper2]<<ran[2]<<endl;
										break;
									}
								}
							}
							else
								switch(mean1)
							{
								case 1:
									fout<<ran[0]<<list[oper1]<<ran[1]<<list[oper2]<<ran[2]<<endl;
									break;
								case 0:
									cout<<ran[0]<<list[oper1]<<ran[1]<<list[oper2]<<ran[2]<<endl;
									break;
							}
						}
						//形如A+B-C的式子，判断结果是否为负数，如果是，则交换B和C的位置

						if(oper1==0||oper1==1||oper1==2||oper1==3)
						{
							if(((ran[0]+ran[1])-ran[2])<0)
							{
								int a=ran[1];
								ran[1]=ran[2];
								ran[2]=a;
							}
							switch(mean1)
							{
							case 1:
								fout<<ran[0]<<list[oper1]<<ran[1]<<list[oper2]<<ran[2]<<endl;
								break;
							case 0:
								cout<<ran[0]<<list[oper1]<<ran[1]<<list[oper2]<<ran[2]<<endl;
								break;
							}
						}
						break;
				}
				break;
			}
		}
		fout.close();
}