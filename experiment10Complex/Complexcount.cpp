#include "Complexcount.h"

//���븴��A��B
void Complexcount::input()
{
    cout << "����A:\n";
    cin >> m_a;
    cout << "����B:\n";
    cin >> m_b;
}

//���A��B���
void Complexcount::output()
{
    cout << "����A: " << m_a << endl
        << "����B: " << m_b << endl;
}

//������
Complex Complexcount::add()
{
    return m_a + m_b;
}

//������
Complex Complexcount::sub()
{
    return m_a - m_b;
}

//������
Complex Complexcount::mul()
{
    return m_a * m_b;
}

//������
Complex Complexcount::div()
{
    return m_a / m_b;
}