#include <iostream>
#include <iomanip>
#include "CommEntry.h"
#include "Comms.h"
using namespace std;

//通讯录初始化通讯录条目个数
Comms::Comms(int num = 10)
{
    m_Maxnum = num;                 //通讯录默认最大10个条目
    m_count = 0;                    //当前通讯录个数初始化0
    m_pCe = new CommEntry[num];     //动态开辟指针数组
}

//析构释放通讯录条目内存
Comms::~Comms()
{
    delete []m_pCe;     //释放内存
}

//输入一些通讯录条目
void Comms::inputSome()
{
    cout << "请输入要添加几个通讯录: " << endl;
    unsigned num = 0;
    cin >> num;
    while (num + m_count > m_Maxnum)
    {
        cout << "剩余通讯录不够存储, 请重新输入! " << endl;
        cin >> num;
    }
    for (int i = m_count; i < num + m_count; i++)
    {
        m_pCe[i].input();
    }
}

//输出全部通讯录条目
void Comms::outputAll()
{
    cout << left;
    cout << setw(12) << "姓名"
        << setw(18) << "电话"
        << setw(12) << "拥有者" << endl;
    for (int i = 0; i < m_count; i++)
    {
        m_pCe[i].output();
    }
}

//输入姓名查找通讯录,返回下标
int Comms::findComName(string name)
{
    for (int i = 0; i < m_Maxnum; i++)
    {
        if(m_pCe[i].getName() == name)
            return i;
    }
}

//输入姓名,修改电话
void modifyTel(string name, string tel);

//输入电话,返回通讯录条目下标
int findComTel(string tel);

//输入电话,修改姓名
void modifyName(string tel, string name);

//输入姓名进行模糊查找
void fuzzySearch(string name);
