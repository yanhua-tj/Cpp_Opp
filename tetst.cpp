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
        cout << "1. 输入float浮点数查看其在内存中16进制码" << endl;
        cout << "2. 输入16进制码转为浮点数" << endl;
        cout << "0. 退出程序" << endl;
        int chose;
        cout << "请输入: ";
        cin >> chose;
        switch (chose)
        {
        case 0:
            return 0;
            break;
        case 1:
            cout << "输入float浮点数: ";
            cin >> t.ib;
            cout << t.ib << "在内存中16进制: " << hex << uppercase << showbase << t.ia << endl;
            break;
        case 2:
            cout << "输入16进制码: ";
            scanf("%x", &t.ia);
            //cin >> hex >> t.ia;       有问题
            //t.ia = 0xc1360000;
            //cout << hex << uppercase << showbase << t.ia << endl;
            cout << hex << uppercase << showbase << t.ia << "的float表示" << setprecision(8) << t.ib << endl;
            break;
        default:
            cout << "输入错误" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}