#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // ofstream out;
    // out.open("text.txt", ios::out);
    // out << "姓名：张三" << endl;
    // out << "年龄：18" << endl;
    // out << "家庭住址: hsgdd" << endl;
    // out.close();
    ifstream inf;
    inf.open("text.txt", ios::in);
    if (!inf.is_open())
        cout << "文件打开失败" << endl;
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