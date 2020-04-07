#include "CommEntry.h"

using namespace std;

string CommEntry ::getName()
{
    return name;
}

string CommEntry ::getTel()
{
    return tel;
}

string CommEntry ::getAddr()
{
    return addr;
}

void CommEntry ::setName(string nm)
{
    name = nm;
}

void CommEntry ::setTel(string t)
{
    tel = t;
}

void CommEntry ::setAddr(string ad)
{
    addr = ad;
}

void CommEntry ::input()
{
    string temp;
    cout << "\n������" << endl;

    cout << "����: ";
    fflush(stdin);
    getline(cin, temp);
    setName(temp);

    cout << "�绰: ";
    fflush(stdin);
    getline(cin, temp);
    setTel(temp);

    cout << "��ַ: ";
    fflush(stdin);
    getline(cin, temp);
    setAddr(temp);
}

void CommEntry ::output()
{
    cout << setw(14) << left << "����"
         << setw(18) << left << "�绰"
         << "��ַ" << endl;
    cout << setw(14) << left << getName()
         << setw(18) << left << getTel()
         << getAddr() << endl;
}
