#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ofstream out;
    // out.open("text.txt", ios::out);
    // out << "����������" << endl;
    // out << "���䣺18" << endl;
    // out << "��ͥסַ: hsgdd" << endl;
    // out.close();
    ifstream inf;
    inf.open("text.txt", ios::in);
    if (!inf.is_open())
        cout << "�ļ���ʧ��" << endl;
    char buf[1024] = {0};
    while (inf.getline(buf, sizeof(buf)))
    {
        cout << buf << endl;
    }
    // string str;
    // while (getline(inf, str))
    // {
    //     cout << str << endl;
    // }
    inf.close();
    system("pause");
    return 0;
}