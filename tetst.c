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
        printf("1. 输入float浮点数查看其在内存中16进制码\n");
        printf("2. 输入16进制码转为浮点数\n");
        printf("0. 退出程序\n");
        printf("请输入: ");
        scanf("%d", &chose);
        switch (chose)
        {
        case 0:
            return 0;
            break;
        case 1:
            printf("输入float浮点数: ");
            scanf("%f", &t.ib);
            printf("%.8f 在内存中16进制: %x\n", t.ib, t.ia);
            break;
        case 2:
            printf("输入16进制码: ");
            scanf("%x", &t.ia);
            //t.ia = 0xc1360000;
            printf("%x 的float表示 %.8f\n", t.ia, t.ib);
            break;
        default:
            printf("输入错误");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}