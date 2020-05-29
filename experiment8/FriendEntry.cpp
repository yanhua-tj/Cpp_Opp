#include "FriendEntry.h"
using namespace std;
//����������Ŀ��Ϣ
void FriendEntry::input()
{
    cin.ignore(16, '\n');           //��ջ�����
    string temp;
    cout << "��������: ";
    getline(cin, temp);
    setName(temp);

    cout << "����绰: ";
    getline(cin, temp);
    setTel(temp);

    cout << "�����ַ: ";
    getline(cin, temp);
    setAddr(temp);

    cout << "��������: ";
    getline(cin, temp);
    setEmail(temp);
}

//���������Ŀ��Ϣ
void FriendEntry::output()
{
    cout << setw(14) << getName()
        << setw(18) << getTel()
        << setw(20) << getAddr()
        << setw(16) << getEmail()
        << endl;
}

//���������Ŀ������
void FriendEntry::outputHead()
{
    cout << setw(20) << "��ַ"
        << setw(16) << "����";
}

//�������ѵ�ַ
void FriendEntry::setAddr(string addr)
{
    m_addr = addr;
}

//��ȡ���ѵ�ַ
string FriendEntry::getAddr()
{
    return m_addr;
}

//������������
void FriendEntry::setEmail(string email)
{
    m_email = email;
}

//��ȡ��������
string FriendEntry::getEmail()
{
    return m_email;
}