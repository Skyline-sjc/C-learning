#include <stdio.h>
#include <math.h>

int is_H(int n)
{
    if (n % 4 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_H_prime(int n)
{
    int i = 0;
    for (i = 5; i < n; i = i + 4)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    if(is_H(n)==1 && n!=1){
        return 1;
    }else{
        return 0;
    }
}
int search(int a[][3])
{
    int i = 0, j = 0, m = 0, n = 0, ct = 0;
    for (i = 25; i <= 150; i++)
    {
        for (j = 5; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                m = j;
                n = i / j;
                if (is_H_prime(m) == 1 && is_H_prime(n) == 1)
                {
                    a[ct][0] = i, a[ct][1] = m, a[ct][2] = n;
                    ct++;
                    break;
                }
            }
        }
    }
    return ct;
}
int main()
{
    FILE *p = fopen("myf2.out", "w");
    int num = 0, i = 0;
    int a[100][3];
    num = search(a);
    printf("Number:%d\n", num);
    for (i = 0; i < num; i++)
    {
        printf("%d=%d*%d\n", a[i][0], a[i][1], a[i][2]);
    }
    fprintf(p,"Number:%d\n", num);
    for (i = 0; i < num; i++)
    {
        fprintf(p,"%d=%d*%d\n", a[i][0], a[i][1], a[i][2]);
    }
    fclose(p);
    return 0;
}