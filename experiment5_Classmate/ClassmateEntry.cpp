#include "ClassmateEntry.h"
using namespace std;
//����ͬѧ��Ŀ��Ϣ
void ClassmateEntry::input()
{
    string temp;
    cout << "����ѧУ: ";
    getline(cin, temp);
    setSch(temp);

    cout << "����༶: ";
    getline(cin, temp);
    setCla(temp);
}

//���ͬѧ��Ŀ��Ϣ
void ClassmateEntry::output()
{
    cout << setw(20) << getSch()
        << setw(16) << getCla();
}

//���ͬѧ��Ŀ������
void ClassmateEntry::outputHead()
{
    cout << setw(20) << "ѧУ"
        << setw(16) << "�༶";
}

//����ͬѧѧУ
void ClassmateEntry::setSch(string sch)
{
    m_sch = sch;
}

//��ȡͬѧѧУ
string ClassmateEntry::getSch()
{
    return m_sch;
}

//����ͬѧ�༶
void ClassmateEntry::setCla(string cla)
{
    m_cla = cla;
}

//��ȡͬѧ�༶
string ClassmateEntry::getCla()
{
    return m_cla;
}