#include <iostream>
using namespace std;
int g_a, g_b;                   //ȫ�ֱ���
const int c_g_a = 1, c_g_b = 2; //constȫ�ֱ���

int main()
{
    int a, b;            //�ֲ�����
    static int s_a, s_b; //��̬����
    cout << "�ֲ�����a�ĵ�ַ��" << (long long)&a << endl;
    cout << "�ֲ�����b�ĵ�ַ��" << (long long)&b << endl;

    cout << "ȫ�ֱ���g_a�ĵ�ַ��" << (long long)&g_a << endl;
    cout << "ȫ�ֱ���g_b�ĵ�ַ��" << (long long)&g_b << endl;

    cout << "��̬����s_a�ĵ�ַ��" << (long long)&s_a << endl;
    cout << "��̬����s_b�ĵ�ַ��" << (long long)&s_b << endl;
    //�ַ�������
    cout << "�ַ���������hello���ĵ�ַ��" << (long long)&"hello" << endl;
    cout << "�ַ���������world���ĵ�ַ��" << (long long)&"world" << endl;

    //constȫ�ֱ���
    cout << "constȫ�ֱ���c_a�ĵ�ַ��" << (long long)&c_g_a << endl;
    cout << "constȫ�ֱ���c_b�ĵ�ַ��" << (long long)&c_g_b << endl;

    //const�ֲ�����
    const int c_a = 1, c_b = 2;
    cout << "const�ֲ�����c_a�ĵ�ַ��" << (long long)&c_a << endl;
    cout << "const�ֲ�����c_b�ĵ�ַ��" << (long long)&c_b << endl;

    system("pause");
    return 0;
}