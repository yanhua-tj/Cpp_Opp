#include "CommEntry.h"
using namespace std;

//��ȡ����
string CommEntry::getName()
{
    return m_name;
}

//��ȡ�绰
string CommEntry::getTel()
{
    return m_tel;
}

//������Ŀ������
void CommEntry::setName(string name)
{
    m_name = name;
}

//������Ŀ�ĵ绰
void CommEntry::setTel(string tel)
{
    m_tel = tel;
}

//����ͨѶ¼��Ŀ
void CommEntry::input()
{
    string temp;

    cout << "��������: ";
    getline(cin, temp);
    setName(temp);

    cout << "����绰: ";
    getline(cin, temp);
    setTel(temp);
}

//���ͨѶ¼��Ŀ
void CommEntry::output()
{
    cout << setw(14) << getName()
        << setw(18) << getTel();
}

//���ͨѶ¼��Ŀ������
void CommEntry::outputHead()
{
    cout << setw(14) << "����"
        << setw(18) << "�绰";
}