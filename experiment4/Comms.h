#pragma once
#include <string>
#include "CommEntry.h"
using namespace std;

//ͨѶ¼��
class Comms
{
public:
    //ͨѶ¼��ʼ��ͨѶ¼��Ŀ����
    Comms(int num);

    //�����ͷ�ͨѶ¼��Ŀ�ڴ�
    ~Comms();

    //����һЩͨѶ¼��Ŀ
    void inputSome();

    //���һЩͨѶ¼��Ŀ
    void outputAll();

    //������������ͨѶ¼,�����±�
    int findComName(string name);

    //��������,�޸ĵ绰
    void modifyTel(string name, string tel);

    //����绰,����ͨѶ¼��Ŀ�±�
    int findComTel(string tel);

    //����绰,�޸�����
    void modifyName(string tel, string name);

    //������������ģ������
    void fuzzySearch(string name);

private:
    //ͨѶ¼��Ŀָ��
    CommEntry *m_pCe;

    //ͨѶ¼������
    int m_Maxnum;

    //ͨѶ¼��ǰ����
    int m_count;
};

