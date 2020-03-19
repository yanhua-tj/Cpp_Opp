/*
 * @Author: yanhua 
 * @Date: 2020-03-17 20:30:53 
 * @Last Modified by: yanhua
 * @Last Modified time: 2020-03-19 20:42:23
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

unsigned int displayMenu();                              //主菜单显示
void funChoose(Addrebook &AddBook);                      //主菜单功能选择
commEntry *InputCommEntry();                             //输入一条通讯录
void ShowCommEntry(commEntry *&head);                    //显示所有的通讯录
void setCommEntry(commEntry *&head);                     //设置修改通讯录的名字,电话,地址
commEntry *Foundid(commEntry *&head, unsigned sel);      //在通讯录链表中查找符合编号的条目,返回当前
commEntry *FoundidBefor(commEntry *&head, unsigned sel); //在通讯录链表中查找符合编号的条目,返回前驱
void setName(commEntry *p);                              //修改通讯录条目的姓名
void setTel(commEntry *p);                               //修改通讯录条目的电话
void setAddr(commEntry *p);                              //修改通讯录条目的地址
void OuttoFile(commEntry *&head);                        //把内存中的通讯录写到文件中
void ReadtoFile(Addrebook &AddBook);                     //从文件中读取通讯录到内存
void Init(Addrebook &AddBook);                           //初始化通讯录结构
void DeleteSpace(commEntry *&head);                      //释放new生成的链表空间
void ShowOneCom(commEntry *p);                           //显示一条通讯录条目
void InsertCom(Addrebook &AddBook);                      //插入一条通讯录
void DeleteCom(Addrebook &AddBook);                      //删除一条通讯录
void NameToTEL(commEntry *head);                         //输入姓名查找电话

int main()
{
    Addrebook AddBook;
    Init(AddBook);
    ReadtoFile(AddBook);
    funChoose(AddBook);
    OuttoFile(AddBook.head);
    DeleteSpace(AddBook.head);
    return 0;
}

void DeleteSpace(commEntry *&head)
{ //释放new生成的链表空间
    commEntry *p = head, *q;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
}

void Init(Addrebook &AddBook)
{ //初始化通讯录结构
    AddBook.num = 0;
    AddBook.head = new commEntry;
    AddBook.head->next = NULL;
}

void ReadtoFile(Addrebook &AddBook)
{ //从文件中读取通讯录到内存
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
{ //把内存中的通讯录写到文件中
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
{ //主菜单显示
    unsigned int i;
    cout << endl;
    cout << "=========================" << endl;
    cout << "1.输入一条通讯录" << endl;
    cout << "2.输出全部通讯录" << endl;
    cout << "3.修改一条通讯录" << endl;
    cout << "4.插入一条通讯录" << endl;
    cout << "5.删除一条通讯录" << endl;
    cout << "6.输入姓名查找电话" << endl;
    cout << "0.退出并保存" << endl;
    cout << "=========================" << endl;
    cout << "请输入一个数(0-6)选择：";
    cin >> i;
    return i;
}

void funChoose(Addrebook &AddBook)
{ //主菜单功能选择
    unsigned int ichoose = 1;
    commEntry *p;
    while (ichoose != 0)
    {
        ichoose = displayMenu();
        while (ichoose > 6)
        {
            cout << "输入的数不在范围内！重新输入" << endl;
            ichoose = displayMenu();
        }
        switch (ichoose)
        {
        case 0: //功能0,结束程序
            break;
        case 1: //功能1,输入通讯录
            p = InputCommEntry();
            p->next = AddBook.head->next;
            AddBook.head->next = p;
            AddBook.num++;
            p->id = AddBook.num;
            break;
        case 2: //功能2,输出通讯录
            ShowCommEntry(AddBook.head);
            break;
        case 3: //功能3,修改一条通讯录
            setCommEntry(AddBook.head);
            break;
        case 4: //功能4,插入一条通讯录
            InsertCom(AddBook);
            break;
        case 5: //功能5,删除一条通讯录
            DeleteCom(AddBook);
            break;
        case 6: //功能6,输入姓名查找电话
            NameToTEL(AddBook.head);
            break;
        }
    }
}

commEntry *InputCommEntry()
{ //输入一条通讯录
    commEntry *comEp = new commEntry;
    cout << endl;
    cout << "请输入: " << endl;
    cout << "姓名: ";
    fflush(stdin);
    getline(cin, comEp->name);
    cout << "电话号码: ";
    getline(cin, comEp->tel);
    cout << "地址: ";
    getline(cin, comEp->addr);
    cout << "一条通讯录导入成功..." << endl;
    return comEp;
}

void ShowCommEntry(commEntry *&head)
{ //显示所有的通讯录
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

void setCommEntry(commEntry *&head)
{ //设置修改通讯录的名字,电话,地址
    unsigned sel, ichoose = 1;
    commEntry *p;
    cout << endl;
    cout << "1.修改名字" << endl;
    cout << "2.修改电话" << endl;
    cout << "3.修改地址" << endl;
    cout << "0.返回上一级" << endl;
    cout << "请选择功能(0-3): " << endl;
    cin >> ichoose;
    while (ichoose > 3)
    {
        cout << "输入的数不在范围内！重新输入" << endl;
        cin >> ichoose;
    }
    if (ichoose != 0)
    {
        cout << "输入要修改的通讯录编号" << endl;
        cin >> sel;
        p = Foundid(head, sel);
        if (p != NULL)
        {
            switch (ichoose)
            {
            case 1:
                setName(p);
                break;
            case 2:
                setTel(p);
                break;
            case 3:
                setAddr(p);
                break;
            }
        }
        else
            cout << "没有这个编号的通讯录" << endl;
    }
}

commEntry *Foundid(commEntry *&head, unsigned sel)
{ //在通讯录链表中查找符合编号的条目,返回当前
    commEntry *p = head->next;
    while (p)
    {
        if (p->id == sel)
            break;
        p = p->next;
    }
    return p;
}

commEntry *FoundidBefor(commEntry *&head, unsigned sel)
{ //在通讯录链表中查找符合编号的条目,返回前驱
    commEntry *p = head;
    while (p->next)
    {
        if (p->next->id == sel)
            break;
        p = p->next;
    }
    return p;
}

void ShowOneCom(commEntry *p)
{ //显示一条通讯录条目
    cout << endl;
    cout << setw(6) << left << "编号"
         << setw(14) << left << "姓名"
         << setw(18) << left << "电话"
         << "地址" << endl;
    cout << setfill('0') << setw(4) << right << p->id << "  ";
    cout << setfill(' ');
    cout << setw(14) << left << p->name
         << setw(18) << left << p->tel
         << p->addr << endl;
}

void setName(commEntry *p)
{ //修改通讯录条目的姓名
    ShowOneCom(p);
    cout << endl;
    cout << "将名字修改为: ";
    fflush(stdin);
    cin >> p->name;
    cout << "名字修改成功" << endl;
    ShowOneCom(p);
}
void setTel(commEntry *p)
{ //修改通讯录条目的电话
    ShowOneCom(p);
    cout << endl;
    cout << "将电话修改为: ";
    fflush(stdin);
    cin >> p->tel;
    cout << "电话修改成功" << endl;
    ShowOneCom(p);
}
void setAddr(commEntry *p)
{ //修改通讯录条目的地址
    ShowOneCom(p);
    cout << endl;
    cout << "将地址修改为: ";
    fflush(stdin);
    cin >> p->addr;
    cout << "地址修改成功" << endl;
    ShowOneCom(p);
}

void InsertCom(Addrebook &AddBook)
{ //插入一条通讯录
    unsigned sel;
    commEntry *p, *q;
    cout << endl;
    cout << "插入通讯录到指定编号后" << endl;
    cout << "请输入插入的编号" << endl;
    cin >> sel;
    p = Foundid(AddBook.head, sel);
    if (p == NULL)
    {
        cout << "要插入的编号不存在" << endl;
    }
    else
    {
        q = InputCommEntry();
        q->next = p->next;
        p->next = q;
        AddBook.num++;
        q->id = AddBook.num;
    }
}
void DeleteCom(Addrebook &AddBook)
{ //删除一条通讯录
    commEntry *p, *q;
    unsigned sel;
    cout << endl;
    cout << "请输入要删除的通讯录编号" << endl;
    cin >> sel;
    p = FoundidBefor(AddBook.head, sel);
    if (p == NULL)
        cout << "要删除的编号不存在" << endl;
    else
    {
        q = p->next;
        p->next = q->next;
        delete q;
        cout << "一条通讯录删除成功" << endl;
    }
}
void NameToTEL(commEntry *head)
{ //输入姓名查找电话
    commEntry *p = head->next;
    string name;
    int count = 0;
    cout << "输入姓名：" << endl;
    fflush(stdin);
    getline(cin, name);
    while (p)
    {
        if (name.compare(p->name) == 0)
        {
            cout << name << " 的电话: " << p->tel << endl;
            count++;
        }
        p = p->next;
    }
    if (count == 0)
        cout << "没有 \"" << name << "\" 电话" << endl;
    else
        cout << name << " 一共有: " << count << "个电话" << endl;
}