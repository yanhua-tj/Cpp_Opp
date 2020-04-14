#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "CommEntry.h"
using namespace std;

unsigned menu();                        //���˵�
void menuselect(CommEntry& a);          //�˵�����ѡ��
void setCommName(CommEntry& a);         //�޸���Ŀ����
void setCommTel(CommEntry& a);          //�޸���Ŀ�绰
void setCommOwner(CommEntry& a);        //�޸���Ŀӵ����

string CommEntry::sm_Owner = "δָ��";

int main()
{
    CommEntry comme;
    menuselect(comme);
    return 0;
}

//���˵�
unsigned menu()
{
    cout << "=============================" << endl;
    cout << "       1.����ͨѶ¼��Ŀ" << endl;
    cout << "       2.���ͨѶ¼��Ŀ" << endl;
    cout << "          3.�޸�����" << endl;
    cout << "          4.�޸ĵ绰" << endl;
    cout << "         5.�޸�ӵ����" << endl;
    cout << "            0.�˳�" << endl;
    cout << "=============================" << endl;
    cout << endl;
    cout << "��������(0-5)ѡ����: ";
    unsigned i = 999;
    cin >> i;
    return i;
}

//�˵�����ѡ��
void menuselect(CommEntry& a)
{
    unsigned select = 999;
    while (select != 0)
    {
        select = menu();        //�������˵�
        while (select > 6)
        {
            cout << "��������, ����������! " << endl;
            system("pause");
            system("cls");
            select = menu();
        }
        if (select == 0)
        {
            cout << "��ӭ�´�ʹ��" << endl;
            break;
        }
        cin.ignore(16, '\n');
        switch (select)
        {
        case 1:
            a.input();
            break;
        case 2:
            cout << left;
            cout << setw(12) << "����"
                << setw(18) << "�绰"
                << setw(12) << "ӵ����" << endl;
            a.output();
            break;
        case 3:
            setCommName(a);
            break;
        case 4:
            setCommTel(a);
            break;
        case 5:
            setCommOwner(a);
            break;
        }
        system("pause");
        system("cls");
    }
}

//�޸���Ŀ����
void setCommName(CommEntry& a)
{
    cout << "�޸�����Ϊ: " << endl;
    string temp;
    getline(cin, temp);
    a.setName(temp);
}

//�޸���Ŀ�绰
void setCommTel(CommEntry& a)
{
    cout << "�޸ĵ绰Ϊ: " << endl;
    string temp;
    getline(cin, temp);
    a.setTel(temp);
}

//�޸���Ŀӵ����
void setCommOwner(CommEntry& a)
{
    cout << "�޸�ӵ����Ϊ: " << endl;
    string temp;
    getline(cin, temp);
    a.setOwner(temp);
}
