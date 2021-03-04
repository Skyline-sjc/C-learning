#include <stdio.h>
#define N 5
int judge(int a[N][N])
{
    int sum = a[0][0] + a[0][1] + a[0][2] + a[0][3] + a[0][4];
    int sum1 = 0;
    int i = 0, j = 0;
    for (i = 1; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            sum1 += a[i][j];
        }
        if (sum1 != sum)
        {
            return 0;
        }
        sum1 = 0;
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            sum1 += a[j][i];
        }
        if (sum1 != sum)
        {
            return 0;
        }
        sum1 = 0;
    }
    for (i = 0; i < N; i++)
    {
        sum1 += a[i][i];
    }
    if (sum1 != sum)
    {
        return 0;
    }
    sum1 = 0;
    for (i = 0; i < N; i++)
    {
        sum1 += a[i][N - i - 1];
    }
    if (sum1 != sum)
    {
        return 0;
    }
    sum1 = 0;
    return 1;
}
int main()
{
    FILE *p = fopen("myf2.out", "w");
    int num[N][N] = {{17, 24, 1, 8, 15}, {23, 5, 7, 14, 16}, {4, 6, 13, 20, 22}, {10, 12, 19, 21, 3}, {11, 18, 25, 2, 9}};
    if (judge(num) == 1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    if (judge(num) == 1)
    {
        fprintf("p", "yes\n");
    }
    else
    {
        fprintf("p", "no\n");
    }
    fclose(p);
    return 0;
}