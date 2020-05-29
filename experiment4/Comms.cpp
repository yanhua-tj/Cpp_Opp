#include "Comms.h"
//初始化构造函数
Comms::Comms(unsigned maxCount) : m_count(0)
{
    //初始化最大通讯录数
    m_maxCount = maxCount;
    mp_Ce = new CommEntry[m_maxCount];
}

//析构释放内存
Comms::~Comms()
{
    delete[]mp_Ce;
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
    cin.ignore(16, '\n');           //清空缓冲区
    for (int i = 0; i < (int)num; i++)
    {
        cout << "添加第" << i + 1 << "条通讯录" << endl;
        mp_Ce[i + m_count].input();
    }
    m_count += num;
}

//输出通讯录
void Comms::outputAll()
{
    CommEntry::outputInfo();
    cout << endl;
    for (unsigned i = 0; i < m_count; i++)
    {
        mp_Ce[i].output();
    }
    cout << "当前通讯录一共有: " << m_count;
    cout << "\t通讯录最大容量: " << m_maxCount << endl;
}

//输入姓名查找下标
int Comms::findname(string name)
{
    for (unsigned i = 0; i < m_count; i++)
    {
        if (mp_Ce[i].getName() == name)
        {
            return (int)i;
        }
    }
    return -1;
}

//输入电话查找下标
int Comms::findtel(string tel)
{
    for (unsigned i = 0; i < m_count; i++)
    {
        if (mp_Ce[i].getTel() == tel)
        {
            return (int)i;
        }
    }
    return -1;
}

//输入姓名修改其电话
void Comms::modifytel(string name, string tel)
{
    mp_Ce[findname(name)].setTel(tel);
    cout << name << "电话修改为: " << tel << endl;
}

//输入电话修改其姓名
void Comms::modifyname(string tel, string name)
{
    mp_Ce[findtel(tel)].setName(name);
    cout << tel << "的联系人修改为: " << name << endl;
}

//输入电话模糊查找
void Comms::fuzzysearchtel(string tel)
{
    int count = 0;
    cout << "模糊查找结果: " << endl;
    for (unsigned i = 0; i < m_count; i++)
    {
        string s1 = mp_Ce[i].getTel();
        if (s1.find(tel) != string::npos)
        {
            cout << s1 << endl;
            count ++;
        }
    }
    if (count == 0)
    {
        cout << "模糊查找没有结果" << endl;
    }
    else
    {
        cout << "模糊查找到" << count << "条信息" << endl;
    }
}

//输入姓名模糊查找
void Comms::fuzzysearchname(string name)
{
    int count = 0;
    cout << "模糊查找结果: " << endl;
    for (unsigned i = 0; i < m_count; i++)
    {
        string s1 = mp_Ce[i].getName();
        if (s1.find(name) != string::npos)
        {
            cout << s1 << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "模糊查找没有结果" << endl;
    }
    else
    {
        cout << "模糊查找到" << count << "条信息" << endl;
    }
}
