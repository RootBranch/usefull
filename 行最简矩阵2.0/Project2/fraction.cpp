#include <iostream>
#include "Fraction.h"
using namespace std;

void fraction::reduction()               //Լ��
{
    int i, j;
    if (this->above == 0)
    {
        this->below = 1;
        return;
    }
    if (this->above == 0 && this->below == 0)
    {
        this->above = abs(this->above);
        this->below = abs(this->below);
    }
    else if (this->above < 0 && this->below < 0)
    {
        this->below = -this->below;
        this->above = -this->above;
    }
    else if (this->above * this->below < 0)
    {
        this->below = abs(this->below);
        this->above = -abs(this->above);
    }
    i = abs(this->above) > abs(this->below) ? abs(this->below) : abs(this->above);
    for (; i >= 1; i--)
    {
        if (abs(this->above) % i == 0 && abs(this->below) % i == 0)
        {
            this->above /= i;
            this->below /= i;
            return;
        }
    }
}



void fraction::makeCommond(fraction f)     //ͨ��
{
    this->below = this->below * f.below;
    this->above = this->above * f.below;
}



fraction::fraction(int i, int j)         //���캯��
{
    this->above = i;
    this->below = j;
}


fraction fraction::add(fraction f)         //���������
{
    fraction f1(this->above, this->below);
    fraction tempf(f.above, f.below);
    f.makeCommond(f1);
    f1.makeCommond(tempf);
    f1.above += f.above;
    f1.reduction();
    return f1;
}


fraction fraction::sub(fraction f)         //���������
{
    fraction f1(this->above, this->below);
    fraction tempf(f.above, f.below);
    f.makeCommond(f1);
    f1.makeCommond(tempf);
    f1.above -= f.above;
    f1.reduction();
    return f1;
}


fraction fraction::mul(fraction f)         //���������
{
    fraction f1(this->above, this->below);
    f1.above = this->above * f.above;
    f1.below = this->below * f.below;
    return f1;
}



fraction fraction::div(fraction f)         //���������
{
    if (f.above == 0)
    {
        std::cout << "ERROR" << std::endl;
        return f;
    }
    fraction tempf;
    tempf.above = this->above * f.below;
    tempf.below = this->below * f.above;
    tempf.reduction();
    return tempf;
}


fraction fraction::reciprocal()          //����
{
    fraction f;
    if (this->above == 0)
    {
        std::cout << "ERROR" << std::endl;
        return f;
    }
    f.above = this->below;
    f.below = this->above;
    return f;
}


void fraction::Inserter(int a, int b)
{
    this->above = a;
    this->below = b;
}



bool fraction::equal(fraction f)           //��������
{
    if (f.above == this->above && f.below == this->below)
        return true;
    else
        return false;
}


bool fraction::greaterThan(fraction f)     //��������  
{
    fraction temps(f.above, f.below);
    fraction f1(this->above, this->below);
    f.makeCommond(f1);
    f1.makeCommond(temps);
    if (f1.above > f.above)
        return true;
    else return false;
}


bool fraction::lessThan(fraction f)        //С������
{
    fraction f1(this->above, this->below);
    fraction tempf(f.above, f.below);
    f.makeCommond(f1);
    f1.makeCommond(tempf);
    if (f1.above < f.above)
        return true;
    else return false;
}

void fraction::display()                 //��ʾ����
{
    reduction();
    if (above == 0)
        std::cout << "0" << std::endl;
    else
        std::cout << this->above << "/" << this->below << std::endl;
}



void fraction::input()                   //�������
{
    std::cout << "����������ķ��Ӻͷ�ĸ" << std::endl;
    std::cin >> this->above >> this->below;
}



int fraction::compare(fraction f)          //�Ƚϴ�С��С�ڷ���-1�����ڷ���0�����ڷ���1   
{
    if (equal(f))
        return 0;
    else if (greaterThan(f))
        return 1;
    else
        return -1;
}


bool operator==(fraction a, fraction b)
{
    if (a.equal(b))
        return 1;
    else return 0;
}


bool operator!=(fraction a, fraction b)
{
    if (a.equal(b))
        return 0;
    else return 1;
}

fraction fraction::operator=(fraction f)
{
    fraction tempf(f.above, f.below);
    this->above = tempf.above;
    this->below = tempf.below;
    return tempf;
}


fraction operator+(const fraction& a, const fraction& b)
{
    fraction tempf(a.above, a.below);
    return tempf.add(b);
}



fraction operator-(const fraction& a, const fraction& b)
{
    fraction tempf(a.above, a.below);
    return tempf.sub(b);
}



fraction operator*(const fraction& a, const fraction& b)
{
    fraction tempf(a.above, a.below);
    return tempf.mul(b);
}


fraction operator/(const fraction& a, const fraction& b)
{
    fraction tempf(a.above, a.below);
    return tempf.div(b);
}



fraction& operator+=(fraction& a, const fraction& b)
{
    fraction tempf;
    tempf = a + b;
    a = tempf;
    return a;
}



fraction& operator-=(fraction& a, const fraction& b)
{
    fraction tempf;
    tempf = a - b;
    a = tempf;
    return a;
}


fraction& operator*=(fraction& a, const fraction& b)
{
    fraction tempf;
    tempf = a * b;
    a = tempf;
    return a;
}


fraction& operator/=(fraction& a, const fraction& b)
{
    fraction tempf;
    tempf = a / b;
    a = tempf;
    return a;
}



fraction operator++(fraction& f)              //ǰ��++
{
    fraction tempf(f.above, f.below);
    tempf += 1;
    f = tempf;
    return f;
}


fraction operator++(fraction& f, int)         //����++
{
    fraction tempf(f.above, f.below);
    f += 1;
    return tempf;
}

fraction operator--(fraction& f)              //ǰ��--
{
    fraction tempf(f.above, f.below);
    f -= 1;
    tempf = f;
    return tempf;
}



fraction operator--(fraction& f, int)         //����--
{
    fraction tempf(f.above, f.below);
    f -= 1;
    return tempf;
}

ostream& operator<<(ostream& out, fraction& f)         //<<
{
    if (f.above == 0)
        out << 0;
    else if (f.below == 1)
        cout << f.above;
    else if (f.below!=1)
        out << f.above << "/" << f.below;
    
    return out;
}



istream& operator>>(istream& in, fraction& f)         //<<
{
    scanf_s("%d/%d", &f.above, &f.below);
    return in;
}



double fraction::showNumber()    //��ʾС����ʽ
{
    double a = double(this->above) / double(this->below);
    return a;
}