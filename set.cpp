#include <iostream>
#include <set>
using namespace std;

class MyCompare
{
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};


void test01()
{
    set<int, MyCompare> s1;
    s1.insert(20);
    s1.insert(10);
    s1.insert(30);
    s1.insert(90);
    s1.insert(50);

    for (set<int>::const_iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}
