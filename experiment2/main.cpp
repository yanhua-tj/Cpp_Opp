#include "CommEntry.h"

//using namespace std;

unsigned int displayMenu();
void funChoose();

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

void funChoose()
{
    CommEntry comE;
    string str;
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
            comE.input();
            break;
        case 2: //����2,���ͨѶ¼
            comE.output();
            break;
        case 3: //����3,�޸�����
            cout << "\n�޸�����Ϊ: ";
            fflush(stdin);
            getline(cin, str);
            comE.setName(str);
            break;
        case 4: //����4,�޸ĵ绰
            cout << "\n�޸ĵ绰Ϊ: ";
            fflush(stdin);
            getline(cin, str);
            comE.setTel(str);
            break;
        case 5: //����5,�޸ĵ�ַ
            cout << "\n�޸ĵ�ַΪ: ";
            fflush(stdin);
            getline(cin, str);
            comE.setAddr(str);
            break;
        }
    }
}

int main()
{
    funChoose();
    return 0;
}
