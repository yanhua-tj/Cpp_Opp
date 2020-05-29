#include <iostream>
using namespace std;

class Base
{
public:
    virtual void fun1() { cout << "Base::fun1()" << endl; }
    virtual ~Base() {}
};

class Derived1 : public Base
{
public:
    virtual void fun1() { cout << "Derived1::fun1()" << endl; }
    virtual void fun2() { cout << "Derived1::fun2()" << endl; }
};

class Derived2 : public Derived1
{
public:
    virtual void fun1() { cout << "Derived2::fun1()" << endl; }
    virtual void fun2() { cout << "Derived2::fun2()" << endl; }
};

void fun(Base *b)
{
    b->fun1();
    //尝试将Base类型的指针转换为Derived1类型指针
    Derived1 *p = dynamic_cast<Derived1 *>(b);
    //判断转换是否成功
    if (p)
    {
        p->fun2();
    }
}

int main()
{
    Base a;
    fun(&a);    //本身是基类,不能转换为派生类指针类型
    Derived1 b;
    fun(&b);    //本身是派生类,形参传递的时候转成了基类指针,可以转回
    Derived2 c;
    fun(&c);    //本身是派生类,形参传递转成了基类指针,可以变成其父类指针
    system("pause");
    return 0;
}