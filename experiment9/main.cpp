#include "CommEntry.h"
#include "Comms.h"
#include <cstdlib>
#define FileName "record.txt"

//using namespace std;

unsigned int displayMenu();             //���˵�����ʾ
void funChoose(Comms*);                 //�˵�ѡ��
Comms* InitComms();                     //ͨѶ¼��ʼ��
void FindName(Comms*);                  //��������
void FindTel(Comms* p);                 //���ҵ绰
void Namemodify(Comms*);                //���������޸ĵ绰
void Telmodify(Comms*);                 //����绰�޸�����
void Fuzzysearch(Comms*);               //ģ������

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
    cout << "4.���ҵ绰" << endl;
    cout << "5.���������޸���绰" << endl;
    cout << "6.����绰�޸�������" << endl;
    cout << "7.ģ������" << endl;
    cout << "8.���ļ��ж�����" << endl;
    cout << "9.�������ݵ��ļ�" << endl;
    cout << "0.�����˳�" << endl;
    cout << "=======================" << endl;
    cout << "������һ����(0-9)ѡ��";
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
        while (ichoose > 9)
        {
            cout << "����������ڷ�Χ�ڣ�" << endl;
            system("pause");
            system("cls");
            ichoose = displayMenu();
        }
        cin.ignore(16, '\n');           //��ջ�����
        switch (ichoose)
        {
        case 0: //����0,�������򲢱���
        {
            ofstream outfile(FileName);
            p->outputToFile(outfile);
            outfile.close();
            break;
        }
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
        case 4: //����4,���ҵ绰
            FindTel(p);
            break;
        case 5: //����5,���������޸���绰
            Namemodify(p);
            break;
        case 6: //����6,����绰�޸�������
            Telmodify(p);
            break;
        case 7: //����7,ģ������
            Fuzzysearch(p);
            break;
        case 8: //8.���ļ��ж�����
        {
            ifstream infile(FileName);
            if (!infile.is_open())
            {
                cout << "�ļ���ʧ��! �����ļ��Ƿ����" << endl;
                break;
            }
            p->inputFromFile(infile);
            infile.close();
            break;
        }
        case 9: //9.�������ݵ��ļ�
        {
            ofstream outfile(FileName);
            p->outputToFile(outfile);
            outfile.close();
            break;
        }
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
    index = p->findname(name);
    if (index == -1)
    {
        cout << "���޴���! " << endl;
    }
    else
    {
        cout << "������ͨѶ¼��" << index + 1 << "��" << endl;
    }
}

//���ҵ绰
void FindTel(Comms* p)
{
    string tel;
    int index = 0;
    cout << "����Ҫ��������: ";
    cin >> tel;
    index = p->findtel(tel);
    if (index == -1)
    {
        cout << "�����ڴ˵绰! " << endl;
    }
    else
    {
        cout << "�˵绰��ͨѶ¼��" << index + 1 << "��" << endl;
    }
}

//���������޸ĵ绰
void Namemodify(Comms* p)
{
    string name, tel;
    int index = 0;
    cout << "����Ҫ��������: ";
    cin >> name;
    index = p->findname(name);
    if (index == -1)
    {
        cout << "���޴���! " << endl;
    }
    else
    {
        cout << "�绰�޸�Ϊ: ";
        cin >> tel;
        p->modifytel(name, tel);
    }
}

//����绰�޸�����
void Telmodify(Comms* p)
{
    string name, tel;
    int index = 0;
    cout << "����Ҫ���ҵ绰: ";
    cin >> tel;
    index = p->findtel(tel);
    if (index == -1)
    {
        cout << "���޴˵绰! " << endl;
    }
    else
    {
        cout << "�����޸�Ϊ: ";
        cin >> name;
        p->modifyname(tel, name);
    }
}

//ģ������
void Fuzzysearch(Comms* p)
{
    int choice = 0;
    cout << "0.������һ��" << endl;
    cout << "1.����ģ������" << endl;
    cout << "2.�绰ģ������" << endl;
    cout << "����һ����ѡ����(0-2): ";
    cin >> choice;
    cin.ignore(16, '\n');
    switch (choice)
    {
    case 0:
        break;
    case 1:
    {
        string name;
        cout << "����ģ�����������ؼ���: ";
        cin >> name;
        p->fuzzysearchname(name);
        break;
    }
    case 2:
    {
        string tel;
        cout << "����ģ�����ҵ绰�ؼ���: ";
        cin >> tel;
        p->fuzzysearchtel(tel);
        break;
    }
    default:
        cout << "��������" << endl;
        break;
    }
}