#include <stdlib.h>
#include <stdio.h>
int main()
{
    union a {
        int ia;
        float ib;
    };
    union a t;
    int chose;
    while (1)
    {
        printf("1. ����float�������鿴�����ڴ���16������\n");
        printf("2. ����16������תΪ������\n");
        printf("0. �˳�����\n");
        printf("������: ");
        scanf("%d", &chose);
        switch (chose)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("����float������: ");
            scanf("%f", &t.ib);
            printf("%.8f ���ڴ���16����: %x\n", t.ib, t.ia);
            break;
        case 2:
            printf("����16������: ");
            scanf("%x", &t.ia);
            //t.ia = 0xc1360000;
            printf("%x ��float��ʾ %.8f\n", t.ia, t.ib);
            break;
        default:
            printf("�������");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}