#pragma once
#include <iostream>
using namespace std;

class Complex
{
    friend ostream& operator<<(ostream&, const Complex&);       //��Ԫ����<<
    friend istream& operator>>(istream&, Complex&);             //��Ԫ����<<
    friend Complex operator+(const Complex&, const Complex&);   //��Ԫ����+
    friend Complex operator*(const Complex&, const Complex&);   //��Ԫ����*
public:
    Complex();                              //��ʼ������, Ĭ��Ϊ0
    Complex(float i, float j);              //��ʼ������
    float geti();                           //��ȡ������ʵ��
    float getj();                           //��ȡ�������鲿
    void seti(float i);                     //���ø�����ʵ��
    void setj(float j);                     //���ø������鲿
    void showComplex();                     //��ӡ����
    Complex operator-(const Complex& p);    //����-��
    Complex operator/(const Complex& p);    //���ظ���/������
    Complex operator/(float num);           //���ظ���/ʵ��

private:
    float m_i;          //������ʵ��
    float m_j;          //�������鲿
};

