#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class CommEntry
{
private:
    //����
    string m_name;
    //�绰
    string m_tel;

public:
    //����ͨѶ¼��Ŀ
    virtual void input();

    //���ͨѶ¼��Ŀ
    virtual void output();

    //���ͨѶ¼��Ŀ������
    static void outputHead();

    //������Ŀ������
    void setName(string name);

    //������Ŀ�ĵ绰
    void setTel(string tel);

    //��ȡ����
    string getName();

    //��ȡ�绰
    string getTel();
};
