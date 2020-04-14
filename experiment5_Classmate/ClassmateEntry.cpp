#include "ClassmateEntry.h"
using namespace std;
//输入同学条目信息
void ClassmateEntry::input()
{
    string temp;
    cout << "输入学校: ";
    getline(cin, temp);
    setSch(temp);

    cout << "输入班级: ";
    getline(cin, temp);
    setCla(temp);
}

//输出同学条目信息
void ClassmateEntry::output()
{
    cout << setw(20) << getSch()
        << setw(16) << getCla();
}

//输出同学条目的属性
void ClassmateEntry::outputHead()
{
    cout << setw(20) << "学校"
        << setw(16) << "班级";
}

//设置同学学校
void ClassmateEntry::setSch(string sch)
{
    m_sch = sch;
}

//获取同学学校
string ClassmateEntry::getSch()
{
    return m_sch;
}

//设置同学班级
void ClassmateEntry::setCla(string cla)
{
    m_cla = cla;
}

//获取同学班级
string ClassmateEntry::getCla()
{
    return m_cla;
}