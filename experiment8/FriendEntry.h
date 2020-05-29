#pragma once
#include "CommEntry.h"
using namespace std;

class FriendEntry : public CommEntry
{
private:
    //朋友地址
    string m_addr;

    //朋友邮箱
    string m_email;

public:
    //输入朋友条目信息
    void input();

    //输出朋友条目信息
    void output();

    //输出朋友条目的属性
    static void outputHead();

    //设置朋友地址
    void setAddr(string addr);

    //获取朋友地址
    string getAddr();

    //设置朋友邮箱
    void setEmail(string email);

    //获取朋友邮箱
    string getEmail();
};

