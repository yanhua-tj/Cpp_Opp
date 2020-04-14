#include "CommEntry.h"
using namespace std;

//获取姓名
string CommEntry::getName()
{
    return m_name;
}

//获取电话
string CommEntry::getTel()
{
    return m_tel;
}

//设置条目的名字
void CommEntry::setName(string name)
{
    m_name = name;
}

//设置条目的电话
void CommEntry::setTel(string tel)
{
    m_tel = tel;
}

//输入通讯录条目
void CommEntry::input()
{
    string temp;

    cout << "输入姓名: ";
    getline(cin, temp);
    setName(temp);

    cout << "输入电话: ";
    getline(cin, temp);
    setTel(temp);
}

//输出通讯录条目
void CommEntry::output()
{
    cout << setw(14) << getName()
        << setw(18) << getTel();
}

//输出通讯录条目的属性
void CommEntry::outputHead()
{
    cout << setw(14) << "姓名"
        << setw(18) << "电话";
}