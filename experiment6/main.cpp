#include "CommEntry.h"
#include <cstdlib>

//using namespace std;

unsigned int displayMenu();
void funChoose(CommEntry&);

unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "===================" << endl;
    cout << "1.输入通讯录条目" << endl;
    cout << "2.输出通讯录条目" << endl;
    cout << "3.修改姓名" << endl;
    cout << "4.修改电话" << endl;
    cout << "5.修改地址" << endl;
    cout << "0.退出" << endl;
    cout << "===================" << endl;
    cout << "请输入一个数(0-5)选择：";
    cin >> i;
    return i;
}

void funChoose(CommEntry& comE)
{
    string str;
    unsigned int ichoose = 1;
    while (ichoose != 0)
    {
        ichoose = displayMenu();
        while (ichoose > 5)
        {
            cout << "输入的数不在范围内！" << endl;
            ichoose = displayMenu();
        }
        cin.ignore(16, '\n');
        switch (ichoose)
        {
        case 0: //功能0,结束程序
            break;
        case 1: //功能1,输入通讯录
            cin >> comE;
            break;
        case 2: //功能2,输出通讯录
            cout << comE;
            break;
        case 3: //功能3,修改姓名
            cout << "\n修改姓名为: ";
            getline(cin, str);
            comE.setName(str);
            break;
        case 4: //功能4,修改电话
            cout << "\n修改电话为: ";
            getline(cin, str);
            comE.setTel(str);
            break;
        case 5: //功能5,修改地址
            cout << "\n修改地址为: ";
            getline(cin, str);
            comE.setAddr(str);
            break;
        }
        system("pause");
        system("cls");
    }
}

int main()
{
    CommEntry comE;
    funChoose(comE);
    return 0;
}
