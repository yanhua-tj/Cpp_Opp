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
    string name;       //����
    unsigned telCount; //�绰�ĸ���
    string *tels;      //�绰
    string *telType;   //�绰����
    string addr;       //��ַ

public:
    CommEntry(unsigned num = 3);            //���캯����ʼ��
    ~CommEntry();                           //���������ͷ��ڴ�
    void input();                           //����ͨѶ¼��Ŀ
    void output();                          //���ͨѶ¼��Ŀ
    void setName(string nm);                //��������
    void setTel(string t, int iNum);        //���õ绰
    void setTelType(string type, int iNum); //���õ绰
    void setAddr(string ad);                //���õ�ַ
    string getName();                       //��ȡ����
    string getTel(int iNum);                //��ȡ�绰
    string getTelType(int iNum);            //��ȡ�绰
    string getAddr();                       //��ȡ��ַ
    bool iNumINtelCo(int iNum);             //�ж�Ҫ�޸ĵ��Ƿ��ڷ�Χ��
};

#endif // COMMENTRY_H_INCLUDED
