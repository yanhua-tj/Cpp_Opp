#pragma once
#include "CommEntry.h"
#include "FriendEntry.h"
class Comms
{
private:
    //通讯录条目最大数
    unsigned m_maxCount;
    //通讯录当前个数
    unsigned m_count;
    //通讯录条目指针数组
    CommEntry **mp_Ces;

public:
    //初始化构造函数
    Comms(unsigned maxCount = 10);
    //析构函数释放内存
    ~Comms();
    //输入通讯录
    void input();
    //输出通讯录
    void outputAll();
    //输入姓名查找下标
    int find(string name);
    //输入姓名修改其电话
    void modify(string name, string tel);
    //显示朋友条目
    void outputFri();
    //显示一般条目
    void outputCom();
};