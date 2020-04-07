#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

class CommEntry
{
private:
    string name;       //姓名
    unsigned telCount; //电话的个数
    string *tels;      //电话
    string *telType;   //电话类型
    string addr;       //地址

public:
    CommEntry(unsigned num = 3);            //构造函数初始化
    ~CommEntry();                           //析构函数释放内存
    void input();                           //输入通讯录条目
    void output();                          //输出通讯录条目
    void setName(string nm);                //设置名字
    void setTel(string t, int iNum);        //设置电话
    void setTelType(string type, int iNum); //设置电话
    void setAddr(string ad);                //设置地址
    string getName();                       //获取姓名
    string getTel(int iNum);                //获取电话
    string getTelType(int iNum);            //获取电话
    string getAddr();                       //获取地址
    bool iNumINtelCo(int iNum);             //判断要修改的是否在范围内
};

unsigned int displayMenu();
void funChoose();
void setName(CommEntry &comE);
void setTel(CommEntry &comE);
void setTelType(CommEntry &comE);
void setAddr(CommEntry &comE);
CommEntry *Init();

CommEntry ::CommEntry(unsigned num)
{
    telCount = num;
    tels = new string[telCount];
    telType = new string[telCount];
}

CommEntry ::~CommEntry()
{
    delete[] tels;
    delete[] telType;
}

bool CommEntry ::iNumINtelCo(int iNum)
{
    if (iNum > telCount || iNum <= 0)
        return false;
    else
        return true;
}

string CommEntry ::getName()
{
    return name;
}

string CommEntry ::getTel(int iNum)
{
    return tels[iNum];
}

string CommEntry ::getTelType(int iNum)
{ //获取电话类型
    return telType[iNum];
}

string CommEntry ::getAddr()
{
    return addr;
}

void CommEntry ::setName(string nm)
{
    name = nm;
}

void CommEntry ::setTel(string t, int iNum)
{
    tels[iNum] = t;
}

void CommEntry ::setTelType(string type, int iNum)
{ //设置电话类型
    telType[iNum] = type;
}

void CommEntry ::setAddr(string ad)
{
    addr = ad;
}

void CommEntry ::input()
{ //输入通讯录
    string temp;
    cout << "\n请输入" << endl;

    cout << "姓名: ";
    fflush(stdin);
    getline(cin, temp);
    setName(temp);

    for (int i = 0; i < telCount; i++)
    {
        cout << "第" << i + 1 << "个电话: ";
        fflush(stdin);
        getline(cin, temp);
        setTel(temp, i);
        cout << "电话类型: ";
        fflush(stdin);
        getline(cin, temp);
        setTelType(temp, i);
    }

    cout << "地址: ";
    fflush(stdin);
    getline(cin, temp);
    setAddr(temp);
}

void CommEntry ::output()
{ //输出通讯录
    cout << setw(14) << left << "姓名";
    for (int i = 0; i < telCount; i++)
        cout << setw(18) << left << telType[i];
    cout << "地址" << endl;

    cout << setw(14) << left << name;
    for (int i = 0; i < telCount; i++)
        cout << setw(18) << left << tels[i];
    cout << addr << endl;
}

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
    system("pause");
    return 0;
}