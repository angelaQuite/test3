//结对开发成员；张晓菲 张哲
//本次实验题目为：求二维数组中的最大连通子数组的和
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
}Struct;//定义结构体变量

void input(Struct &num, int x, int y)
{//input用于实现从文件中读取行和列并输出到屏幕上
	num.countnum = x*y;
	int i = 1;
	int a, b;
	ifstream in = ifstream("input.txt");
	in >> a;
	in >> b;
	num.countnum = a*b;
	while (in >> num.array[i])
	{//将in文件中的数字读取到数组中
		++i;
	}
	in.close();//读取完毕关闭文件in
    for (int i = 1; i <= num.countnum; i++)
	{
        cout << num.array[i] << " ";
		if (i%b == 0)
		{
			cout << endl;
		}
	}//输出文件导入的数组到屏幕
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
{//通过对数组的遍历寻找最大连通子数组
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
	cout << "该数组中最大连通子数组的和为：" << max << endl;
}