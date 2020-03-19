/*
 * @Author: yanhua
 * @Date: 2020-03-10 21:13:40
 * @Last Modified by: yanhua
 * @Last Modified time: 2020-03-17 18:08:38
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

struct commEntry
{
    string name;
    string tel;
    string addr;
};

unsigned int displayMenu();
void funChoose(commEntry &peop);
void InputCommEntry(commEntry &p);
void ShowCommEntry(commEntry &p);
void setName(commEntry &p);
void setTel(commEntry &p);
void setAddr(commEntry &p);

int main()
{
    commEntry peop;
    peop.addr = "";
    peop.name = "";
    peop.tel = "";
    funChoose(peop);
    return 0;
}

unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "===================" << endl;
    cout << "1.输入通讯录条目" << endl;
    cout << "2.输出通讯录条目" << endl;
    cout << "3.修改姓名" << endl;
    cout << "4.修改电话" << endl;
    cout << "5.修改地址" << endl;
    cout << "0.退出" << endl;
    cout << "===================" << endl;
    cout << "请输入一个数(0-5)选择：";
    cin >> i;
    return i;
}
void funChoose(commEntry &peop)
{
    unsigned int ichoose = 1;
    while (ichoose != 0)
    {
        ichoose = displayMenu();
        while (ichoose > 5)
        {
            cout << "输入的数不在范围内！" << endl;
            ichoose = displayMenu();
        }
        switch (ichoose)
        {
        case 0: //功能0,结束程序
            break;
        case 1: //功能1,输入通讯录
            InputCommEntry(peop);
            break;
        case 2: //功能2,输出通讯录
            ShowCommEntry(peop);
            break;
        case 3: //功能3,修改姓名
            setName(peop);
            break;
        case 4: //功能4,修改电话
            setTel(peop);
            break;
        case 5: //功能5,修改地址
            setAddr(peop);
            break;
        }
    }
}
void InputCommEntry(commEntry &p)
{
    cout << endl;
    cout << "请输入: " << endl;
    cout << "姓名: ";
    fflush(stdin);
    getline(cin, p.name);
    cout << "电话号码: ";
    getline(cin, p.tel);
    cout << "地址: ";
    getline(cin, p.addr);
}
void ShowCommEntry(commEntry &p)
{
    if (p.name == "" || p.tel == "" || p.addr == "")
    {
        cout << "没有通讯录条目" << endl;
    }
    else
    {
        cout << setw(10) << left << "姓名"
             << setw(14) << left << "电话"
             << "地址" << endl;
        cout << setw(10) << left << p.name
             << setw(14) << left << p.tel
             << p.addr << endl;
    }
}
void setName(commEntry &p)
{
    if (p.name == "")
    {
        cout << "没有通讯录条目" << endl;
    }
    else
    {
        cout << endl;
        cout << "将名字修改为: ";
        fflush(stdin);
        cin >> p.name;
        cout << "名字修改成功" << endl;
    }
}
void setTel(commEntry &p)
{
    if (p.tel == "")
    {
        cout << "没有通讯录条目" << endl;
    }
    else
    {
        cout << endl;
        cout << "将电话修改为: ";
        fflush(stdin);
        cin >> p.tel;
        cout << "电话修改成功" << endl;
    }
}
void setAddr(commEntry &p)
{
    if (p.addr == "")
    {
        cout << "没有通讯录条目" << endl;
    }
    else
    {
        cout << endl;
        cout << "将地址修改为: ";
        fflush(stdin);
        cin >> p.addr;
        cout << "地址修改成功" << endl;
    }
}
