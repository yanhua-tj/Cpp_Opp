#include "Complex.h"
#include <iostream>
using namespace std;

//��ʼ������, Ĭ��0
Complex::Complex() : m_i(0), m_j(0)
{
}

//��ʼ������
Complex::Complex(float i, float j) : m_i(i), m_j(j)
{
}

//��ȡ������ʵ��
float Complex::geti()
{
    return m_i;
}

//��ȡ�������鲿
float Complex::getj()
{
    return m_j;
}

//���ø�����ʵ��
void Complex::seti(float i)
{
    m_i = i;
}

//���ø������鲿
void Complex::setj(float j)
{
    m_j = j;
}

//��ӡ����
void Complex::showComplex()
{
    cout << noshowpos << m_i
        << showpos << m_j << "i" << endl;
}

//���أ���
Complex operator+(const Complex& a, const Complex& b)
{
    Complex temp(a.m_i + b.m_i, a.m_j + b.m_j);
    return temp;
}

//����-��
Complex Complex::operator-(const Complex& p)
{
    float i = this->m_i - p.m_i;
    float j = this->m_j - p.m_j;
    Complex temp(i, j);
    return temp;
}

//����*��
Complex operator*(const Complex& a, const Complex& b)
{
    float i = (a.m_i * b.m_i) - (a.m_j * b.m_j);
    float j = (a.m_i * b.m_j) + (a.m_j * b.m_i);
    Complex temp(i, j);
    return temp;
}

//���ظ���/����
Complex Complex::operator/(const Complex& p)
{
    Complex conju(p.m_i, -p.m_j);			    //�����
    Complex numerator = (*this) * conju;		//��ĸ*�����
    float denominator = p.m_i * p.m_i + p.m_j * p.m_j;
    Complex temp = numerator / denominator;
    return temp;
}

//���ظ���/ʵ��
Complex Complex::operator/(float num)
{
    float i = this->m_i / num;
    float j = this->m_j / num;
    Complex temp(i, j);
    return temp;
}

//����<<�������
ostream& operator<<(ostream& out, const Complex& a)
{
    out << noshowpos << a.m_i
        << showpos << a.m_j << "i";
    return out;
}

//����>>���븴��
istream& operator>>(istream& in, Complex& a)
{
    cout << "���븴��ʵ��: ";
    cin >> a.m_i;

    cout << "���븴���鲿: ";
    cin >> a.m_j;
    return in;
}
