#include<stdio.h>
char *my_strcpy(char *dest,const char* source){
    char *temp = dest;
    while(*dest++=*source++){
        ;
    }
    *dest = *source;
    return temp;
}
int my_strlen(char *str){
    if (*str=='\0'){
        return 0;
    }
    return 1 + my_strlen(str + 1);
}
void bubble_sort(int *arr,int len){
    int i = 0, j = 0;
    for (i = 0; i < len - 1;i++){
        int flag = 1;
        for (j = 0; j < len - 1 - i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }
        if(flag==1){
            break;
        }
    }
}
void odd_even(int *num,int len){
    int point = 0;
    int temp = 0;
    int i = 0;
    for (i = 0; i < len;i++){
        if(num[i] % 2==1){
            temp = num[i];
            num[i]=num[point];
            num[point] = temp;
            point++;
        }
    }
    bubble_sort(num + point, len - point + 1);
}
int main(){
    int i = 0;
    int num[10] = {1,2,3,4,5,6,7,8,9,10};
    odd_even(num,10);
    for (i = 0; i < 10;i++){
        printf("%d ", num[i]);
    }
}
// int main(){
//     char a[] = "abcde";
//     char b[] = "qqqqqqqqqqqqqq";
//     printf("%d\n", my_strlen(a));
//     my_strcpy(b, a);
//     puts(b);
//     return 0;
// }
