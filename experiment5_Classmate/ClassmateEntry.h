#pragma once
#include "CommEntry.h"
using namespace std;

class ClassmateEntry : public CommEntry
{
public:
    //输入同学条目信息
    void input();

    //输出同学条目信息
    void output();

    //输出同学条目的属性
    static void outputHead();

    //设置同学学校
    void setSch(string sch);

    //获取同学学校
    string getSch();

    //设置同学班级
    void setCla(string cla);

    //获取同学班级
    string getCla();

private:
    //同学学校
    string m_sch;

    //同学班级
    string m_cla;
};

