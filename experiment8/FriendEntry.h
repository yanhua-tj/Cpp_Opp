#pragma once
#include "CommEntry.h"
using namespace std;

class FriendEntry : public CommEntry
{
private:
    //���ѵ�ַ
    string m_addr;

    //��������
    string m_email;

public:
    //����������Ŀ��Ϣ
    void input();

    //���������Ŀ��Ϣ
    void output();

    //���������Ŀ������
    static void outputHead();

    //�������ѵ�ַ
    void setAddr(string addr);

    //��ȡ���ѵ�ַ
    string getAddr();

    //������������
    void setEmail(string email);

    //��ȡ��������
    string getEmail();
};

