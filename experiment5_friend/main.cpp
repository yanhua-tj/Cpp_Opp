#include "FriendEntry.h"
#include <cstdlib>

//using namespace std;

unsigned int displayMenu();         //���˵�����ʾ
void funChoose(FriendEntry&);       //�˵�ѡ��
void setFriName(FriendEntry&);      //�޸�������Ŀ������
void setFriTel(FriendEntry&);       //�޸�������Ŀ�ĵ绰
void setFriAddr(FriendEntry&);      //�޸�������Ŀ�ĵ�ַ
void setFriEmail(FriendEntry&);     //�޸�������Ŀ������

int main()
{
    cout << left;                   //�����
    FriendEntry frentry;
    funChoose(frentry);             //�˵�ѡ��
    return 0;
}

//���˵�����ʾ
unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "===================" << endl;
    cout << "1.����������Ŀ" << endl;
    cout << "2.���������Ŀ" << endl;
    cout << "3.�޸�����" << endl;
    cout << "4.�޸ĵ绰" << endl;
    cout << "5.�޸ĵ�ַ" << endl;
    cout << "6.�޸�����" << endl;
    cout << "0.�˳�" << endl;
    cout << "===================" << endl;
    cout << "������һ����(0-6)ѡ��";
    cin >> i;
    return i;
}

//�˵�ѡ��
void funChoose(FriendEntry &a)
{
    string str;
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
            a.CommEntry::input();       //ͨѶ¼��Ŀ����
            a.input();
            cout << "������Ŀд��ɹ�!" << endl;
            break;
        case 2: //����2,���ͨѶ¼
            a.CommEntry::outputHead();
            a.outputHead();                 //�������
            cout << endl;
            a.CommEntry::output();
            a.output();                     //�����Ϣ
            cout << endl;
            break;
        case 3: //����3,�޸�����
            setFriName(a);
            break;
        case 4: //����4,�޸ĵ绰
            setFriTel(a);
            break;
        case 5: //����5,�޸ĵ�ַ
            setFriAddr(a);
            break;
        case 6: //����6,�޸�����
            setFriEmail(a);
            break;
        }
        system("pause");
        system("cls");
    }
}

//�޸�������Ŀ������
void setFriName(FriendEntry& a)
{
    cout << "�޸�����Ϊ: ";
    string temp;
    getline(cin, temp);
    a.setName(temp);
    cout << "�޸ĳɹ�!" << endl;
}

//�޸�������Ŀ�ĵ绰
void setFriTel(FriendEntry& a)
{
    cout << "�޸ĵ绰Ϊ: ";
    string temp;
    getline(cin, temp);
    a.setTel(temp);
    cout << "�޸ĳɹ�!" << endl;
}

//�޸�������Ŀ�ĵ�ַ
void setFriAddr(FriendEntry& a)
{
    cout << "�޸ĵ�ַΪ: ";
    string temp;
    getline(cin, temp);
    a.setAddr(temp);
    cout << "�޸ĳɹ�!" << endl;
}

//�޸�������Ŀ������
void setFriEmail(FriendEntry& a)
{
    cout << "�޸�����Ϊ: ";
    string temp;
    getline(cin, temp);
    a.setEmail(temp);
    cout << "�޸ĳɹ�!" << endl;
}
