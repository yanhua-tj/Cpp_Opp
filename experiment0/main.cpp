/*
 * @Author: yanhua
 * @Date: 2020-03-10 21:13:40
 * @Last Modified by: yanhua
 * @Last Modified time: 2020-03-17 18:08:38
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

struct commEntry
{
    string name;
    string tel;
    string addr;
};

unsigned int displayMenu();
void funChoose(commEntry &peop);
void InputCommEntry(commEntry &p);
void ShowCommEntry(commEntry &p);
void setName(commEntry &p);
void setTel(commEntry &p);
void setAddr(commEntry &p);

int main()
{
    commEntry peop;
    peop.addr = "";
    peop.name = "";
    peop.tel = "";
    funChoose(peop);
    return 0;
}

unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "===================" << endl;
    cout << "1.����ͨѶ¼��Ŀ" << endl;
    cout << "2.���ͨѶ¼��Ŀ" << endl;
    cout << "3.�޸�����" << endl;
    cout << "4.�޸ĵ绰" << endl;
    cout << "5.�޸ĵ�ַ" << endl;
    cout << "0.�˳�" << endl;
    cout << "===================" << endl;
    cout << "������һ����(0-5)ѡ��";
    cin >> i;
    return i;
}
void funChoose(commEntry &peop)
{
    unsigned int ichoose = 1;
    while (ichoose != 0)
    {
        ichoose = displayMenu();
        while (ichoose > 5)
        {
            cout << "����������ڷ�Χ�ڣ�" << endl;
            ichoose = displayMenu();
        }
        switch (ichoose)
        {
        case 0: //����0,��������
            break;
        case 1: //����1,����ͨѶ¼
            InputCommEntry(peop);
            break;
        case 2: //����2,���ͨѶ¼
            ShowCommEntry(peop);
            break;
        case 3: //����3,�޸�����
            setName(peop);
            break;
        case 4: //����4,�޸ĵ绰
            setTel(peop);
            break;
        case 5: //����5,�޸ĵ�ַ
            setAddr(peop);
            break;
        }
    }
}
void InputCommEntry(commEntry &p)
{
    cout << endl;
    cout << "������: " << endl;
    cout << "����: ";
    fflush(stdin);
    getline(cin, p.name);
    cout << "�绰����: ";
    getline(cin, p.tel);
    cout << "��ַ: ";
    getline(cin, p.addr);
}
void ShowCommEntry(commEntry &p)
{
    if (p.name == "" || p.tel == "" || p.addr == "")
    {
        cout << "û��ͨѶ¼��Ŀ" << endl;
    }
    else
    {
        cout << setw(10) << left << "����"
             << setw(14) << left << "�绰"
             << "��ַ" << endl;
        cout << setw(10) << left << p.name
             << setw(14) << left << p.tel
             << p.addr << endl;
    }
}
void setName(commEntry &p)
{
    if (p.name == "")
    {
        cout << "û��ͨѶ¼��Ŀ" << endl;
    }
    else
    {
        cout << endl;
        cout << "�������޸�Ϊ: ";
        fflush(stdin);
        cin >> p.name;
        cout << "�����޸ĳɹ�" << endl;
    }
}
void setTel(commEntry &p)
{
    if (p.tel == "")
    {
        cout << "û��ͨѶ¼��Ŀ" << endl;
    }
    else
    {
        cout << endl;
        cout << "���绰�޸�Ϊ: ";
        fflush(stdin);
        cin >> p.tel;
        cout << "�绰�޸ĳɹ�" << endl;
    }
}
void setAddr(commEntry &p)
{
    if (p.addr == "")
    {
        cout << "û��ͨѶ¼��Ŀ" << endl;
    }
    else
    {
        cout << endl;
        cout << "����ַ�޸�Ϊ: ";
        fflush(stdin);
        cin >> p.addr;
        cout << "��ַ�޸ĳɹ�" << endl;
    }
}
