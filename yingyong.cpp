#include <iostream>
using namespace std;
int &changevalue()
{
    static int a_return = 666;
    return a_return;
}

int main()
{
    int &a = changevalue();
    cout << a << endl;
    a = 20;
    cout << changevalue() << endl;
    system("pause");
    return 0;
}