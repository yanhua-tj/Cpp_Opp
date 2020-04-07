#include "CommEntry.h"

//using namespace std;

unsigned int displayMenu();
void funChoose();
void setName(CommEntry &comE);
void setTel(CommEntry &comE);
void setTelType(CommEntry &comE);
void setAddr(CommEntry &comE);
CommEntry *Init();

unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "===================" << endl;
    cout << "1.输入通讯录条目" << endl;
    cout << "2.输出通讯录条目" << endl;
    cout << "3.修改姓名" << endl;
    cout << "4.修改电话" << endl;
    cout << "5.修改电话类型" << endl;
    cout << "6.修改地址" << endl;
    cout << "0.退出" << endl;
    cout << "===================" << endl;
    cout << "请输入一个数(0-6)选择：";
    cin >> i;
    return i;
}

void funChoose()
{ //选择功能
    unsigned int ichoose = 1;
    CommEntry *comE = NULL;
    char t;
    while (ichoose != 0)
    {
        ichoose = displayMenu(); //菜单选择
        while (ichoose > 6)
        {
            cout << "输入的数不在范围内！" << endl;
            ichoose = displayMenu();
        }
        fflush(stdin); //清空缓冲区
        if (comE == NULL && ichoose != 1 && ichoose != 0)
            cout << "没有通讯录" << endl;
        else
            switch (ichoose)
            {
            case 0: //功能0,结束程序
                break;
            case 1: //功能1,输入通讯录
                cout << "是否自定义电话个数(默认为3)?(y/n)";
                cin >> t;
                if (t == 'y' || t == 'Y')
                    comE = Init();
                else
                    comE = new CommEntry();
                comE->input();
                break;
            case 2: //功能2,输出通讯录
                comE->output();
                break;
            case 3: //功能3,修改姓名
                setName(*comE);
                break;
            case 4: //功能4,修改电话
                setTel(*comE);
                break;
            case 5: //功能5,修改电话类型
                setTelType(*comE);
                break;
            case 6: //功能6,修改地址
                setAddr(*comE);
                break;
            }
    }
    delete comE;
}

void setName(CommEntry &comE)
{ //修改姓名
    string str;
    cout << "\n修改姓名为: ";
    getline(cin, str);
    comE.setName(str);
}

void setTel(CommEntry &comE)
{ //修改电话
    string str;
    int iNum;
    comE.output();
    cout << "修改第几个电话？";
    cin >> iNum;
    if (comE.iNumINtelCo(iNum) == false)
    {
        cout << "不存在该电话, 不能修改";
        return;
    }
    else
    {
        cout << "\n修改电话为: ";
        fflush(stdin);
        getline(cin, str);
        comE.setTel(str, iNum - 1);
    }
}

void setTelType(CommEntry &comE)
{ //修改电话类型
    string str;
    int iNum;
    comE.output();
    cout << "修改第几个电话类型？";
    cin >> iNum;
    if (comE.iNumINtelCo(iNum) == false)
    {
        cout << "不存在该电话类型, 不能修改";
        return;
    }
    else
    {
        cout << "\n修改电话类型为: ";
        fflush(stdin);
        getline(cin, str);
        comE.setTelType(str, iNum - 1);
    }
}

void setAddr(CommEntry &comE)
{ //修改地址
    string str;
    cout << "\n修改地址为: ";
    getline(cin, str);
    comE.setAddr(str);
}

CommEntry *Init()
{
    CommEntry *comE;
    unsigned int num;
    cout << "输入电话个数: " << endl;
    cin >> num;
    comE = new CommEntry(num);
    return comE;
}

int main()
{
    funChoose();
    return 0;
}
