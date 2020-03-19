//函数重载
#include <iostream>
using namespace std;
void print(int a)
{
    cout << a;
}
void print(double b)
{
    cout << b;
}
int main()
{
    int a;
    cin >> a;
    print(a);
    double b;
    cin >> b;
    print(b);
    system("pause");
    return 0;
}