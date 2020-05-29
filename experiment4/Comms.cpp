#include "Comms.h"
//��ʼ�����캯��
Comms::Comms(unsigned maxCount) : m_count(0)
{
    //��ʼ�����ͨѶ¼��
    m_maxCount = maxCount;
    mp_Ce = new CommEntry[m_maxCount];
}

//�����ͷ��ڴ�
Comms::~Comms()
{
    delete[]mp_Ce;
}

//����ͨѶ¼
void Comms::input()
{
    cout << "�����������Ŀ����: ";
    unsigned num = 0;
    cin >> num;
    while (m_count + num > m_maxCount)
    {
        cout << "ʣ��ͨѶ¼��Ŀ��������, ʣ��" << m_maxCount - m_count << endl;
        cout << "�����������Ŀ����: ";
        cin >> num;
    }
    cin.ignore(16, '\n');           //��ջ�����
    for (int i = 0; i < (int)num; i++)
    {
        cout << "��ӵ�" << i + 1 << "��ͨѶ¼" << endl;
        mp_Ce[i + m_count].input();
    }
    m_count += num;
}

//���ͨѶ¼
void Comms::outputAll()
{
    CommEntry::outputInfo();
    cout << endl;
    for (unsigned i = 0; i < m_count; i++)
    {
        mp_Ce[i].output();
    }
    cout << "��ǰͨѶ¼һ����: " << m_count;
    cout << "\tͨѶ¼�������: " << m_maxCount << endl;
}

//�������������±�
int Comms::findname(string name)
{
    for (unsigned i = 0; i < m_count; i++)
    {
        if (mp_Ce[i].getName() == name)
        {
            return (int)i;
        }
    }
    return -1;
}

//����绰�����±�
int Comms::findtel(string tel)
{
    for (unsigned i = 0; i < m_count; i++)
    {
        if (mp_Ce[i].getTel() == tel)
        {
            return (int)i;
        }
    }
    return -1;
}

//���������޸���绰
void Comms::modifytel(string name, string tel)
{
    mp_Ce[findname(name)].setTel(tel);
    cout << name << "�绰�޸�Ϊ: " << tel << endl;
}

//����绰�޸�������
void Comms::modifyname(string tel, string name)
{
    mp_Ce[findtel(tel)].setName(name);
    cout << tel << "����ϵ���޸�Ϊ: " << name << endl;
}

//����绰ģ������
void Comms::fuzzysearchtel(string tel)
{
    int count = 0;
    cout << "ģ�����ҽ��: " << endl;
    for (unsigned i = 0; i < m_count; i++)
    {
        string s1 = mp_Ce[i].getTel();
        if (s1.find(tel) != string::npos)
        {
            cout << s1 << endl;
            count ++;
        }
    }
    if (count == 0)
    {
        cout << "ģ������û�н��" << endl;
    }
    else
    {
        cout << "ģ�����ҵ�" << count << "����Ϣ" << endl;
    }
}

//��������ģ������
void Comms::fuzzysearchname(string name)
{
    int count = 0;
    cout << "ģ�����ҽ��: " << endl;
    for (unsigned i = 0; i < m_count; i++)
    {
        string s1 = mp_Ce[i].getName();
        if (s1.find(name) != string::npos)
        {
            cout << s1 << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "ģ������û�н��" << endl;
    }
    else
    {
        cout << "ģ�����ҵ�" << count << "����Ϣ" << endl;
    }
}
