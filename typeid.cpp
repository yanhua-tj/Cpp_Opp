#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
public:
	virtual void out()
	{
		cout << "Base" << endl;
	}
private:
    int m_a;
};

class Derived : public Base
{
public:
	void out()
	{
		cout << "Derived" << endl;
	}
private:
    int m_b;
};

void fun(Base *b)
{
	b->out();
    const type_info &info1 = typeid(b);
    const type_info &info2 = typeid(*b);
    cout << "typeid(b): " << info1.name() << endl;
    cout << "typeid(*b): " << info2.name() << endl;
    if(info2 == typeid(Base))
        cout << "A Bass class" << endl;
}

int main()
{
    Base b;
    fun(&b);
    Derived d;
    fun(&d);
    system("pause");
    return 0;
}