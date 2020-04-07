#include <iostream>
using namespace std;
int g_a, g_b;                   //全局变量
const int c_g_a = 1, c_g_b = 2; //const全局变量

int main()
{
    int a, b;            //局部变量
    static int s_a, s_b; //静态变量
    cout << "局部变量a的地址：" << (long long)&a << endl;
    cout << "局部变量b的地址：" << (long long)&b << endl;

    cout << "全局变量g_a的地址：" << (long long)&g_a << endl;
    cout << "全局变量g_b的地址：" << (long long)&g_b << endl;

    cout << "静态变量s_a的地址：" << (long long)&s_a << endl;
    cout << "静态变量s_b的地址：" << (long long)&s_b << endl;
    //字符串常量
    cout << "字符串常量“hello”的地址：" << (long long)&"hello" << endl;
    cout << "字符串常量“world”的地址：" << (long long)&"world" << endl;

    //const全局变量
    cout << "const全局变量c_a的地址：" << (long long)&c_g_a << endl;
    cout << "const全局变量c_b的地址：" << (long long)&c_g_b << endl;

    //const局部变量
    const int c_a = 1, c_b = 2;
    cout << "const局部变量c_a的地址：" << (long long)&c_a << endl;
    cout << "const局部变量c_b的地址：" << (long long)&c_b << endl;

    system("pause");
    return 0;
}