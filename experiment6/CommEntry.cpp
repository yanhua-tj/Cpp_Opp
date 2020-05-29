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
    cout << "\n������" << endl;

    cout << "����: ";
    getline(cin, temp);
    setName(temp);

    cout << "�绰: ";
    getline(cin, temp);
    setTel(temp);

    cout << "��ַ: ";
    getline(cin, temp);
    setAddr(temp);
}

void CommEntry::output()
{
    cout << setw(14) << left << "����"
        << setw(18) << left << "�绰"
        << "��ַ" << endl;
    cout << setw(14) << left << getName()
        << setw(18) << left << getTel()
        << getAddr() << endl;
}

istream& operator>>(istream& in, CommEntry& a)
{
    cout << "\n������" << endl;

    cout << "����: ";
    getline(in, a.name);

    cout << "�绰: ";
    getline(in, a.tel);

    cout << "��ַ: ";
    getline(in, a.addr);

    return in;
}

ostream& operator<<(ostream& out, CommEntry& a)
{
    cout << setw(14) << left << "����"
        << setw(18) << left << "�绰"
        << "��ַ" << endl;
    cout << setw(14) << left << a.name
        << setw(18) << left << a.tel
        << a.addr << endl;
    return out;
}
