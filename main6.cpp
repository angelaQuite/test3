//��Կ�����Ա�������� ����
//����ʵ����ĿΪ�����ά�����е������ͨ������ĺ�
#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
#define N 100

typedef struct
{
	int array[N];
	int col[N][N];
	int countnum;
}Struct;//����ṹ�����

void input(Struct &num, int x, int y)
{//input����ʵ�ִ��ļ��ж�ȡ�к��в��������Ļ��
	num.countnum = x*y;
	int i = 1;
	int a, b;
	ifstream in = ifstream("input.txt");
	in >> a;
	in >> b;
	num.countnum = a*b;
	while (in >> num.array[i])
	{//��in�ļ��е����ֶ�ȡ��������
		++i;
	}
	in.close();//��ȡ��Ϲر��ļ�in
    for (int i = 1; i <= num.countnum; i++)
	{
        cout << num.array[i] << " ";
		if (i%b == 0)
		{
			cout << endl;
		}
	}//����ļ���������鵽��Ļ
	for (int i = 1; i <= num.countnum; i += y)
	{
		for (int j = i; j <= i + y - 2; j++)
		{
			num.col[j][j + 1] = 1;
			num.col[j + 1][j] = 1;
		}
	}
	for (int i = 1 + y; i<num.countnum; i += y)
	{
		for (int j = i; j <= i + x - 1; j++)
		{
			num.col[j][j - y] = 1;
			num.col[j - y][j] = 1;
		}
	}
}

void traverse(Struct &num, int v, int visit[], int &b, int &max, int x)
{//ͨ��������ı���Ѱ�������ͨ������
	int a = 0, var = 0;
	visit[v] = 1;
    max += num.array[v];
	if (max >= b)
	{
		b = max;
	}
   for (int w = 1; w <= num.countnum; w++)
	{
		for (int c = 1; c <= num.countnum; c++)
		{
			if ((visit[w] == 0) && (num.col[c][w] == 1) && (visit[c] == 1))
			{
				a = w; 
				var = 1; 
				break;
			}
		}
		if (var == 1)
			break;
	}
	for (int w = 1; w <= num.countnum; w++)
	{
		for (int c = 1; c <= num.countnum; c++)
		{
			if ((visit[w] == 0) && (num.col[c][w] == 1) && (visit[c] == 1))
			{
				if (num.array[a]<num.array[w])
					a = w;
			}
		}
	}
	if (b + num.array[a]<0)
	{
		num.col[v][a] = 0;
	}
	else
		traverse(num, a, visit, b, max, x);
}


int main()
{
	int x, y;
	fstream fs("input.txt");
	fs >> x;
	fs >> y;
	cout << x << " " << y << endl;
	Struct num;
	input(num, x, y);
	int v = 1, b[N] = { 0 }, h = 0;
	for (int i = 1; i <= num.countnum; i++)
	{
		if (num.array[i]<0)
		{
			b[i] = num.array[i];
		}
		else
		{
			int visit[N] = { 0 };
			int max = 0;
			traverse(num, i, visit, b[i], max, x);
		}
	}

	int max = b[1];
	for (int i = 2; i <= num.countnum; i++)
	{
		if (b[i]>max)
			max = b[i];
	}
	cout << "�������������ͨ������ĺ�Ϊ��" << max << endl;
}