#include "FriendEntry.h"
#include <cstdlib>

//using namespace std;

unsigned int displayMenu();         //主菜单的显示
void funChoose(FriendEntry&);       //菜单选择
void setFriName(FriendEntry&);      //修改朋友条目的姓名
void setFriTel(FriendEntry&);       //修改朋友条目的电话
void setFriAddr(FriendEntry&);      //修改朋友条目的地址
void setFriEmail(FriendEntry&);     //修改朋友条目的邮箱

int main()
{
    cout << left;                   //左对齐
    FriendEntry frentry;
    funChoose(frentry);             //菜单选择
    return 0;
}

//主菜单的显示
unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "===================" << endl;
    cout << "1.输入朋友条目" << endl;
    cout << "2.输出朋友条目" << endl;
    cout << "3.修改姓名" << endl;
    cout << "4.修改电话" << endl;
    cout << "5.修改地址" << endl;
    cout << "6.修改邮箱" << endl;
    cout << "0.退出" << endl;
    cout << "===================" << endl;
    cout << "请输入一个数(0-6)选择：";
    cin >> i;
    return i;
}

//菜单选择
void funChoose(FriendEntry &a)
{
    string str;
    unsigned int ichoose = 1;
    while (ichoose != 0)
    {
        ichoose = displayMenu();        //调用主菜单函数
        while (ichoose > 6)
        {
            cout << "输入的数不在范围内！" << endl;
            system("pause");
            system("cls");
            ichoose = displayMenu();
        }
        cin.ignore(16, '\n');           //清空缓冲区
        switch (ichoose)
        {
        case 0: //功能0,结束程序
            break;
        case 1: //功能1,输入通讯录
            cout << endl;
            a.CommEntry::input();       //通讯录条目基类
            a.input();
            cout << "朋友条目写入成功!" << endl;
            break;
        case 2: //功能2,输出通讯录
            a.CommEntry::outputHead();
            a.outputHead();                 //输出属性
            cout << endl;
            a.CommEntry::output();
            a.output();                     //输出信息
            cout << endl;
            break;
        case 3: //功能3,修改姓名
            setFriName(a);
            break;
        case 4: //功能4,修改电话
            setFriTel(a);
            break;
        case 5: //功能5,修改地址
            setFriAddr(a);
            break;
        case 6: //功能6,修改邮箱
            setFriEmail(a);
            break;
        }
        system("pause");
        system("cls");
    }
}

//修改朋友条目的姓名
void setFriName(FriendEntry& a)
{
    cout << "修改姓名为: ";
    string temp;
    getline(cin, temp);
    a.setName(temp);
    cout << "修改成功!" << endl;
}

//修改朋友条目的电话
void setFriTel(FriendEntry& a)
{
    cout << "修改电话为: ";
    string temp;
    getline(cin, temp);
    a.setTel(temp);
    cout << "修改成功!" << endl;
}

//修改朋友条目的地址
void setFriAddr(FriendEntry& a)
{
    cout << "修改地址为: ";
    string temp;
    getline(cin, temp);
    a.setAddr(temp);
    cout << "修改成功!" << endl;
}

//修改朋友条目的邮箱
void setFriEmail(FriendEntry& a)
{
    cout << "修改邮箱为: ";
    string temp;
    getline(cin, temp);
    a.setEmail(temp);
    cout << "修改成功!" << endl;
}
