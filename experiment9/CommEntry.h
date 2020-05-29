#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class CommEntry
{
private:
    //姓名
    string m_name;
    //电话
    string m_tel;

public:
    //输入通讯录条目
    void input();
    friend istream& operator>>(istream& in, CommEntry& a);

    //输出通讯录条目
    void output();
    friend ostream& operator<<(ostream& out, const CommEntry& a);

    //输出通讯录条目的属性
    static void outputInfo();

    //设置条目的名字
    void setName(string name);

    //设置条目的电话
    void setTel(string tel);

    //获取姓名
    string getName();

    //获取电话
    string getTel();
};