#pragma once
#include <string>
using namespace std;
class CommEntry
{
public:
    //����ͨѶ¼��Ŀ
    void input();

    //���ͨѶ¼��Ŀ
    void output();

    //������Ŀ����
    void setName(string name);

    //������Ŀ�绰
    void setTel(string tel);

    //������Ŀӵ����
    void setOwner(string owner);

    //��ȡ��Ŀ����
    string getName();

    //��ȡ��Ŀ�绰
    string getTel();

    //��ȡ��Ŀӵ����
    string getOwner();

private:
    //ͨѶ¼��Ŀ����
    string m_Name = "";

    //ͨѶ¼��Ŀ�绰
    string m_Tel = "";

    //ͨѶ¼��Ŀӵ����
    static string sm_Owner;
};
