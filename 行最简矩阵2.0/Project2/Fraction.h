#pragma once
#pragma once
using namespace std;
class fraction
{
    int above;                      //分子
    int below;                      //分母
public:
    void reduction();               //约分
    void makeCommond(fraction);     //通分
    fraction(int = 0, int = 1);         //构造函数
    fraction add(fraction);         //两分数相加
    fraction sub(fraction);         //两分数相减
    fraction mul(fraction);         //两分数相乘
    fraction div(fraction);         //两分数相除
    fraction reciprocal();          //求倒数
    void Inserter(int, int);    //插入
    bool equal(fraction);           //等于运算
    bool greaterThan(fraction);     //大于运算  
    bool lessThan(fraction);        //小于运算
    void display();                 //显示分数
    void input();                   //输入分数
    int compare(fraction);          //比较大小，小于返回-1，等于返回0，大于返回1   
    double showNumber();    //显示小数形式

    //运算符重载
    fraction operator=(fraction);
    friend fraction operator+(const fraction&, const fraction&);
    friend fraction operator-(const fraction&, const fraction&);
    friend fraction operator*(const fraction&, const fraction&);
    friend fraction operator/(const fraction&, const fraction&);
    friend fraction& operator+=(fraction&, const fraction&);
    friend fraction& operator-=(fraction&, const fraction&);
    friend fraction& operator*=(fraction&, const fraction&);
    friend fraction& operator/=(fraction&, const fraction&);
    friend bool operator==(fraction, fraction);
    friend bool operator!=(fraction, fraction);
    friend fraction operator++(fraction&);              //前置++
    friend fraction operator++(fraction&, int);         //后置++
    friend fraction operator--(fraction&);              //前置--
    friend fraction operator--(fraction&, int);         //后置--
    friend ostream& operator<<(ostream&, fraction&);         //<<
    friend istream& operator>>(istream&, fraction&);         //<<
};
