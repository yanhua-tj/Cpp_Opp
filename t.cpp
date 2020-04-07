#include <iostream>
#include <string>
using namespace std;
class CMyclass
{
public:
    CMyclass()
    {
        cout << "构造函数" << endl;
        cin >> name;
    }
    CMyclass(CMyclass &a)
    {
        cout << "复制构造函数  " << endl;
        cin >> name;
    }
    ~CMyclass()
    {
        cout << "析构函数  " << name << endl;
    }
private:
    string name;
};

CMyclass fun(CMyclass sobj)
{
    cout << "fun 函数" << endl;
    sobj;
    return sobj; //函数调用返回时生成临时对象返回
}
int main()
{
    CMyclass obj;
    fun(obj); //函数调用的返回值（临时对象）被用过后，该临时对象析构函数被调用
    return 0;
}
