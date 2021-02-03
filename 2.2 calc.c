#include <stdio.h>
void menu();
int add(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);
int main()
{
    int input = 0;
    int x = 0, y = 0;
    int (*pfArrp[])(int, int) = {0, add, sub, mul, div};

    do
    {
        menu();
        printf("请输入您的选择\n");
        scanf("%d", &input);
        if (input >= 1 && input <= 4)
        {
            printf("请输入x，y\n");
            scanf("%d%d", &x, &y);
            int ret = pfArrp[input](x, y);
            printf("结果是%d\n", ret);
        }
        else if (input == 0)
        {
            printf("退出计算器\n");
        }
        else
        {
            printf("非法输入，请重新输入！\n");
        }
    } while (input);
    return 0;
}
void menu()
{
    printf("************************\n");
    printf("**********1.add*********\n");
    printf("**********2.sub*********\n");
    printf("**********3.mul*********\n");
    printf("**********4.div*********\n");
    printf("**********0.exit********\n");
    printf("************************\n");
}
int add(int x, int y)
{
    return x + y;
}
int sub(int x, int y)
{
    return x - y;
}
int mul(int x, int y)
{
    return x * y;
}
int div(int x, int y)
{
    return x / y;
}
