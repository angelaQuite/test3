//�����ƣ�2016/3/11
//Ҫ��1����Ŀ�����ظ���
//      2���ɶ��ƣ���������ӡ��ʽ����
//      3�����Կ������в������Ƿ��г˳������Ƿ������š���ֵ��Χ���Ӽ����޸�������������������

#include<iostream>
#include<time.h>
#include <cmath>
#include<string>
#include<fstream>
using namespace std;

void main()
{
	srand( (unsigned)time( NULL ) );//ʱ�����ӷ�ֹÿ�β������������ͬ
	int num1,num2,max,oper,mean1;
	int ran[10];
	int i;
	//ofstream fout;
	ofstream fout("1.txt"); 
	

	cout<<"������Ҫ��ӡ��������";
	cin>>num1;
	if(num1<=0)
	{
		cout<<"����������Ҫ��ӡ��������";
		cin>>num1;
	}

	cout<<"�������ӡ��ʽ��(1��������ļ� 0���������Ļ)";
	cin>>mean1;

	cout<<"���������������������������ֵ��";
	cin>>max;
	if(max<=0)
	{
		cout<<"�����������������������ֵ��";
		cin>>max;
	}

	cout<<"��������������������";
	cin>>num2;
	if(num2<=1)
	{
		cout<<"������������������������1<x<=3����";
		cin>>num2;
	}

	cout<<"��ѡ���Ƿ��г˳�����1���� 0���񣩣�";
	cin>>i;
	if(i!=1 && i!=0)
	{
		cout<<"������ѡ���Ƿ��г˳�����1���� 0���񣩣�";
		cin>>i;
	}

	for(int x=0;x<num1;x++)
		{
			for(int j=0;j<num2;j++)
			{
				ran[j]=rand()%(max+1);
			}
			oper=rand()%4;//oper������������ʲô��������
			switch(i)//����ѡ���Ƿ��г˳���
			{
			case 0://û�г˳�
				switch(num2)
			{
				case 2://������������
					switch(oper)
					{
					case 0:
					case 1:
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"+"<<ran[1]<<"="<<endl;//���м�����
							break;
						case 0:
							cout<<ran[0]<<"+"<<ran[1]<<"="<<endl;//���м�����
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
							fout<<ran[0]<<"-"<<ran[1]<<"="<<endl;//���м�����
							break;
						case 0:
							cout<<ran[0]<<"-"<<ran[1]<<"="<<endl;
							break;
						}
						break;
					}
					break;
				case 3://��3��������
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
						if((ran[0]-ran[1]-ran[2])<0)//�жϽ���Ƿ�Ϊ����������ǣ��򽫼��ű�Ϊ�Ӻ����
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
						if(ran[0]<ran[1])//�ж�ran[0]-ran[1]�Ƿ����0��С���򽻻�λ��
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
			case 1://�г˳�
				switch(num2)
				{
					//���������������
				case 2:
					switch(oper)
					{
					case 0:
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"+"<<ran[1]<<"="<<endl;//���м�����
							break;
						case 0:
							cout<<ran[0]<<"+"<<ran[1]<<"="<<endl;//���м�����
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
							fout<<ran[0]<<"-"<<ran[1]<<"="<<endl;//���м�����
							break;
						case 0:
							cout<<ran[0]<<"-"<<ran[1]<<"="<<endl;//���м�����
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
							ran[1]=rand()%100;//�жϳ����Ƿ�Ϊ0������ǣ�����������
						if(ran[0]%ran[1]!=0)
							ran[0]=ran[0]-ran[0]%ran[1];
						switch(mean1)
						{
						case 1:
							fout<<ran[0]<<"/"<<ran[1]<<"="<<endl;//���г�����
							break;
						case 0:
							cout<<ran[0]<<"/"<<ran[1]<<"="<<endl;//���г�����
							break;
						}
						break;
					}
					break;

					//���������������
				case 3:
					int oper1,oper2;
					oper1=rand()%16;
					oper2=rand()%16;
					string list[16];
					//�̶����ʽ����ʽ��һ�����֣�A+B-C��A-B*C��A*B/C��A/B+C
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
						//����A/B+C��ʽ�ӣ��ж�B�Ƿ�Ϊ0�Լ�A/B�Ƿ��ܳ���
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
						//����A+B/C��ʽ�ӣ��ж�C�Ƿ�Ϊ0�Լ�B/C�Ƿ��ܳ���
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
						//����A-B*C��ʽ�ӣ��жϽ���Ƿ�Ϊ���������Ϊ���������ж�A-B�Ƿ�С��0����С����ֱ�������A-B��*C,С���򽻻�ABλ��
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
						//����A+B-C��ʽ�ӣ��жϽ���Ƿ�Ϊ����������ǣ��򽻻�B��C��λ��

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