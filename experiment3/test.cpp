#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

class CommEntry
{
private:
    string name;       //����
    unsigned telCount; //�绰�ĸ���
    string *tels;      //�绰
    string *telType;   //�绰����
    string addr;       //��ַ

public:
    CommEntry(unsigned num = 3);            //���캯����ʼ��
    ~CommEntry();                           //���������ͷ��ڴ�
    void input();                           //����ͨѶ¼��Ŀ
    void output();                          //���ͨѶ¼��Ŀ
    void setName(string nm);                //��������
    void setTel(string t, int iNum);        //���õ绰
    void setTelType(string type, int iNum); //���õ绰
    void setAddr(string ad);                //���õ�ַ
    string getName();                       //��ȡ����
    string getTel(int iNum);                //��ȡ�绰
    string getTelType(int iNum);            //��ȡ�绰
    string getAddr();                       //��ȡ��ַ
    bool iNumINtelCo(int iNum);             //�ж�Ҫ�޸ĵ��Ƿ��ڷ�Χ��
};

unsigned int displayMenu();
void funChoose();
void setName(CommEntry &comE);
void setTel(CommEntry &comE);
void setTelType(CommEntry &comE);
void setAddr(CommEntry &comE);
CommEntry *Init();

CommEntry ::CommEntry(unsigned num)
{
    telCount = num;
    tels = new string[telCount];
    telType = new string[telCount];
}

CommEntry ::~CommEntry()
{
    delete[] tels;
    delete[] telType;
}

bool CommEntry ::iNumINtelCo(int iNum)
{
    if (iNum > telCount || iNum <= 0)
        return false;
    else
        return true;
}

string CommEntry ::getName()
{
    return name;
}

string CommEntry ::getTel(int iNum)
{
    return tels[iNum];
}

string CommEntry ::getTelType(int iNum)
{ //��ȡ�绰����
    return telType[iNum];
}

string CommEntry ::getAddr()
{
    return addr;
}

void CommEntry ::setName(string nm)
{
    name = nm;
}

void CommEntry ::setTel(string t, int iNum)
{
    tels[iNum] = t;
}

void CommEntry ::setTelType(string type, int iNum)
{ //���õ绰����
    telType[iNum] = type;
}

void CommEntry ::setAddr(string ad)
{
    addr = ad;
}

void CommEntry ::input()
{ //����ͨѶ¼
    string temp;
    cout << "\n������" << endl;

    cout << "����: ";
    fflush(stdin);
    getline(cin, temp);
    setName(temp);

    for (int i = 0; i < telCount; i++)
    {
        cout << "��" << i + 1 << "���绰: ";
        fflush(stdin);
        getline(cin, temp);
        setTel(temp, i);
        cout << "�绰����: ";
        fflush(stdin);
        getline(cin, temp);
        setTelType(temp, i);
    }

    cout << "��ַ: ";
    fflush(stdin);
    getline(cin, temp);
    setAddr(temp);
}

void CommEntry ::output()
{ //���ͨѶ¼
    cout << setw(14) << left << "����";
    for (int i = 0; i < telCount; i++)
        cout << setw(18) << left << telType[i];
    cout << "��ַ" << endl;

    cout << setw(14) << left << name;
    for (int i = 0; i < telCount; i++)
        cout << setw(18) << left << tels[i];
    cout << addr << endl;
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
    cout << "5.�޸ĵ绰����" << endl;
    cout << "6.�޸ĵ�ַ" << endl;
    cout << "0.�˳�" << endl;
    cout << "===================" << endl;
    cout << "������һ����(0-6)ѡ��";
    cin >> i;
    return i;
}

void funChoose()
{ //ѡ����
    unsigned int ichoose = 1;
    CommEntry *comE = NULL;
    char t;
    while (ichoose != 0)
    {
        ichoose = displayMenu(); //�˵�ѡ��
        while (ichoose > 6)
        {
            cout << "����������ڷ�Χ�ڣ�" << endl;
            ichoose = displayMenu();
        }
        fflush(stdin); //��ջ�����
        if (comE == NULL && ichoose != 1 && ichoose != 0)
            cout << "û��ͨѶ¼" << endl;
        else
            switch (ichoose)
            {
            case 0: //����0,��������
                break;
            case 1: //����1,����ͨѶ¼
                cout << "�Ƿ��Զ���绰����(Ĭ��Ϊ3)?(y/n)";
                cin >> t;
                if (t == 'y' || t == 'Y')
                    comE = Init();
                else
                    comE = new CommEntry();
                comE->input();
                break;
            case 2: //����2,���ͨѶ¼
                comE->output();
                break;
            case 3: //����3,�޸�����
                setName(*comE);
                break;
            case 4: //����4,�޸ĵ绰
                setTel(*comE);
                break;
            case 5: //����5,�޸ĵ绰����
                setTelType(*comE);
                break;
            case 6: //����6,�޸ĵ�ַ
                setAddr(*comE);
                break;
            }
    }
    delete comE;
}

void setName(CommEntry &comE)
{ //�޸�����
    string str;
    cout << "\n�޸�����Ϊ: ";
    getline(cin, str);
    comE.setName(str);
}

void setTel(CommEntry &comE)
{ //�޸ĵ绰
    string str;
    int iNum;
    comE.output();
    cout << "�޸ĵڼ����绰��";
    cin >> iNum;
    if (comE.iNumINtelCo(iNum) == false)
    {
        cout << "�����ڸõ绰, �����޸�";
        return;
    }
    else
    {
        cout << "\n�޸ĵ绰Ϊ: ";
        fflush(stdin);
        getline(cin, str);
        comE.setTel(str, iNum - 1);
    }
}

void setTelType(CommEntry &comE)
{ //�޸ĵ绰����
    string str;
    int iNum;
    comE.output();
    cout << "�޸ĵڼ����绰���ͣ�";
    cin >> iNum;
    if (comE.iNumINtelCo(iNum) == false)
    {
        cout << "�����ڸõ绰����, �����޸�";
        return;
    }
    else
    {
        cout << "\n�޸ĵ绰����Ϊ: ";
        fflush(stdin);
        getline(cin, str);
        comE.setTelType(str, iNum - 1);
    }
}

void setAddr(CommEntry &comE)
{ //�޸ĵ�ַ
    string str;
    cout << "\n�޸ĵ�ַΪ: ";
    getline(cin, str);
    comE.setAddr(str);
}

CommEntry *Init()
{
    CommEntry *comE;
    unsigned int num;
    cout << "����绰����: " << endl;
    cin >> num;
    comE = new CommEntry(num);
    return comE;
}

int main()
{
    funChoose();
    system("pause");
    return 0;
}