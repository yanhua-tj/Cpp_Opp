#include "CommEntry.h"
#include <iostream>
#include <iomanip>
using namespace std;

//输入通讯录条目
void CommEntry::input()
{
    string temp;
    cout << "输入姓名: " << endl;
    getline(cin, temp);
    setName(temp);

    cout << "输入电话: " << endl;
    getline(cin, temp);
    setTel(temp);

    cout << "一条通讯录写入成功! " << endl;
}

//输出通讯录条目
void CommEntry::output()
{
    cout << setw(12) << m_Name
        << setw(18) << m_Tel
        << setw(12) << sm_Owner << endl;
}

//设置条目姓名
void CommEntry::setName(string name)
{
    m_Name = name;
}

//设置条目电话
void CommEntry::setTel(string tel)
{
    m_Tel = tel;
}

//设置条目拥有者
void CommEntry::setOwner(string owner)
{
    sm_Owner = owner;
}

//获取条目姓名
string CommEntry::getName()
{
    return m_Name;
}

//获取条目电话
string CommEntry::getTel()
{
    return m_Tel;
}

//获取条目拥有者
string CommEntry::getOwner()
{
    return sm_Owner;
}