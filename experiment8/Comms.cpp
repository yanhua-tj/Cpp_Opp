#include "Comms.h"
#include <typeinfo>
//��ʼ�����캯��
Comms::Comms(unsigned maxCount) : m_count(0)
{
    //��ʼ�����ͨѶ¼��
    m_maxCount = maxCount;
    mp_Ces = new CommEntry * [m_maxCount];
}

//�����ͷ��ڴ�
Comms::~Comms()
{
    delete[]mp_Ces;
}

//����ͨѶ¼
void Comms::input()
{
    cout << "�����������Ŀ����: ";
    unsigned num = 0;
    cin >> num;
    while (m_count + num > m_maxCount)
    {
        cout << "ʣ��ͨѶ¼��Ŀ��������, ʣ��" << m_maxCount - m_count << endl;
        cout << "�����������Ŀ����: ";
        cin >> num;
    }
    for (int i = 0; i < (int)num; i++)
    {
        cout << endl;
        cout << "0.��ͨͨѶ¼��Ŀ" << endl;
        cout << "1.����ͨѶ¼��Ŀ" << endl;
        cout << "��ѡ��Ҫ����ͨѶ¼����(0/1): ";
        int choice = 0;
        cin >> choice;
        if (choice == 1)
            mp_Ces[i + m_count] = new FriendEntry;      //����1Ϊ����ͨѶ¼
        else
            mp_Ces[i + m_count] = new CommEntry;        //����Ϊ��ͨͨѶ¼
        mp_Ces[i + m_count]->input();
    }
    m_count += num;
}

//���ͨѶ¼
void Comms::outputAll()
{
    CommEntry::outputHead();
    FriendEntry::outputHead();
    cout << endl;
    for (unsigned i = 0; i < m_count; i++)
    {
        mp_Ces[i]->output();
    }
    cout << "��ǰͨѶ¼һ����: " << m_count;
    cout << "    ͨѶ¼�������: " << m_maxCount << endl;
}

//�������������±�
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
    cout << name << "�绰�޸�Ϊ: " << tel << endl;
}

//��ʾ������Ŀ
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
//��ʾһ����Ŀ
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
