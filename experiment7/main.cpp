#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "CommEntry.h"
using namespace std;

unsigned menu();                        //主菜单
void menuselect(CommEntry& a);          //菜单功能选择
void setCommName(CommEntry& a);         //修改条目姓名
void setCommTel(CommEntry& a);          //修改条目电话
void setCommOwner(CommEntry& a);        //修改条目拥有者

string CommEntry::sm_Owner = "未指定";

int main()
{
    CommEntry comme;
    menuselect(comme);
    return 0;
}

//主菜单
unsigned menu()
{
    cout << "=============================" << endl;
    cout << "       1.输入通讯录条目" << endl;
    cout << "       2.输出通讯录条目" << endl;
    cout << "          3.修改姓名" << endl;
    cout << "          4.修改电话" << endl;
    cout << "         5.修改拥有者" << endl;
    cout << "            0.退出" << endl;
    cout << "=============================" << endl;
    cout << endl;
    cout << "请输入数(0-5)选择功能: ";
    unsigned i = 999;
    cin >> i;
    return i;
}

//菜单功能选择
void menuselect(CommEntry& a)
{
    unsigned select = 999;
    while (select != 0)
    {
        select = menu();        //调用主菜单
        while (select > 6)
        {
            cout << "输入有误, 请重新输入! " << endl;
            system("pause");
            system("cls");
            select = menu();
        }
        if (select == 0)
        {
            cout << "欢迎下次使用" << endl;
            break;
        }
        cin.ignore(16, '\n');
        switch (select)
        {
        case 1:
            a.input();
            break;
        case 2:
            cout << left;
            cout << setw(12) << "姓名"
                << setw(18) << "电话"
                << setw(12) << "拥有者" << endl;
            a.output();
            break;
        case 3:
            setCommName(a);
            break;
        case 4:
            setCommTel(a);
            break;
        case 5:
            setCommOwner(a);
            break;
        }
        system("pause");
        system("cls");
    }
}

//修改条目姓名
void setCommName(CommEntry& a)
{
    cout << "修改姓名为: " << endl;
    string temp;
    getline(cin, temp);
    a.setName(temp);
}

//修改条目电话
void setCommTel(CommEntry& a)
{
    cout << "修改电话为: " << endl;
    string temp;
    getline(cin, temp);
    a.setTel(temp);
}

//修改条目拥有者
void setCommOwner(CommEntry& a)
{
    cout << "修改拥有者为: " << endl;
    string temp;
    getline(cin, temp);
    a.setOwner(temp);
}
