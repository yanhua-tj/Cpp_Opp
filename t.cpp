#include <iostream>
#include <string>
using namespace std;
class CMyclass
{
public:
    CMyclass()
    {
        cout << "���캯��" << endl;
        cin >> name;
    }
    CMyclass(CMyclass &a)
    {
        cout << "���ƹ��캯��  " << endl;
        cin >> name;
    }
    ~CMyclass()
    {
        cout << "��������  " << name << endl;
    }
private:
    string name;
};

CMyclass fun(CMyclass sobj)
{
    cout << "fun ����" << endl;
    sobj;
    return sobj; //�������÷���ʱ������ʱ���󷵻�
}
int main()
{
    CMyclass obj;
    fun(obj); //�������õķ���ֵ����ʱ���󣩱��ù��󣬸���ʱ������������������
    return 0;
}
