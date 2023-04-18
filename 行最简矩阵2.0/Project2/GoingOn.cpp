#include <iostream>
#include <math.h>
#include "Fraction.h"
#include "judgeNumber.h"
#include <stdlib.h>
using namespace std;
int line, column;
fraction a[10005][10055];

void Print();
int change(int , int );
void reduce(int , int );
void make(int , int , int );
int main()
{
	printf("请输入矩阵行列数\n");
	string s;
	cin >> line >> column;
	for (int i = 1; i <= line; i++)
		for (int j = 1; j <= column; j++)
		{
			cin >> s;
			a[i][j] = judge(s);
		}
	cout << endl << endl;
	Print();
	int NowLine = 1;
	int NowColumn = 1;
	while (NowLine <= line && NowColumn <= column)
	{
		if (a[NowLine][NowColumn].showNumber() == 0)
		{
			if (change(NowLine, NowColumn) == 0)
			{
				NowColumn++;
			}
			else
			{

				Print();
				cout << endl << endl;
			}
		}
		for (int i = NowLine + 1; i <= line; i++)
		{
			if (a[i][NowColumn].showNumber() != 0)
				make(i, NowColumn, NowLine);
		}
		NowLine++;
		NowColumn++;
	}
	cout << endl << endl << endl;
	printf("梯形矩阵为\n");
	Print();
	for (NowLine = 1; NowLine <= line; NowLine++)
	{
		for (int j = 1; j <= column; j++)
		{
			if (a[NowLine][j].showNumber() != 0)
			{
				reduce(NowLine, j);
				goto absd;
			}
		}
	absd:;
	}
	cout << endl << endl;
	printf("行最简矩阵为\n");
	Print();
	system("pause");
	return 0;
}



void Print()
{
	for (int i = 1; i <= line; i++)
	{
		for (int j = 1; j <= column; j++)
			cout << a[i][j] << "    ";
		cout << endl;
	}
	cout << "---------------------------------------" << endl;
}




int change(int NowLine, int NowColumn)
{
	for (int i = NowLine; i <= line; i++)
	{
		if (a[i][NowColumn].showNumber() != 0)
		{
			for (int k = NowColumn; k <= column; k++)
			{
				printf("交换 C%d C%d ", i, NowColumn);
				cout << endl;
				swap(a[NowLine][k], a[i][k]);
				if (k == column) return 1;
			}
			cout << endl << endl;
		}
	}
	return 0;
}



void reduce(int NowLine, int NowColumn)
{
	for (int i = 1; i <= line; i++)
	{
		if (i == NowLine) continue;
		fraction divisor = a[i][NowColumn] / a[NowLine][NowColumn];
		if (divisor.showNumber() == 0)
			continue;
		for (int j = 1; j <= column; j++)
		{
			a[i][j] = a[i][j] - a[NowLine][j] * divisor;
		}
		cout << "C" << i << " - " << divisor << " * C" << NowLine<<endl;
		cout << endl;
		Print();
		cout << endl << endl;
	}
}




void make(int ToLine, int NowColumn, int NowLine)
{
	if (a[NowLine][NowColumn].showNumber() == 0) return;
	fraction divisor = a[ToLine][NowColumn] / a[NowLine][NowColumn];
	for (int j = NowColumn; j <= column; j++)
	{
		a[ToLine][j] = a[ToLine][j] - a[NowLine][j] * divisor;
	}
	cout << "C" << ToLine << " - " << divisor << " * C" << NowLine<<endl ;
	Print();
	cout << endl;
	cout << endl << endl;
}