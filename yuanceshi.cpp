#include <iostream>
using namespace std;
#define PI 3.1415926
int main()
{
    int itype;
    float redius,a,b,area;
    cout << "图形的类型为？1.圆形,2.长方形,3.正方形";
    cin >> itype;
    switch (itype)
    {
    case 1:
        cout << "圆的半径?";
        cin >> redius;
        area = PI * redius * redius;
        cout << "圆的面积：" << area << endl;
        break;
    case 2:
        cout << "长方形的长：";
        cin >> a;
        cout << "长方形的宽：";
        cin >> b;
        area = a * b;
        cout << "长方形的面积：" << area << endl;
        break;
    case 3:
        cout << "正方形的边?";
        cin >> a;
        area = a * a;
        cout << "正方形的面积：" << area << endl;
    default:
        cout << "输入不符合条件\n";
        break;
    }
    return 0;
}