/*
 * @Author: yanhua 
 * @Date: 2020-03-17 20:30:53 
 * @Last Modified by: yanhua
 * @Last Modified time: 2020-03-19 20:42:23
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <fstream>
using namespace std;

struct commEntry
{
    unsigned int id;
    string name;
    string tel;
    string addr;
    commEntry *next;
};
struct Addrebook
{
    unsigned int num;
    commEntry *head;
};

unsigned int displayMenu();                              //���˵���ʾ
void funChoose(Addrebook &AddBook);                      //���˵�����ѡ��
commEntry *InputCommEntry();                             //����һ��ͨѶ¼
void ShowCommEntry(commEntry *&head);                    //��ʾ���е�ͨѶ¼
void setCommEntry(commEntry *&head);                     //�����޸�ͨѶ¼������,�绰,��ַ
commEntry *Foundid(commEntry *&head, unsigned sel);      //��ͨѶ¼�����в��ҷ��ϱ�ŵ���Ŀ,���ص�ǰ
commEntry *FoundidBefor(commEntry *&head, unsigned sel); //��ͨѶ¼�����в��ҷ��ϱ�ŵ���Ŀ,����ǰ��
void setName(commEntry *p);                              //�޸�ͨѶ¼��Ŀ������
void setTel(commEntry *p);                               //�޸�ͨѶ¼��Ŀ�ĵ绰
void setAddr(commEntry *p);                              //�޸�ͨѶ¼��Ŀ�ĵ�ַ
void OuttoFile(commEntry *&head);                        //���ڴ��е�ͨѶ¼д���ļ���
void ReadtoFile(Addrebook &AddBook);                     //���ļ��ж�ȡͨѶ¼���ڴ�
void Init(Addrebook &AddBook);                           //��ʼ��ͨѶ¼�ṹ
void DeleteSpace(commEntry *&head);                      //�ͷ�new���ɵ�����ռ�
void ShowOneCom(commEntry *p);                           //��ʾһ��ͨѶ¼��Ŀ
void InsertCom(Addrebook &AddBook);                      //����һ��ͨѶ¼
void DeleteCom(Addrebook &AddBook);                      //ɾ��һ��ͨѶ¼
void NameToTEL(commEntry *head);                         //�����������ҵ绰

int main()
{
    Addrebook AddBook;
    Init(AddBook);
    ReadtoFile(AddBook);
    funChoose(AddBook);
    OuttoFile(AddBook.head);
    DeleteSpace(AddBook.head);
    return 0;
}

void DeleteSpace(commEntry *&head)
{ //�ͷ�new���ɵ�����ռ�
    commEntry *p = head, *q;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
}

void Init(Addrebook &AddBook)
{ //��ʼ��ͨѶ¼�ṹ
    AddBook.num = 0;
    AddBook.head = new commEntry;
    AddBook.head->next = NULL;
}

void ReadtoFile(Addrebook &AddBook)
{ //���ļ��ж�ȡͨѶ¼���ڴ�
    ifstream infile;
    char temp;
    infile.open("commEntry.txt");
    if (infile)
        while (infile.peek() != EOF)
        {
            commEntry *p = new commEntry;
            p->next = AddBook.head->next;
            getline(infile, p->name);
            getline(infile, p->tel);
            getline(infile, p->addr);
            AddBook.num++;
            p->id = AddBook.num;
            infile.get(temp);
            AddBook.head->next = p;
        }
    infile.close();
}

void OuttoFile(commEntry *&head)
{ //���ڴ��е�ͨѶ¼д���ļ���
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
{ //���˵���ʾ
    unsigned int i;
    cout << endl;
    cout << "=========================" << endl;
    cout << "1.����һ��ͨѶ¼" << endl;
    cout << "2.���ȫ��ͨѶ¼" << endl;
    cout << "3.�޸�һ��ͨѶ¼" << endl;
    cout << "4.����һ��ͨѶ¼" << endl;
    cout << "5.ɾ��һ��ͨѶ¼" << endl;
    cout << "6.�����������ҵ绰" << endl;
    cout << "0.�˳�������" << endl;
    cout << "=========================" << endl;
    cout << "������һ����(0-6)ѡ��";
    cin >> i;
    return i;
}

void funChoose(Addrebook &AddBook)
{ //���˵�����ѡ��
    unsigned int ichoose = 1;
    commEntry *p;
    while (ichoose != 0)
    {
        ichoose = displayMenu();
        while (ichoose > 6)
        {
            cout << "����������ڷ�Χ�ڣ���������" << endl;
            ichoose = displayMenu();
        }
        switch (ichoose)
        {
        case 0: //����0,��������
            break;
        case 1: //����1,����ͨѶ¼
            p = InputCommEntry();
            p->next = AddBook.head->next;
            AddBook.head->next = p;
            AddBook.num++;
            p->id = AddBook.num;
            break;
        case 2: //����2,���ͨѶ¼
            ShowCommEntry(AddBook.head);
            break;
        case 3: //����3,�޸�һ��ͨѶ¼
            setCommEntry(AddBook.head);
            break;
        case 4: //����4,����һ��ͨѶ¼
            InsertCom(AddBook);
            break;
        case 5: //����5,ɾ��һ��ͨѶ¼
            DeleteCom(AddBook);
            break;
        case 6: //����6,�����������ҵ绰
            NameToTEL(AddBook.head);
            break;
        }
    }
}

commEntry *InputCommEntry()
{ //����һ��ͨѶ¼
    commEntry *comEp = new commEntry;
    cout << endl;
    cout << "������: " << endl;
    cout << "����: ";
    fflush(stdin);
    getline(cin, comEp->name);
    cout << "�绰����: ";
    getline(cin, comEp->tel);
    cout << "��ַ: ";
    getline(cin, comEp->addr);
    cout << "һ��ͨѶ¼����ɹ�..." << endl;
    return comEp;
}

void ShowCommEntry(commEntry *&head)
{ //��ʾ���е�ͨѶ¼
    if (head->next == NULL)
    {
        cout << "ͨѶ¼��û������..." << endl;
    }
    else
    {
        commEntry *p = head->next;
        cout << setw(6) << left << "���"
             << setw(14) << left << "����"
             << setw(18) << left << "�绰"
             << "��ַ" << endl;
        while (p)
        {
            cout << setfill('0') << setw(4) << right << p->id << "  ";
            cout << setfill(' ');
            cout << setw(14) << left << p->name
                 << setw(18) << left << p->tel
                 << p->addr << endl;
            p = p->next;
        }
    }
}

void setCommEntry(commEntry *&head)
{ //�����޸�ͨѶ¼������,�绰,��ַ
    unsigned sel, ichoose = 1;
    commEntry *p;
    cout << endl;
    cout << "1.�޸�����" << endl;
    cout << "2.�޸ĵ绰" << endl;
    cout << "3.�޸ĵ�ַ" << endl;
    cout << "0.������һ��" << endl;
    cout << "��ѡ����(0-3): " << endl;
    cin >> ichoose;
    while (ichoose > 3)
    {
        cout << "����������ڷ�Χ�ڣ���������" << endl;
        cin >> ichoose;
    }
    if (ichoose != 0)
    {
        cout << "����Ҫ�޸ĵ�ͨѶ¼���" << endl;
        cin >> sel;
        p = Foundid(head, sel);
        if (p != NULL)
        {
            switch (ichoose)
            {
            case 1:
                setName(p);
                break;
            case 2:
                setTel(p);
                break;
            case 3:
                setAddr(p);
                break;
            }
        }
        else
            cout << "û�������ŵ�ͨѶ¼" << endl;
    }
}

commEntry *Foundid(commEntry *&head, unsigned sel)
{ //��ͨѶ¼�����в��ҷ��ϱ�ŵ���Ŀ,���ص�ǰ
    commEntry *p = head->next;
    while (p)
    {
        if (p->id == sel)
            break;
        p = p->next;
    }
    return p;
}

commEntry *FoundidBefor(commEntry *&head, unsigned sel)
{ //��ͨѶ¼�����в��ҷ��ϱ�ŵ���Ŀ,����ǰ��
    commEntry *p = head;
    while (p->next)
    {
        if (p->next->id == sel)
            break;
        p = p->next;
    }
    return p;
}

void ShowOneCom(commEntry *p)
{ //��ʾһ��ͨѶ¼��Ŀ
    cout << endl;
    cout << setw(6) << left << "���"
         << setw(14) << left << "����"
         << setw(18) << left << "�绰"
         << "��ַ" << endl;
    cout << setfill('0') << setw(4) << right << p->id << "  ";
    cout << setfill(' ');
    cout << setw(14) << left << p->name
         << setw(18) << left << p->tel
         << p->addr << endl;
}

void setName(commEntry *p)
{ //�޸�ͨѶ¼��Ŀ������
    ShowOneCom(p);
    cout << endl;
    cout << "�������޸�Ϊ: ";
    fflush(stdin);
    cin >> p->name;
    cout << "�����޸ĳɹ�" << endl;
    ShowOneCom(p);
}
void setTel(commEntry *p)
{ //�޸�ͨѶ¼��Ŀ�ĵ绰
    ShowOneCom(p);
    cout << endl;
    cout << "���绰�޸�Ϊ: ";
    fflush(stdin);
    cin >> p->tel;
    cout << "�绰�޸ĳɹ�" << endl;
    ShowOneCom(p);
}
void setAddr(commEntry *p)
{ //�޸�ͨѶ¼��Ŀ�ĵ�ַ
    ShowOneCom(p);
    cout << endl;
    cout << "����ַ�޸�Ϊ: ";
    fflush(stdin);
    cin >> p->addr;
    cout << "��ַ�޸ĳɹ�" << endl;
    ShowOneCom(p);
}

void InsertCom(Addrebook &AddBook)
{ //����һ��ͨѶ¼
    unsigned sel;
    commEntry *p, *q;
    cout << endl;
    cout << "����ͨѶ¼��ָ����ź�" << endl;
    cout << "���������ı��" << endl;
    cin >> sel;
    p = Foundid(AddBook.head, sel);
    if (p == NULL)
    {
        cout << "Ҫ����ı�Ų�����" << endl;
    }
    else
    {
        q = InputCommEntry();
        q->next = p->next;
        p->next = q;
        AddBook.num++;
        q->id = AddBook.num;
    }
}
void DeleteCom(Addrebook &AddBook)
{ //ɾ��һ��ͨѶ¼
    commEntry *p, *q;
    unsigned sel;
    cout << endl;
    cout << "������Ҫɾ����ͨѶ¼���" << endl;
    cin >> sel;
    p = FoundidBefor(AddBook.head, sel);
    if (p == NULL)
        cout << "Ҫɾ���ı�Ų�����" << endl;
    else
    {
        q = p->next;
        p->next = q->next;
        delete q;
        cout << "һ��ͨѶ¼ɾ���ɹ�" << endl;
    }
}
void NameToTEL(commEntry *head)
{ //�����������ҵ绰
    commEntry *p = head->next;
    string name;
    int count = 0;
    cout << "����������" << endl;
    fflush(stdin);
    getline(cin, name);
    while (p)
    {
        if (name.compare(p->name) == 0)
        {
            cout << name << " �ĵ绰: " << p->tel << endl;
            count++;
        }
        p = p->next;
    }
    if (count == 0)
        cout << "û�� \"" << name << "\" �绰" << endl;
    else
        cout << name << " һ����: " << count << "���绰" << endl;
}