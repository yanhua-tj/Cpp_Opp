#include "CommEntry.h"
#include <iostream>
#include <iomanip>
using namespace std;

//����ͨѶ¼��Ŀ
void CommEntry::input()
{
    string temp;
    cout << "��������: " << endl;
    getline(cin, temp);
    setName(temp);

    cout << "����绰: " << endl;
    getline(cin, temp);
    setTel(temp);

    cout << "һ��ͨѶ¼д��ɹ�! " << endl;
}

//���ͨѶ¼��Ŀ
void CommEntry::output()
{
    cout << setw(12) << m_Name
        << setw(18) << m_Tel
        << setw(12) << sm_Owner << endl;
}

//������Ŀ����
void CommEntry::setName(string name)
{
    m_Name = name;
}

//������Ŀ�绰
void CommEntry::setTel(string tel)
{
    m_Tel = tel;
}

//������Ŀӵ����
void CommEntry::setOwner(string owner)
{
    sm_Owner = owner;
}

//��ȡ��Ŀ����
string CommEntry::getName()
{
    return m_Name;
}

//��ȡ��Ŀ�绰
string CommEntry::getTel()
{
    return m_Tel;
}

//��ȡ��Ŀӵ����
string CommEntry::getOwner()
{
    return sm_Owner;
}