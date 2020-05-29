#include <iostream>
#include <cstdlib>
#include "Complex.h"
#include "Complexcount.h"
using namespace std;

int menu();											//菜单
void fun(Complexcount&);											//选择功能

//菜单
int menu()
{
    int i;
    cout << "复数计算器" << endl;
    cout << "1.输入复数" << endl;
    cout << "2.输出复数" << endl;
    cout << "3.复数加法" << endl;
    cout << "4.复数减法" << endl;
    cout << "5.复数乘法" << endl;
    cout << "6.复数除法" << endl;
    cout << "7.复数的加减乘除" << endl;
    cout << "0.退出程序" << endl;
    cout << "请输入数字(0-7)选择功能: ";
    cin >> i;
    return i;
}

//选择功能
void fun(Complexcount& counter)
{
    while (true)
    {
        int funId = menu();
        while (funId < 0 || funId > 7)
        {
            cout << "输入有误, 请重新输入！" << endl;
            system("pause");
            system("cls");
            funId = menu();
        }
        if (funId == 0)
            break;
        switch (funId)
        {
        case 1:     //输入复数
            counter.input();
            break;
        case 2:     //输出复数
            counter.output();
            break;
        case 3:     //复数相加
            cout << "A + B后的结果为: " << counter.add() << endl;
            break;
        case 4:     //复数相减
            cout << "A - B后的结果为: " << counter.sub() << endl;
            break;
        case 5:     //复数相乘
            cout << "A * B后的结果为: " << counter.mul() << endl;
            break;
        case 6:     //复数相除
            cout << "A / B后的结果为: " << counter.div() << endl;
            break;
        case 7:     //复数相乘
            cout << "A + B后的结果为: " << counter.add() << endl;
            cout << "A - B后的结果为: " << counter.sub() << endl;
            cout << "A * B后的结果为: " << counter.mul() << endl;
            cout << "A / B后的结果为: " << counter.div() << endl;
            break;
        }
        system("pause");
        system("cls");
    }
}

int main()
{
    Complexcount counter;
    fun(counter);
    return 0;
}
