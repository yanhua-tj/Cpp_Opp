#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void fun();
int iter(double, double, double);

int main()
{
    fun();
    system("pause");
    return 0;
}

void fun()
{
    int i, j, k;
    for (i = 20; i < 100; i++)
    {
        for (j = 20; j <= i; j++)
        {
            for (k = 20; k <= j; k++)
            {
                if(iter(i, j, k) == 1)
                    return;
            }
        }
    }
}

int iter(double t2, double t3, double t4)
{
    /*t2 = t3 / 2.045 + 49.34;
      t3 = 2.045 * t4 - 0.45;
      t4 = 1.045 * t2 - 0.9;*/
    double t2before, t3before, t4before;
    double t2res, t3res, t4res;
    //存储之前的
    t2before = t2;
    t3before = t3;
    t4before = t4;
    //计算当前的
    t2 = t3before / 2.045 + 49.34;
    t3 = 1.0225 * t4before - 0.45;
    t4 = 2.045 * t3before - t2before - 0.9;
    //计算结果
    t2res = (t2 - t2before) / (t2 > t2before ? t2 : t2before);
    t3res = (t3 - t3before) / (t3 > t3before ? t3 : t3before);
    t4res = (t4 - t4before) / (t4 > t4before ? t4 : t4before);
    if (fabs(t2res) <= 0.01 && fabs(t3res) <= 0.01 && fabs(t4res) <= 0.01)
    {
        printf("t2: %.2f\tt3: %.2f\tt4: %.2f\n", t2, t3, t4);
        return 1;
    }
    if (t2 > 100 || t3 > 100 || t4 > 100 || t2 < 20 || t3 < 20 || t4 < 20)
    {
        //printf("--------------------------------\n");
        return 0;
    }
    return iter(t2, t3, t4);
}
