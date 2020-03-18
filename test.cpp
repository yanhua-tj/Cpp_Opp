/*
 * @Author: yanhua 
 * @Date: 2020-03-10 11:24:54 
 * @Last Modified by: yanhua
 * @Last Modified time: 2020-03-17 18:14:35
 */
#include <iostream>
using namespace std;
void swap(int &a, int &b);
int main()
{
    int i = 1, j = 3;
    int &ra = i, &rb = j;
    cout << i << "," << j << endl;
    swap(ra, rb);
    cout << i << "," << j << endl;
    system("pause");
    return 0;
}
void swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}