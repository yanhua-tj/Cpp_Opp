#ifndef COMMENTRY_H_INCLUDED
#define COMMENTRY_H_INCLUDED

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

class CommEntry
{
private:
    string name; //����
    string tel;  //�绰
    string addr; //��ַ

public:
    void input();            //����ͨѶ¼��Ŀ
    void output();           //���ͨѶ¼��Ŀ
    void setName(string nm); //������Ŀ������
    void setTel(string t);   //������Ŀ�ĵ绰
    void setAddr(string ad); //������Ŀ�ĵ�ַ
    string getName();        //��ȡ����
    string getTel();         //��ȡ�绰
    string getAddr();        //��ȡ��ַ
};

#endif // COMMENTRY_H_INCLUDED
