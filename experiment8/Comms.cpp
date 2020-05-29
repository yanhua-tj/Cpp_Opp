#include "Comms.h"
#include <typeinfo>
//初始化构造函数
Comms::Comms(unsigned maxCount) : m_count(0)
{
    //初始化最大通讯录数
    m_maxCount = maxCount;
    mp_Ces = new CommEntry * [m_maxCount];
}

//析构释放内存
Comms::~Comms()
{
    delete[]mp_Ces;
}

//输入通讯录
void Comms::input()
{
    cout << "请输入添加条目个数: ";
    unsigned num = 0;
    cin >> num;
    while (m_count + num > m_maxCount)
    {
        cout << "剩余通讯录条目数量不足, 剩余" << m_maxCount - m_count << endl;
        cout << "请输入添加条目个数: ";
        cin >> num;
    }
    for (int i = 0; i < (int)num; i++)
    {
        cout << endl;
        cout << "0.普通通讯录条目" << endl;
        cout << "1.朋友通讯录条目" << endl;
        cout << "请选择要导入通讯录类型(0/1): ";
        int choice = 0;
        cin >> choice;
        if (choice == 1)
            mp_Ces[i + m_count] = new FriendEntry;      //输入1为朋友通讯录
        else
            mp_Ces[i + m_count] = new CommEntry;        //其他为普通通讯录
        mp_Ces[i + m_count]->input();
    }
    m_count += num;
}

//输出通讯录
void Comms::outputAll()
{
    CommEntry::outputHead();
    FriendEntry::outputHead();
    cout << endl;
    for (unsigned i = 0; i < m_count; i++)
    {
        mp_Ces[i]->output();
    }
    cout << "当前通讯录一共有: " << m_count;
    cout << "    通讯录最大容量: " << m_maxCount << endl;
}

//输入姓名查找下标
int Comms::find(string name)
{
    for (unsigned i = 0; i < m_count; i++)
    {
        if (mp_Ces[i]->getName() == name)
        {
            return (int)i;
        }
    }
    return -1;
}

void Comms::modify(string name, string tel)
{
    mp_Ces[find(name)]->setTel(tel);
    cout << name << "电话修改为: " << tel << endl;
}

//显示朋友条目
void Comms::outputFri()
{
    CommEntry::outputHead();
    FriendEntry::outputHead();
    cout << endl;
    for (unsigned i = 0; i < m_count; i++)
    {
        if(typeid(*mp_Ces[i]) == typeid(FriendEntry))
            mp_Ces[i]->output();
    }
}
//显示一般条目
void Comms::outputCom()
{
    CommEntry::outputHead();
    cout << endl;
    for (unsigned i = 0; i < m_count; i++)
    {
        if (typeid(*mp_Ces[i]) == typeid(CommEntry))
            mp_Ces[i]->output();
    }
}
