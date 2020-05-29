#include "CommEntry.h"


string CommEntry::getName()
{
    return name;
}

string CommEntry::getTel()
{
    return tel;
}

string CommEntry::getAddr()
{
    return addr;
}

void CommEntry::setName(string nm)
{
    name = nm;
}

void CommEntry::setTel(string t)
{
    tel = t;
}

void CommEntry::setAddr(string ad)
{
    addr = ad;
}

void CommEntry::input()
{
    string temp;
    cout << "\n请输入" << endl;

    cout << "姓名: ";
    getline(cin, temp);
    setName(temp);

    cout << "电话: ";
    getline(cin, temp);
    setTel(temp);

    cout << "地址: ";
    getline(cin, temp);
    setAddr(temp);
}

void CommEntry::output()
{
    cout << setw(14) << left << "姓名"
        << setw(18) << left << "电话"
        << "地址" << endl;
    cout << setw(14) << left << getName()
        << setw(18) << left << getTel()
        << getAddr() << endl;
}

istream& operator>>(istream& in, CommEntry& a)
{
    cout << "\n请输入" << endl;

    cout << "姓名: ";
    getline(in, a.name);

    cout << "电话: ";
    getline(in, a.tel);

    cout << "地址: ";
    getline(in, a.addr);

    return in;
}

ostream& operator<<(ostream& out, CommEntry& a)
{
    cout << setw(14) << left << "姓名"
        << setw(18) << left << "电话"
        << "地址" << endl;
    cout << setw(14) << left << a.name
        << setw(18) << left << a.tel
        << a.addr << endl;
    return out;
}
