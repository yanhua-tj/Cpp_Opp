#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "\t\"Name\\Address\n";
    cout << str << endl;
    cout << str.size() << endl;
    system("pause");
    return 0;
}