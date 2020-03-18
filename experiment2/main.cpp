/*
 * @Author: yanhua
 * @Date: 2020-03-17 18:04:25
 * @Last Modified by:   yanhua
 * @Last Modified time: 2020-03-17 18:04:25
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <fstream>
using namespace std;

struct commEntry
{
    string name;
    string tel;
    string addr;
    commEntry *next;
};

unsigned int displayMenu();
void funChoose(commEntry *&head);
void InputCommEntry(commEntry *&head);
void ShowCommEntry(commEntry *&head);
void setName(commEntry &p);
void setTel(commEntry &p);
void setAddr(commEntry &p);
void OuttoFile(commEntry *&head);
void ReadtoFile(commEntry *&head);

int main()
{
    commEntry *head = new commEntry;
    head->addr = "";
    head->name = "";
    head->tel = "";
    head->next = NULL;
    ReadtoFile(head);
    funChoose(head);
    OuttoFile(head);
    delete head;
    return 0;
}

void ReadtoFile(commEntry *&head)
{
    ifstream infile;
    char temp;
    infile.open("commEntry.txt");
    if (infile)
        while (infile.peek() != EOF)
        {
            commEntry *p = new commEntry;
            p->next = head->next;
            getline(infile, p->name);
            getline(infile, p->tel);
            getline(infile, p->addr);
            infile.get(temp);
            head->next = p;
        }
    infile.close();
}

void OuttoFile(commEntry *&head)
{
    commEntry *p = head->next;
    ofstream outfile;
    outfile.open("commEntry.txt");
    while (p)
    {
        outfile << p->name << endl;
        outfile << p->tel << endl;
        outfile << p->addr << endl;
        outfile << endl;
        p = p->next;
    }
    outfile.close();
}

unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "===================" << endl;
    cout << "1.����һ��ͨѶ¼" << endl;
    cout << "2.���ȫ��ͨѶ¼" << endl;
    cout << "3.�޸�����" << endl;
    cout << "4.�޸ĵ绰" << endl;
    cout << "5.�޸ĵ�ַ" << endl;
    cout << "0.�˳�" << endl;
    cout << "===================" << endl;
    cout << "������һ����(0-5)ѡ��";
    cin >> i;
    return i;
}
void funChoose(commEntry *&head)
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
            InputCommEntry(head);
            break;
        case 2: //����2,���ͨѶ¼
            ShowCommEntry(head);
            break;
        case 3: //����3,�޸�����
            //setName(peop);
            break;
        case 4: //����4,�޸ĵ绰
            //setTel(peop);
            break;
        case 5: //����5,�޸ĵ�ַ
            //setAddr(peop);
            break;
        }
    }
}
void InputCommEntry(commEntry *&head)
{
    commEntry *comEp = new commEntry;
    comEp->next = head->next;
    cout << endl;
    cout << "������: " << endl;
    cout << "����: ";
    fflush(stdin);
    getline(cin, comEp->name);
    cout << "�绰����: ";
    getline(cin, comEp->tel);
    cout << "��ַ: ";
    getline(cin, comEp->addr);
    head->next = comEp;
    cout << "һ��ͨѶ¼����ɹ�..." << endl;
}
void ShowCommEntry(commEntry *&head)
{
    if (head->next == NULL)
    {
        cout << "ͨѶ¼��û������..." << endl;
    }
    else
    {
        commEntry *p = head->next;
        cout << setw(14) << left << "����"
             << setw(18) << left << "�绰"
             << "��ַ" << endl;
        while (p)
        {
            cout << setw(14) << left << p->name
                 << setw(18) << left << p->tel
                 << p->addr << endl;
            p = p->next;
        }
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