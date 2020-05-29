#include "Complex.h"
#include <iostream>
using namespace std;

//初始化复数, 默认0
Complex::Complex() : m_i(0), m_j(0)
{
}

//初始化复数
Complex::Complex(float i, float j) : m_i(i), m_j(j)
{
}

//获取复数的实部
float Complex::geti()
{
    return m_i;
}

//获取复数的虚部
float Complex::getj()
{
    return m_j;
}

//设置复数的实部
void Complex::seti(float i)
{
    m_i = i;
}

//设置复数的虚部
void Complex::setj(float j)
{
    m_j = j;
}

//打印复数
void Complex::showComplex()
{
    cout << noshowpos << m_i
        << showpos << m_j << "i" << endl;
}

//重载＋号
Complex operator+(const Complex& a, const Complex& b)
{
    Complex temp(a.m_i + b.m_i, a.m_j + b.m_j);
    return temp;
}

//重载-号
Complex Complex::operator-(const Complex& p)
{
    float i = this->m_i - p.m_i;
    float j = this->m_j - p.m_j;
    Complex temp(i, j);
    return temp;
}

//重载*号
Complex operator*(const Complex& a, const Complex& b)
{
    float i = (a.m_i * b.m_i) - (a.m_j * b.m_j);
    float j = (a.m_i * b.m_j) + (a.m_j * b.m_i);
    Complex temp(i, j);
    return temp;
}

//重载复数/复数
Complex Complex::operator/(const Complex& p)
{
    Complex conju(p.m_i, -p.m_j);			    //共轭复数
    Complex numerator = (*this) * conju;		//分母*共轭复数
    float denominator = p.m_i * p.m_i + p.m_j * p.m_j;
    Complex temp = numerator / denominator;
    return temp;
}

//重载复数/实数
Complex Complex::operator/(float num)
{
    float i = this->m_i / num;
    float j = this->m_j / num;
    Complex temp(i, j);
    return temp;
}

//重载<<输出复数
ostream& operator<<(ostream& out, const Complex& a)
{
    out << noshowpos << a.m_i
        << showpos << a.m_j << "i";
    return out;
}

//重载>>输入复数
istream& operator>>(istream& in, Complex& a)
{
    cout << "输入复数实部: ";
    cin >> a.m_i;

    cout << "输入复数虚部: ";
    cin >> a.m_j;
    return in;
}
