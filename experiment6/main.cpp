#include "CommEntry.h"
#include <cstdlib>

//using namespace std;

unsigned int displayMenu();
void funChoose(CommEntry&);

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

void funChoose(CommEntry& comE)
{
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
        cin.ignore(16, '\n');
        switch (ichoose)
        {
        case 0: //����0,��������
            break;
        case 1: //����1,����ͨѶ¼
            cin >> comE;
            break;
        case 2: //����2,���ͨѶ¼
            cout << comE;
            break;
        case 3: //����3,�޸�����
            cout << "\n�޸�����Ϊ: ";
            getline(cin, str);
            comE.setName(str);
            break;
        case 4: //����4,�޸ĵ绰
            cout << "\n�޸ĵ绰Ϊ: ";
            getline(cin, str);
            comE.setTel(str);
            break;
        case 5: //����5,�޸ĵ�ַ
            cout << "\n�޸ĵ�ַΪ: ";
            getline(cin, str);
            comE.setAddr(str);
            break;
        }
        system("pause");
        system("cls");
    }
}

int main()
{
    CommEntry comE;
    funChoose(comE);
    return 0;
}
