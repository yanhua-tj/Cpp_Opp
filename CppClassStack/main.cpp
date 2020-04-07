#include <iostream>

using namespace std;

class Stack
{
private:
    int *data;
    int maxsize;
    int top;
    void Init();//��ʼ��ջ
    void errMsg(string str);

public:
    Stack();            //��ʼ��ջĬ�ϴ�С5
    Stack(int n);       //��ʼ��ջ�Զ����С
    ~Stack();           //��������,�ͷſռ�
    bool Push(int num); //��ջ
    bool Pop(int &num); //��ջ
    bool isFull();      //�ж�ջ�Ƿ�Ϊ��
    bool isEmpty();     //�ж�ջ�Ƿ���
    void dump();        //���ջ������
};

Stack ::Stack()
{
    maxsize = 5;
    Init();
}

Stack ::Stack(int n)
{
    maxsize = n;
    Init();
}

Stack ::~Stack()
{
    delete data;
}

void Stack ::Init()
{ //��ʼ��ջ
    top = -1;
    data = new int[maxsize];
}

bool Stack ::isFull()
{ //�ж�ջ�Ƿ���
    return top >= maxsize ? true : false;
}

bool Stack ::isEmpty()
{ //�ж�ջ�Ƿ��
    return top == -1 ? true : false;
}

bool Stack ::Push(int num)
{ //��ջ
    if (isFull())
        return false;
    else
        data[++top] = num;
    return true;
}

bool Stack ::Pop(int &num)
{ //��ջ
    if (isEmpty())
        return false;
    else
        num = data[top--];
    return true;
}

void Stack ::dump()
{ //���ջ������
    for (int i = top; i >= 0; i--)
    {
        cout << "��" << i << "��:" << data[i] << endl;
    }
}

int main()
{
    Stack stack(100);
    cout << "1.��ʼ��ջ" << endl;
    cout << "2.��ջ" << endl;
    cout << "3.��ջ" << endl;
    cout << "4.��ʾջ������" << endl;
    cout << "0.�˳�����" << endl;
    system("pause");
    return 0;
}
