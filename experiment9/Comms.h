#pragma once
#include "CommEntry.h"
#include <fstream>
class Comms
{
private:
    //通讯录条目最大数
    unsigned m_maxCount;
    //通讯录当前个数
    unsigned m_count;
    //通讯录条目指针数组
    CommEntry *mp_Ce;

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
    int findname(string name);
    //输入电话查找下标
    int findtel(string tel);
    //输入姓名修改其电话
    void modifytel(string name, string tel);
    //输入电话修改其姓名
    void modifyname(string tel, string name);
    //输入电话模糊查找
    void fuzzysearchtel(string tel);
    //输入姓名模糊查找
    void fuzzysearchname(string name);
    //从文件中读数据
    void inputFromFile(ifstream& in);
    //保存数据到文件中
    void outputToFile(ofstream& out);
};