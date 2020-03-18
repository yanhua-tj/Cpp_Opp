/*
 * @Author: yanhua
 * @Date: 2020-03-17 18:04:25
 * @Last Modified by: yanhua
 * @Last Modified time: 2020-03-19 00:56:23
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <fstream>
using namespace std;

struct commEntry
{
    unsigned int id;
    string name;
    string tel;
    string addr;
    commEntry *next;
};
struct Addrebook
{
    unsigned int num;
    commEntry *head;
};

unsigned int displayMenu();
void funChoose(Addrebook &AddBook);
void InputCommEntry(Addrebook &AddBook);
void ShowCommEntry(commEntry *&head);
void setName(commEntry &p);
void setTel(commEntry &p);
void setAddr(commEntry &p);
void OuttoFile(commEntry *&head);
void ReadtoFile(Addrebook &AddBook);
void Init(Addrebook &AddBook);

int main()
{
    Addrebook AddBook;
    Init(AddBook);
    ReadtoFile(AddBook);
    funChoose(AddBook);
    OuttoFile(AddBook.head);
    delete AddBook.head;
    return 0;
}

void Init(Addrebook &AddBook)
{
    AddBook.num = 0;
    AddBook.head = new commEntry;
    AddBook.head->next = NULL;
}

void ReadtoFile(Addrebook &AddBook)
{
    ifstream infile;
    char temp;
    infile.open("commEntry.txt");
    if (infile)
        while (infile.peek() != EOF)
        {
            commEntry *p = new commEntry;
            p->next = AddBook.head->next;
            getline(infile, p->name);
            getline(infile, p->tel);
            getline(infile, p->addr);
            AddBook.num++;
            p->id = AddBook.num;
            infile.get(temp);
            AddBook.head->next = p;
        }
    infile.close();
}

void OuttoFile(commEntry *&head)
{
    commEntry *p = head->next;
    ofstream outfile;
    outfile.open("commEntry.txt");
    while (p)
    {
        outfile << p->name << endl;
        outfile << p->tel << endl;
        outfile << p->addr << endl;
        outfile << endl;
        p = p->next;
    }
    outfile.close();
}

unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "===================" << endl;
    cout << "1.输入一条通讯录" << endl;
    cout << "2.输出全部通讯录" << endl;
    cout << "3.修改姓名" << endl;
    cout << "4.修改电话" << endl;
    cout << "5.修改地址" << endl;
    cout << "0.退出" << endl;
    cout << "===================" << endl;
    cout << "请输入一个数(0-5)选择：";
    cin >> i;
    return i;
}
void funChoose(Addrebook &AddBook)
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
            InputCommEntry(AddBook);
            break;
        case 2: //功能2,输出通讯录
            ShowCommEntry(AddBook.head);
            break;
        case 3: //功能3,修改姓名
            //setName(peop);
            break;
        case 4: //功能4,修改电话
            //setTel(peop);
            break;
        case 5: //功能5,修改地址
            //setAddr(peop);
            break;
        }
    }
}
void InputCommEntry(Addrebook &AddBook)
{
    commEntry *comEp = new commEntry;
    comEp->next = AddBook.head->next;
    cout << endl;
    cout << "请输入: " << endl;
    cout << "姓名: ";
    fflush(stdin);
    getline(cin, comEp->name);
    cout << "电话号码: ";
    getline(cin, comEp->tel);
    cout << "地址: ";
    getline(cin, comEp->addr);
    AddBook.head->next = comEp;
    AddBook.num++;
    comEp->id = AddBook.num;
    cout << "一条通讯录导入成功..." << endl;
}
void ShowCommEntry(commEntry *&head)
{
    if (head->next == NULL)
    {
        cout << "通讯录中没有内容..." << endl;
    }
    else
    {
        commEntry *p = head->next;
        cout << setw(6) << left << "编号"
             << setw(14) << left << "姓名"
             << setw(18) << left << "电话"
             << "地址" << endl;
        while (p)
        {
            cout << setfill('0') << setw(4) << right << p->id << "  ";
            cout << setfill(' ');
            cout << setw(14) << left << p->name
                 << setw(18) << left << p->tel
                 << p->addr << endl;
            p = p->next;
        }
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
