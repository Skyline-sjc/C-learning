#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void menu()
{
    printf("**********************************\n");
    printf("*********** 1.play **********\n");
    printf("*********** 0.exit **********\n");
    printf("**********************************\n");
}
void game()
{
    int rand_num = rand()%100+1;
    int input = 0;
    do
    {
        printf("请输入猜测数字:>\n");
        scanf("%d", &input);
        if(input<rand_num){
            printf("小了！\n");
        }
        if(input>rand_num){
            printf("大了！\n");
        }

    } while (input != rand_num);
    printf("您已找到正确数字！\n");
}
int main()
{
    int choice = 0;
    srand((unsigned int)time(NULL));
    do{
        menu();
        printf("请输入您的选择:>\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            game();
            break;
        case 0:
            break;

        default:
            printf("输入错误！\n");
            break;
        }
    } while (choice);
}