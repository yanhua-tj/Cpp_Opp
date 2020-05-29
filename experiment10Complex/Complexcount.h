#pragma once
#include "Complex.h"
class Complexcount
{
    //复数计算器类
public:
    //输入复数A和B
    void input();

    //输出A和B结果
    void output();

    //复数加
    Complex add();

    //复数减
    Complex sub();

    //复数乘
    Complex mul();

    //复数除
    Complex div();
private:
    Complex m_a;            //复数A
    Complex m_b;            //复数B
};

