#pragma once
#include "CommEntry.h"
#include <fstream>
class Comms
{
private:
    //ͨѶ¼��Ŀ�����
    unsigned m_maxCount;
    //ͨѶ¼��ǰ����
    unsigned m_count;
    //ͨѶ¼��Ŀָ������
    CommEntry *mp_Ce;

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
    int findname(string name);
    //����绰�����±�
    int findtel(string tel);
    //���������޸���绰
    void modifytel(string name, string tel);
    //����绰�޸�������
    void modifyname(string tel, string name);
    //����绰ģ������
    void fuzzysearchtel(string tel);
    //��������ģ������
    void fuzzysearchname(string name);
    //���ļ��ж�����
    void inputFromFile(ifstream& in);
    //�������ݵ��ļ���
    void outputToFile(ofstream& out);
};