#include "CommEntry.h"

using namespace std;

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
