#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    union a {
        int ia;
        float ib;
    };
    a t;
    while (true)
    {
        cout << "1. ����float�������鿴�����ڴ���16������" << endl;
        cout << "2. ����16������תΪ������" << endl;
        cout << "0. �˳�����" << endl;
        int chose;
        cout << "������: ";
        cin >> chose;
        switch (chose)
        {
        case 0:
            return 0;
            break;
        case 1:
            cout << "����float������: ";
            cin >> t.ib;
            cout << t.ib << "���ڴ���16����: " << hex << uppercase << showbase << t.ia << endl;
            break;
        case 2:
            cout << "����16������: ";
            scanf("%x", &t.ia);
            //cin >> hex >> t.ia;       ������
            //t.ia = 0xc1360000;
            //cout << hex << uppercase << showbase << t.ia << endl;
            cout << hex << uppercase << showbase << t.ia << "��float��ʾ" << setprecision(8) << t.ib << endl;
            break;
        default:
            cout << "�������" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}