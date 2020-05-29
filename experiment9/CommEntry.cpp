#include "CommEntry.h"
#include <typeinfo>
#include <fstream>
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

//����>>����ͨѶ¼��Ŀ
istream& operator>>(istream& in, CommEntry& a)
{
    if (typeid(in) == typeid(istream))
    {
        cout << "��������: ";
        getline(in, a.m_name);

        cout << "����绰: ";
        getline(in, a.m_tel);
    }
    else if (typeid(in) == typeid(ifstream))
    {
        char temp[32];
        in.getline(temp, 32);
        a.m_name = temp;
        in.getline(temp, 32);
        a.m_tel = temp;
    }
    return in;
}

//���ͨѶ¼��Ŀ
void CommEntry::output()
{
    cout << setw(14) << getName()
        << setw(18) << getTel()
        << endl;
}

//����<<���ͨѶ¼��Ŀ
ostream& operator<<(ostream& out, const CommEntry& a)
{
    if (typeid(out) == typeid(ostream))
    {
        out << setw(14) << a.m_name
            << setw(18) << a.m_tel << endl;
    }
    else if (typeid(out) == typeid(ofstream))
    {
        out << a.m_name << endl;
        out << a.m_tel << endl;
    }
    return out;
}

//���ͨѶ¼��Ŀ������
void CommEntry::outputInfo()
{
    cout << setw(14) << "����"
        << setw(18) << "�绰";
}