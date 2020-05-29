#include "CommEntry.h"
#include <typeinfo>
#include <fstream>
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

//重载>>输入通讯录条目
istream& operator>>(istream& in, CommEntry& a)
{
    if (typeid(in) == typeid(istream))
    {
        cout << "输入姓名: ";
        getline(in, a.m_name);

        cout << "输入电话: ";
        getline(in, a.m_tel);
    }
    else if (typeid(in) == typeid(ifstream))
    {
        char temp[32];
        in.getline(temp, 32);
        a.m_name = temp;
        in.getline(temp, 32);
        a.m_tel = temp;
    }
    return in;
}

//输出通讯录条目
void CommEntry::output()
{
    cout << setw(14) << getName()
        << setw(18) << getTel()
        << endl;
}

//重载<<输出通讯录条目
ostream& operator<<(ostream& out, const CommEntry& a)
{
    if (typeid(out) == typeid(ostream))
    {
        out << setw(14) << a.m_name
            << setw(18) << a.m_tel << endl;
    }
    else if (typeid(out) == typeid(ofstream))
    {
        out << a.m_name << endl;
        out << a.m_tel << endl;
    }
    return out;
}

//输出通讯录条目的属性
void CommEntry::outputInfo()
{
    cout << setw(14) << "姓名"
        << setw(18) << "电话";
}