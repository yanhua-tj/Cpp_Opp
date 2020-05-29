#pragma once
#include <iostream>
using namespace std;

class Complex
{
    friend ostream& operator<<(ostream&, const Complex&);       //友元重载<<
    friend istream& operator>>(istream&, Complex&);             //友元重载<<
    friend Complex operator+(const Complex&, const Complex&);   //友元重载+
    friend Complex operator*(const Complex&, const Complex&);   //友元重载*
public:
    Complex();                              //初始化复数, 默认为0
    Complex(float i, float j);              //初始化复数
    float geti();                           //获取复数的实部
    float getj();                           //获取复数的虚部
    void seti(float i);                     //设置复数的实部
    void setj(float j);                     //设置复数的虚部
    void showComplex();                     //打印复数
    Complex operator-(const Complex& p);    //重载-号
    Complex operator/(const Complex& p);    //重载复数/复数号
    Complex operator/(float num);           //重载复数/实数

private:
    float m_i;          //复数的实部
    float m_j;          //复数的虚部
};

