#include "CommEntry.h"
#include "FriendEntry.h"
#include "Comms.h"
#include <cstdlib>

//using namespace std;

unsigned int displayMenu();         //主菜单的显示
void funChoose(Comms*);             //菜单选择
Comms* InitComms();                 //通讯录初始化
void FindName(Comms*);              //查找姓名
void Nametotel(Comms*);             //输入姓名修改电话

int main()
{
    cout << left;                   //左对齐
    Comms* p = InitComms();         //初始化
    funChoose(p);                   //菜单选择
    return 0;
}

//通讯录初始化
Comms* InitComms()
{
    Comms* p;
    char a;
    cout << "通讯录默认大小为10, 是否(y/n)自定义个数?" << endl;
    cin.get(a);
    if (a == 'Y' || a == 'y')
    {
        cout << "输入自定义大小: " << endl;
        unsigned num = 0;
        cin >> num;
        p = new Comms(num);
    }
    else
    {
        p = new Comms();
    }
    return p;
}

//主菜单的显示
unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "=======================" << endl;
    cout << "1.输入通讯录" << endl;
    cout << "2.输出通讯录" << endl;
    cout << "3.查找姓名" << endl;
    cout << "4.输入姓名修改其电话" << endl;
    cout << "5.显示一般条目" << endl;
    cout << "6.显示朋友条目" << endl;
    cout << "0.退出" << endl;
    cout << "=======================" << endl;
    cout << "请输入一个数(0-6)选择：";
    cin >> i;
    return i;
}

////菜单选择
void funChoose(Comms* p)
{
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
            p->input();
            cout << "通讯录写入成功!" << endl;
            break;
        case 2: //功能2,输出通讯录
            p->outputAll();                             //输出信息
            break;
        case 3: //功能3,查找姓名
            FindName(p);
            break;
        case 4: //功能4,输入姓名修改其电话
            Nametotel(p);
            break;
        case 5: //显示一般条目
            p->outputCom();
            break;
        case 6: //显示朋友条目
            p->outputFri();
            break;
        }
        system("pause");
        system("cls");
    }
}

//查找姓名
void FindName(Comms* p)
{
    string name;
    int index = 0;
    cout << "输入要查找姓名: ";
    cin >> name;
    index = p->find(name);
    if (index == -1)
    {
        cout << "查无此人! " << endl;
    }
    else
    {
        cout << "此人在通讯录第" << index + 1 << "个" << endl;
    }
}

//输入姓名修改电话
void Nametotel(Comms* p)
{
    string name, tel;
    int index = 0;
    cout << "输入要查找姓名: ";
    cin >> name;
    index = p->find(name);
    if (index == -1)
    {
        cout << "查无此人! " << endl;
    }
    else
    {
        cout << "电话修改为: ";
        cin >> tel;
        p->modify(name, tel);
    }
}
