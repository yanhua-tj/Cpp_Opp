#pragma once
#include <string>
#include "CommEntry.h"
using namespace std;

//通讯录类
class Comms
{
public:
    //通讯录初始化通讯录条目个数
    Comms(int num);

    //析构释放通讯录条目内存
    ~Comms();

    //输入一些通讯录条目
    void inputSome();

    //输出一些通讯录条目
    void outputAll();

    //输入姓名查找通讯录,返回下标
    int findComName(string name);

    //输入姓名,修改电话
    void modifyTel(string name, string tel);

    //输入电话,返回通讯录条目下标
    int findComTel(string tel);

    //输入电话,修改姓名
    void modifyName(string tel, string name);

    //输入姓名进行模糊查找
    void fuzzySearch(string name);

private:
    //通讯录条目指针
    CommEntry *m_pCe;

    //通讯录最大个数
    int m_Maxnum;

    //通讯录当前个数
    int m_count;
};

