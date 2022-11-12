//由于不会带着分数计算，所以本程序计算产生无限小数时结果会很离谱
//虽然是半成品但也勉强能偷懒了
#include <iostream>
using namespace std;
int line, column;
double a[100][100];
int change(int NowLine, int NowColumn)
{
	for (int i = NowLine; i <= line; i++)
	{
		if (a[i][NowColumn] != 0)
		{
			for (int k = NowColumn; k <= column; k++)
			{
				swap(a[NowLine][k], a[i][k]);
				if (k == column)	return 1;
			}
		}
	}
	return 0;
}
void reduce(int NowLine, int NowColumn)
{
	for (int i = 1; i <= line; i++)
	{
		if (i == NowLine) continue;
		double divisor = a[i][NowColumn] / a[NowLine][NowColumn];
		for (int j = 1; j <= column; j++)
		{
			a[i][j] = a[i][j] - a[NowLine][j] * divisor;
		}
	}
}
void make(int ToLine, int NowColumn, int NowLine)
{
	if (a[NowLine][NowColumn] == 0) return;
	double divisor = a[ToLine][NowColumn] / a[NowLine][NowColumn];
	for (int j = NowColumn; j <= column; j++)
	{
		a[ToLine][j] = a[ToLine][j] - a[NowLine][j] * divisor;
	}
}
int main()
{
	printf("请输入矩阵行列数\n");
	cin >> line >> column;
	for (int i = 1; i <= line; i++)
		for (int j = 1; j <= column; j++)
			cin >> a[i][j];
	int NowLine = 1;
	int NowColumn = 1;
	while (NowLine <= line && NowColumn <= column)
	{
		if (a[NowLine][NowColumn] == 0)
		{
			if (change(NowLine, NowColumn) == 0)
			{
				NowColumn++;
			}
		}
		for (int i = NowLine + 1; i <= line; i++)
		{
			if (a[i][NowColumn] != 0) make(i, NowColumn, NowLine);
		}
		NowLine++;
		NowColumn++;
	}
	printf("梯形矩阵为\n");
	for (int i = 1; i <= line; i++)
	{
		for (int j = 1; j <= column; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	for (NowLine = 1; NowLine <= line; NowLine++)
	{
		for (int j = 1; j <= column; j++)
		{
			if (a[NowLine][j] != 0)
			{
				reduce(NowLine, j);
				goto absd;
			}
		}
	absd:;
	}
	printf("行最简矩阵为\n");
	for (int i = 1; i <= line; i++)
	{
		for (int j = 1; j <= column; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}