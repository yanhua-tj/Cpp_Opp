#include "ClassmateEntry.h"
#include <cstdlib>

//using namespace std;

unsigned int displayMenu();         //���˵�����ʾ
void funChoose(ClassmateEntry&);       //�˵�ѡ��
void setClmateName(ClassmateEntry&);      //�޸�ͬѧ��Ŀ������
void setClmateTel(ClassmateEntry&);       //�޸�ͬѧ��Ŀ�ĵ绰
void setClmateSch(ClassmateEntry&);      //�޸�ͬѧ��Ŀ��ѧУ
void setClmateCla(ClassmateEntry&);     //�޸�ͬѧ��Ŀ�İ༶

int main()
{
    cout << left;                   //�����
    ClassmateEntry frentry;
    funChoose(frentry);             //�˵�ѡ��
    return 0;
}

//���˵�����ʾ
unsigned int displayMenu()
{
    unsigned int i;
    cout << endl;
    cout << "===================" << endl;
    cout << "1.����ͬѧ��Ŀ" << endl;
    cout << "2.���ͬѧ��Ŀ" << endl;
    cout << "3.�޸�����" << endl;
    cout << "4.�޸ĵ绰" << endl;
    cout << "5.�޸�ѧУ" << endl;
    cout << "6.�޸İ༶" << endl;
    cout << "0.�˳�" << endl;
    cout << "===================" << endl;
    cout << "������һ����(0-6)ѡ��";
    cin >> i;
    return i;
}

//�˵�ѡ��
void funChoose(ClassmateEntry &a)
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
            cout << "ͬѧ��Ŀд��ɹ�!" << endl;
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
            setClmateName(a);
            break;
        case 4: //����4,�޸ĵ绰
            setClmateTel(a);
            break;
        case 5: //����5,�޸�ѧУ
            setClmateSch(a);
            break;
        case 6: //����6,�޸İ༶
            setClmateCla(a);
            break;
        }
        system("pause");
        system("cls");
    }
}

//�޸�ͬѧ��Ŀ������
void setClmateName(ClassmateEntry& a)
{
    cout << "�޸�����Ϊ: ";
    string temp;
    getline(cin, temp);
    a.setName(temp);
    cout << "�޸ĳɹ�!" << endl;
}

//�޸�ͬѧ��Ŀ�ĵ绰
void setClmateTel(ClassmateEntry& a)
{
    cout << "�޸ĵ绰Ϊ: ";
    string temp;
    getline(cin, temp);
    a.setTel(temp);
    cout << "�޸ĳɹ�!" << endl;
}

//�޸�ͬѧ��Ŀ��ѧУ
void setClmateSch(ClassmateEntry& a)
{
    cout << "�޸�ѧУΪ: ";
    string temp;
    getline(cin, temp);
    a.setSch(temp);
    cout << "�޸ĳɹ�!" << endl;
}

//�޸�ͬѧ��Ŀ�İ༶
void setClmateCla(ClassmateEntry& a)
{
    cout << "�޸İ༶Ϊ: ";
    string temp;
    getline(cin, temp);
    a.setCla(temp);
    cout << "�޸ĳɹ�!" << endl;
}
