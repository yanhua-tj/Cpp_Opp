#pragma once
#include "Complex.h"
class Complexcount
{
    //������������
public:
    //���븴��A��B
    void input();

    //���A��B���
    void output();

    //������
    Complex add();

    //������
    Complex sub();

    //������
    Complex mul();

    //������
    Complex div();
private:
    Complex m_a;            //����A
    Complex m_b;            //����B
};

