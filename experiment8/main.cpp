#include "CommEntry.h"
#include "FriendEntry.h"
#include "Comms.h"
#include <cstdlib>

//using namespace std;

unsigned int displayMenu();         //���˵�����ʾ
void funChoose(Comms*);             //�˵�ѡ��
Comms* InitComms();                 //ͨѶ¼��ʼ��
void FindName(Comms*);              //��������
void Nametotel(Comms*);             //���������޸ĵ绰

int main()
{
    cout << left;                   //�����
    Comms* p = InitComms();         //��ʼ��
    funChoose(p);                   //�˵�ѡ��
    return 0;
}

//ͨѶ¼��ʼ��
Comms* InitComms()
{
    Comms* p;
    char a;
    cout << "ͨѶ¼Ĭ�ϴ�СΪ10, �Ƿ�(y/n)�Զ������?" << endl;
    cin.get(a);
    if (a == 'Y' || a == 'y')
    {
        cout << "�����Զ����С: " << endl;
        unsigned num = 0;
        cin >> num;
        p = new Comms(num);
    }
    else
    {
        p = new Comms();
    }
    return p;
}

//���˵�����ʾ
unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "=======================" << endl;
    cout << "1.����ͨѶ¼" << endl;
    cout << "2.���ͨѶ¼" << endl;
    cout << "3.��������" << endl;
    cout << "4.���������޸���绰" << endl;
    cout << "5.��ʾһ����Ŀ" << endl;
    cout << "6.��ʾ������Ŀ" << endl;
    cout << "0.�˳�" << endl;
    cout << "=======================" << endl;
    cout << "������һ����(0-6)ѡ��";
    cin >> i;
    return i;
}

////�˵�ѡ��
void funChoose(Comms* p)
{
    unsigned int ichoose = 1;
    while (ichoose != 0)
    {
        ichoose = displayMenu();        //�������˵�����
        while (ichoose > 6)
        {
            cout << "����������ڷ�Χ�ڣ�" << endl;
            system("pause");
            system("cls");
            ichoose = displayMenu();
        }
        cin.ignore(16, '\n');           //��ջ�����
        switch (ichoose)
        {
        case 0: //����0,��������
            break;
        case 1: //����1,����ͨѶ¼
            cout << endl;
            p->input();
            cout << "ͨѶ¼д��ɹ�!" << endl;
            break;
        case 2: //����2,���ͨѶ¼
            p->outputAll();                             //�����Ϣ
            break;
        case 3: //����3,��������
            FindName(p);
            break;
        case 4: //����4,���������޸���绰
            Nametotel(p);
            break;
        case 5: //��ʾһ����Ŀ
            p->outputCom();
            break;
        case 6: //��ʾ������Ŀ
            p->outputFri();
            break;
        }
        system("pause");
        system("cls");
    }
}

//��������
void FindName(Comms* p)
{
    string name;
    int index = 0;
    cout << "����Ҫ��������: ";
    cin >> name;
    index = p->find(name);
    if (index == -1)
    {
        cout << "���޴���! " << endl;
    }
    else
    {
        cout << "������ͨѶ¼��" << index + 1 << "��" << endl;
    }
}

//���������޸ĵ绰
void Nametotel(Comms* p)
{
    string name, tel;
    int index = 0;
    cout << "����Ҫ��������: ";
    cin >> name;
    index = p->find(name);
    if (index == -1)
    {
        cout << "���޴���! " << endl;
    }
    else
    {
        cout << "�绰�޸�Ϊ: ";
        cin >> tel;
        p->modify(name, tel);
    }
}
