#include <iostream>
#include <string>
#include <math.h>
#include "Fraction.h"
#include "judgeNumber.h"

fraction judge(string s)
{
	fraction Number;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			Number = isDecimal(s, i);
			return Number;
		}
		if (s[i] == '/')
		{
			Number = isFraction(s, i);
			return Number;
		}
	}
	Number = isNumber(s);
	return Number;
}


fraction isDecimal(string s, int Long)
{
	fraction Number;
	double a = 0;
	double b = 0;
	int cnt = 0;
	if (s[0] == '-')
	{
		for (int i = 1; i < Long; i++)
		{
			a = a * 10;
			a += s[i] - '0';
		}
		for (int i = Long + 1; i < s.size(); i++)
		{
			cnt = cnt + 1;
			b += (s[i] - '0') * pow(0.1, cnt);
		}
		a = a + b;
		Number.Inserter(int(-a * pow(10, cnt)), int(pow(10, cnt)));
		Number.reduction();
		return Number;
	}
	else
	{
		for (int i = 0; i < Long; i++)
		{
			a = a * 10;
			a += s[i] - '0';
		}
		for (int i = Long + 1; i < s.size(); i++)
		{
			cnt = cnt + 1;
			b += (s[i] - '0') * pow(0.1, cnt);
		}
		a = a + b;
		Number.Inserter(int(a * pow(10, cnt)), int(pow(10, cnt)));
		Number.reduction();
	}
	return Number;
}



fraction isFraction(string s, int Long)
{
	fraction Number;
	int a = 0;
	int b = 0;
	if (s[0] == '-')
	{
		for (int i = 1; i < Long; i++)
		{
			a += a * 10 + s[i] - '0';
		}
		for (int i = Long + 1; i < s.size(); i++)
		{
			b += b * 10 + s[i] - '0';
		}
		Number.Inserter(-a, b);
		Number.reciprocal();
		return Number;
	}
	else {
		for (int i = 0; i < Long; i++)
		{
			a += a * 10 + s[i] - '0';
		}
		for (int i = Long + 1; i < s.size(); i++)
		{
			b += b * 10 + s[i] - '0';
		}
		Number.Inserter(a, b);
		Number.reciprocal();
		return Number;
	}
}


fraction isNumber(string s)
{
	fraction Number;
	int a = 0;
	if (s[0] == '-')
	{
		for (int i = 1; i < s.size(); i++)
		{
			a *= 10;
			a += s[i] - '0';
		}
		Number.Inserter(-a, 1);
	}
	else 
	{
		for (int i = 0; i < s.size(); i++)
		{
			a *= 10;
			a += s[i] - '0';
		}
		Number.Inserter(a, 1);
	}
	return Number;
}