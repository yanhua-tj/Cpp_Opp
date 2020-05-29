#include "Complexcount.h"

//输入复数A和B
void Complexcount::input()
{
    cout << "复数A:\n";
    cin >> m_a;
    cout << "复数B:\n";
    cin >> m_b;
}

//输出A和B结果
void Complexcount::output()
{
    cout << "复数A: " << m_a << endl
        << "复数B: " << m_b << endl;
}

//复数加
Complex Complexcount::add()
{
    return m_a + m_b;
}

//复数减
Complex Complexcount::sub()
{
    return m_a - m_b;
}

//复数乘
Complex Complexcount::mul()
{
    return m_a * m_b;
}

//复数除
Complex Complexcount::div()
{
    return m_a / m_b;
}