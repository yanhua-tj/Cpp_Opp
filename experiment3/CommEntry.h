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
    string name;       //姓名
    unsigned telCount; //电话的个数
    string *tels;      //电话
    string *telType;   //电话类型
    string addr;       //地址

public:
    CommEntry(unsigned num = 3);            //构造函数初始化
    ~CommEntry();                           //析构函数释放内存
    void input();                           //输入通讯录条目
    void output();                          //输出通讯录条目
    void setName(string nm);                //设置名字
    void setTel(string t, int iNum);        //设置电话
    void setTelType(string type, int iNum); //设置电话
    void setAddr(string ad);                //设置地址
    string getName();                       //获取姓名
    string getTel(int iNum);                //获取电话
    string getTelType(int iNum);            //获取电话
    string getAddr();                       //获取地址
    bool iNumINtelCo(int iNum);             //判断要修改的是否在范围内
};

#endif // COMMENTRY_H_INCLUDED
