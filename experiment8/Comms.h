#pragma once
#include "CommEntry.h"
#include "FriendEntry.h"
class Comms
{
private:
    //ͨѶ¼��Ŀ�����
    unsigned m_maxCount;
    //ͨѶ¼��ǰ����
    unsigned m_count;
    //ͨѶ¼��Ŀָ������
    CommEntry **mp_Ces;

public:
    //��ʼ�����캯��
    Comms(unsigned maxCount = 10);
    //���������ͷ��ڴ�
    ~Comms();
    //����ͨѶ¼
    void input();
    //���ͨѶ¼
    void outputAll();
    //�������������±�
    int find(string name);
    //���������޸���绰
    void modify(string name, string tel);
    //��ʾ������Ŀ
    void outputFri();
    //��ʾһ����Ŀ
    void outputCom();
};