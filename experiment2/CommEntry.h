#ifndef COMMENTRY_H_INCLUDED
#define COMMENTRY_H_INCLUDED

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

class CommEntry
{
private:
    string name; //姓名
    string tel;  //电话
    string addr; //地址

public:
    void input();            //输入通讯录条目
    void output();           //输出通讯录条目
    void setName(string nm); //设置条目的名字
    void setTel(string t);   //设置条目的电话
    void setAddr(string ad); //设置条目的地址
    string getName();        //获取姓名
    string getTel();         //获取电话
    string getAddr();        //获取地址
};

#endif // COMMENTRY_H_INCLUDED
