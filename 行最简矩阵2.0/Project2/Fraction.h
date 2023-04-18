#pragma once
#pragma once
using namespace std;
class fraction
{
    int above;                      //����
    int below;                      //��ĸ
public:
    void reduction();               //Լ��
    void makeCommond(fraction);     //ͨ��
    fraction(int = 0, int = 1);         //���캯��
    fraction add(fraction);         //���������
    fraction sub(fraction);         //���������
    fraction mul(fraction);         //���������
    fraction div(fraction);         //���������
    fraction reciprocal();          //����
    void Inserter(int, int);    //����
    bool equal(fraction);           //��������
    bool greaterThan(fraction);     //��������  
    bool lessThan(fraction);        //С������
    void display();                 //��ʾ����
    void input();                   //�������
    int compare(fraction);          //�Ƚϴ�С��С�ڷ���-1�����ڷ���0�����ڷ���1   
    double showNumber();    //��ʾС����ʽ

    //���������
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
    friend fraction operator++(fraction&);              //ǰ��++
    friend fraction operator++(fraction&, int);         //����++
    friend fraction operator--(fraction&);              //ǰ��--
    friend fraction operator--(fraction&, int);         //����--
    friend ostream& operator<<(ostream&, fraction&);         //<<
    friend istream& operator>>(istream&, fraction&);         //<<
};
