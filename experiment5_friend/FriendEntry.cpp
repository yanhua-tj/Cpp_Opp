#include "FriendEntry.h"
using namespace std;
//����������Ŀ��Ϣ
void FriendEntry::input()
{
    string temp;
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
    cout << setw(20) << getAddr()
        << setw(16) << getEmail();
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