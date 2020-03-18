#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    int *a, b = 10;
    a = &b;
    cout << a << ends << sizeof(a) << ends << *a << ends << typeid(a).name() << endl;
    a = new int(35);
    cout << a << ends << sizeof(a) << ends << *a << ends << typeid(a).name() << endl;
    delete a;
    cout << a << ends << sizeof(a) << ends << *a << ends << typeid(a).name() << endl;
    return 0;
}