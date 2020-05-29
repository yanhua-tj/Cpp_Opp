#include <iostream>
#include <cstdlib>
#include "Complex.h"
#include "Complexcount.h"
using namespace std;

int menu();											//�˵�
void fun(Complexcount&);											//ѡ����

//�˵�
int menu()
{
    int i;
    cout << "����������" << endl;
    cout << "1.���븴��" << endl;
    cout << "2.�������" << endl;
    cout << "3.�����ӷ�" << endl;
    cout << "4.��������" << endl;
    cout << "5.�����˷�" << endl;
    cout << "6.��������" << endl;
    cout << "7.�����ļӼ��˳�" << endl;
    cout << "0.�˳�����" << endl;
    cout << "����������(0-7)ѡ����: ";
    cin >> i;
    return i;
}

//ѡ����
void fun(Complexcount& counter)
{
    while (true)
    {
        int funId = menu();
        while (funId < 0 || funId > 7)
        {
            cout << "��������, ���������룡" << endl;
            system("pause");
            system("cls");
            funId = menu();
        }
        if (funId == 0)
            break;
        switch (funId)
        {
        case 1:     //���븴��
            counter.input();
            break;
        case 2:     //�������
            counter.output();
            break;
        case 3:     //�������
            cout << "A + B��Ľ��Ϊ: " << counter.add() << endl;
            break;
        case 4:     //�������
            cout << "A - B��Ľ��Ϊ: " << counter.sub() << endl;
            break;
        case 5:     //�������
            cout << "A * B��Ľ��Ϊ: " << counter.mul() << endl;
            break;
        case 6:     //�������
            cout << "A / B��Ľ��Ϊ: " << counter.div() << endl;
            break;
        case 7:     //�������
            cout << "A + B��Ľ��Ϊ: " << counter.add() << endl;
            cout << "A - B��Ľ��Ϊ: " << counter.sub() << endl;
            cout << "A * B��Ľ��Ϊ: " << counter.mul() << endl;
            cout << "A / B��Ľ��Ϊ: " << counter.div() << endl;
            break;
        }
        system("pause");
        system("cls");
    }
}

int main()
{
    Complexcount counter;
    fun(counter);
    return 0;
}
