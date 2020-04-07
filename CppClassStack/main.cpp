#include <iostream>

using namespace std;

class Stack
{
private:
    int *data;
    int maxsize;
    int top;
    void Init();//初始化栈
    void errMsg(string str);

public:
    Stack();            //初始化栈默认大小5
    Stack(int n);       //初始化栈自定义大小
    ~Stack();           //析构函数,释放空间
    bool Push(int num); //入栈
    bool Pop(int &num); //出栈
    bool isFull();      //判断栈是否为空
    bool isEmpty();     //判断栈是否满
    void dump();        //输出栈的内容
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
{ //初始化栈
    top = -1;
    data = new int[maxsize];
}

bool Stack ::isFull()
{ //判断栈是否满
    return top >= maxsize ? true : false;
}

bool Stack ::isEmpty()
{ //判断栈是否空
    return top == -1 ? true : false;
}

bool Stack ::Push(int num)
{ //入栈
    if (isFull())
        return false;
    else
        data[++top] = num;
    return true;
}

bool Stack ::Pop(int &num)
{ //出栈
    if (isEmpty())
        return false;
    else
        num = data[top--];
    return true;
}

void Stack ::dump()
{ //输出栈的内容
    for (int i = top; i >= 0; i--)
    {
        cout << "第" << i << "层:" << data[i] << endl;
    }
}

int main()
{
    Stack stack(100);
    cout << "1.初始化栈" << endl;
    cout << "2.进栈" << endl;
    cout << "3.出栈" << endl;
    cout << "4.显示栈的内容" << endl;
    cout << "0.退出程序" << endl;
    system("pause");
    return 0;
}
