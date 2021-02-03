#include<stdio.h>
#include<string.h>
#define ROW 3
#define LINE 3
int matrix_search(int num[LINE][ROW],int row,int line,int n){
    int i = 0, j = 0;
    for (i = 0; i < line;i++){
        if(num[i][row-1]>n){
            break;
        }
    }
    if(i==line){
        return 0;
    }
    for (j = 0; j < row;j++){
        if(num[i][j]==n){
            break;
        }
    }
    if(j==row){
        return 0;
    }else{
        return 1;
    }
}
int main(){
    int num[3][3] = {1,2,3,4,5,6,7,8,9};
    printf("%d", matrix_search(num, 3, 3, 10));
    return 0;
}
// void left_reverse(char *str,int len,int times){
//     if(times==0){
//         return;
//     }
//     char temp = str[0];
//     int i = 0;
//     for (i = 0; i < len - 1;i++){
//         str[i] = str[i + 1];
//     }
//     str[i] = temp;
//     return left_reverse(str, len, times - 1);
// }
// int main(){
//     char str[] = "ABCD";
//     left_reverse(str, strlen(str), 2);
//     puts(str);
//     return 0;
// }
// void left_reverse(char *str,int len){
//     char temp = str[0];
//     int i = 0;
//     for (i = 0; i < len - 1;i++){
//         str[i] = str[i + 1];
//     }
//     str[i] = temp;
// }
// void right_reverse(char *str,int len){
//     char temp = str[len - 1];
//     int i = 0;
//     for (i = len - 1; i > 0;i--){
//         str[i] = str[i - 1];
//     }
//     str[i] = temp;
// }
// int is_reverse(char* str1,char* str2,int len){
//     if (strlen(str1) != strlen(str2)){
//         return 0;
//     }
//     int temp = len;
//     while (temp > 0)
//     {
//         left_reverse(str1, len);
//         if (strcmp(str1, str2) == 0)
//         {
//             return 1;
//         }
//         temp--;
//         }
//     left_reverse(str1,len);
//     temp = len;
//     while(temp>0){
//         right_reverse(str1, len);
//         if(strcmp(str1,str2)==0){
//         return 1;
//         }
//         temp--;
//     }
//     return 0;
// }
// int main(){
//     char str1[20];
//     char str2[20];
//     printf("请输入第一个字符串\n");
//     gets(str1);
//     printf("请输入第二个字符串\n");
//     gets(str2);
//     printf("%d", is_reverse(str1, str2, strlen(str1)));
//     return 0;
// }
// int main(){
//     char *a[] = {"work", "at", "alibaba"};
//     char **pa = a;
//     pa++;
//     printf("%s", *pa);
//     return 0;

// }