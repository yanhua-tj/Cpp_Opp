#pragma once
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
    friend istream& operator>>(istream&, CommEntry&);
    friend ostream& operator<<(ostream&, CommEntry&);
    void input();            //����ͨѶ¼��Ŀ
    void output();           //���ͨѶ¼��Ŀ
    void setName(string nm); //������Ŀ������
    void setTel(string t);   //������Ŀ�ĵ绰
    void setAddr(string ad); //������Ŀ�ĵ�ַ
    string getName();        //��ȡ����
    string getTel();         //��ȡ�绰
    string getAddr();        //��ȡ��ַ
};
