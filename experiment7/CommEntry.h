#pragma once
#include <string>
using namespace std;
class CommEntry
{
public:
    //输入通讯录条目
    void input();

    //输出通讯录条目
    void output();

    //设置条目姓名
    void setName(string name);

    //设置条目电话
    void setTel(string tel);

    //设置条目拥有者
    void setOwner(string owner);

    //获取条目姓名
    string getName();

    //获取条目电话
    string getTel();

    //获取条目拥有者
    string getOwner();

private:
    //通讯录条目姓名
    string m_Name = "";

    //通讯录条目电话
    string m_Tel = "";

    //通讯录条目拥有者
    static string sm_Owner;
};
