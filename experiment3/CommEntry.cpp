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
{ //��ȡ�绰����
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
{ //���õ绰����
    telType[iNum] = type;
}

void CommEntry ::setAddr(string ad)
{
    addr = ad;
}

void CommEntry ::input()
{ //����ͨѶ¼
    string temp;
    cout << "\n������" << endl;

    cout << "����: ";
    fflush(stdin);
    getline(cin, temp);
    setName(temp);

    for (int i = 0; i < telCount; i++)
    {
        cout << "��" << i + 1 << "���绰: ";
        fflush(stdin);
        getline(cin, temp);
        setTel(temp, i);
        cout << "�绰����: ";
        fflush(stdin);
        getline(cin, temp);
        setTelType(temp, i);
    }

    cout << "��ַ: ";
    fflush(stdin);
    getline(cin, temp);
    setAddr(temp);
}

void CommEntry ::output()
{ //���ͨѶ¼
    cout << setw(14) << left << "����";
    for (int i = 0; i < telCount; i++)
        cout << setw(18) << left << telType[i];
    cout << "��ַ" << endl;

    cout << setw(14) << left << name;
    for (int i = 0; i < telCount; i++)
        cout << setw(18) << left << tels[i];
    cout << addr << endl;
}
