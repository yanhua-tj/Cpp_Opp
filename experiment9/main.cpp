#include "CommEntry.h"
#include "Comms.h"
#include <cstdlib>
#define FileName "record.txt"

//using namespace std;

unsigned int displayMenu();             //主菜单的显示
void funChoose(Comms*);                 //菜单选择
Comms* InitComms();                     //通讯录初始化
void FindName(Comms*);                  //查找姓名
void FindTel(Comms* p);                 //查找电话
void Namemodify(Comms*);                //输入姓名修改电话
void Telmodify(Comms*);                 //输入电话修改姓名
void Fuzzysearch(Comms*);               //模糊查找

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
    cout << "4.查找电话" << endl;
    cout << "5.输入姓名修改其电话" << endl;
    cout << "6.输入电话修改其姓名" << endl;
    cout << "7.模糊查找" << endl;
    cout << "8.从文件中读数据" << endl;
    cout << "9.保存数据到文件" << endl;
    cout << "0.保存退出" << endl;
    cout << "=======================" << endl;
    cout << "请输入一个数(0-9)选择：";
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
        while (ichoose > 9)
        {
            cout << "输入的数不在范围内！" << endl;
            system("pause");
            system("cls");
            ichoose = displayMenu();
        }
        cin.ignore(16, '\n');           //清空缓冲区
        switch (ichoose)
        {
        case 0: //功能0,结束程序并保存
        {
            ofstream outfile(FileName);
            p->outputToFile(outfile);
            outfile.close();
            break;
        }
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
        case 4: //功能4,查找电话
            FindTel(p);
            break;
        case 5: //功能5,输入姓名修改其电话
            Namemodify(p);
            break;
        case 6: //功能6,输入电话修改其姓名
            Telmodify(p);
            break;
        case 7: //功能7,模糊查找
            Fuzzysearch(p);
            break;
        case 8: //8.从文件中读数据
        {
            ifstream infile(FileName);
            if (!infile.is_open())
            {
                cout << "文件打开失败! 请检查文件是否存在" << endl;
                break;
            }
            p->inputFromFile(infile);
            infile.close();
            break;
        }
        case 9: //9.保存数据到文件
        {
            ofstream outfile(FileName);
            p->outputToFile(outfile);
            outfile.close();
            break;
        }
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
    index = p->findname(name);
    if (index == -1)
    {
        cout << "查无此人! " << endl;
    }
    else
    {
        cout << "此人在通讯录第" << index + 1 << "个" << endl;
    }
}

//查找电话
void FindTel(Comms* p)
{
    string tel;
    int index = 0;
    cout << "输入要查找姓名: ";
    cin >> tel;
    index = p->findtel(tel);
    if (index == -1)
    {
        cout << "不存在此电话! " << endl;
    }
    else
    {
        cout << "此电话在通讯录第" << index + 1 << "个" << endl;
    }
}

//输入姓名修改电话
void Namemodify(Comms* p)
{
    string name, tel;
    int index = 0;
    cout << "输入要查找姓名: ";
    cin >> name;
    index = p->findname(name);
    if (index == -1)
    {
        cout << "查无此人! " << endl;
    }
    else
    {
        cout << "电话修改为: ";
        cin >> tel;
        p->modifytel(name, tel);
    }
}

//输入电话修改姓名
void Telmodify(Comms* p)
{
    string name, tel;
    int index = 0;
    cout << "输入要查找电话: ";
    cin >> tel;
    index = p->findtel(tel);
    if (index == -1)
    {
        cout << "查无此电话! " << endl;
    }
    else
    {
        cout << "姓名修改为: ";
        cin >> name;
        p->modifyname(tel, name);
    }
}

//模糊查找
void Fuzzysearch(Comms* p)
{
    int choice = 0;
    cout << "0.返回上一级" << endl;
    cout << "1.姓名模糊查找" << endl;
    cout << "2.电话模糊查找" << endl;
    cout << "输入一个数选择功能(0-2): ";
    cin >> choice;
    cin.ignore(16, '\n');
    switch (choice)
    {
    case 0:
        break;
    case 1:
    {
        string name;
        cout << "输入模糊查找姓名关键字: ";
        cin >> name;
        p->fuzzysearchname(name);
        break;
    }
    case 2:
    {
        string tel;
        cout << "输入模糊查找电话关键字: ";
        cin >> tel;
        p->fuzzysearchtel(tel);
        break;
    }
    default:
        cout << "输入有误" << endl;
        break;
    }
}