#pragma once
#include "CommEntry.h"
using namespace std;

class ClassmateEntry : public CommEntry
{
public:
    //����ͬѧ��Ŀ��Ϣ
    void input();

    //���ͬѧ��Ŀ��Ϣ
    void output();

    //���ͬѧ��Ŀ������
    static void outputHead();

    //����ͬѧѧУ
    void setSch(string sch);

    //��ȡͬѧѧУ
    string getSch();

    //����ͬѧ�༶
    void setCla(string cla);

    //��ȡͬѧ�༶
    string getCla();

private:
    //ͬѧѧУ
    string m_sch;

    //ͬѧ�༶
    string m_cla;
};

