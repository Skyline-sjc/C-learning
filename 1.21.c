#include <stdio.h>
#include <math.h>
int is_prime(int n)
{
    int i;
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    for (i = 2; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int is_leap_year(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }
    else if (year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void print_mul_tab(int n)
{
    int i = 0, j = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d*%d=%3d\t", i, j, i * j);
        }
        printf("\n");
    }
}
int days(int year,int month){
    switch (month)
    {
    case 1:
        return 31;
    case 2:{
        if(is_leap_year(year)){
            return 29;
        }else{
            return 28;
        }
    }
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        return -1;
    }
}
int main()
{
    int year = 0, month = 0;
    while(scanf("%d %d",&year,&month)!=EOF){
        printf("%d\n", days(year, month));
    }
    return 0;
}