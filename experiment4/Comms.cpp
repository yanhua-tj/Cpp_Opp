#include <iostream>
#include <iomanip>
#include "CommEntry.h"
#include "Comms.h"
using namespace std;

//ͨѶ¼��ʼ��ͨѶ¼��Ŀ����
Comms::Comms(int num = 10)
{
    m_Maxnum = num;                 //ͨѶ¼Ĭ�����10����Ŀ
    m_count = 0;                    //��ǰͨѶ¼������ʼ��0
    m_pCe = new CommEntry[num];     //��̬����ָ������
}

//�����ͷ�ͨѶ¼��Ŀ�ڴ�
Comms::~Comms()
{
    delete []m_pCe;     //�ͷ��ڴ�
}

//����һЩͨѶ¼��Ŀ
void Comms::inputSome()
{
    cout << "������Ҫ��Ӽ���ͨѶ¼: " << endl;
    unsigned num = 0;
    cin >> num;
    while (num + m_count > m_Maxnum)
    {
        cout << "ʣ��ͨѶ¼�����洢, ����������! " << endl;
        cin >> num;
    }
    for (int i = m_count; i < num + m_count; i++)
    {
        m_pCe[i].input();
    }
}

//���ȫ��ͨѶ¼��Ŀ
void Comms::outputAll()
{
    cout << left;
    cout << setw(12) << "����"
        << setw(18) << "�绰"
        << setw(12) << "ӵ����" << endl;
    for (int i = 0; i < m_count; i++)
    {
        m_pCe[i].output();
    }
}

//������������ͨѶ¼,�����±�
int Comms::findComName(string name)
{
    for (int i = 0; i < m_Maxnum; i++)
    {
        if(m_pCe[i].getName() == name)
            return i;
    }
}

//��������,�޸ĵ绰
void modifyTel(string name, string tel);

//����绰,����ͨѶ¼��Ŀ�±�
int findComTel(string tel);

//����绰,�޸�����
void modifyName(string tel, string name);

//������������ģ������
void fuzzySearch(string name);
