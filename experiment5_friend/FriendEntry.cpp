#include "FriendEntry.h"
using namespace std;
//输入朋友条目信息
void FriendEntry::input()
{
    string temp;
    cout << "输入地址: ";
    getline(cin, temp);
    setAddr(temp);

    cout << "输入邮箱: ";
    getline(cin, temp);
    setEmail(temp);
}

//输出朋友条目信息
void FriendEntry::output()
{
    cout << setw(20) << getAddr()
        << setw(16) << getEmail();
}

//输出朋友条目的属性
void FriendEntry::outputHead()
{
    cout << setw(20) << "地址"
        << setw(16) << "邮箱";
}

//设置朋友地址
void FriendEntry::setAddr(string addr)
{
    m_addr = addr;
}

//获取朋友地址
string FriendEntry::getAddr()
{
    return m_addr;
}

//设置朋友邮箱
void FriendEntry::setEmail(string email)
{
    m_email = email;
}

//获取朋友邮箱
string FriendEntry::getEmail()
{
    return m_email;
}