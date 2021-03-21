#include<stdio.h>
#include<string.h>
#include<math.h>
void replaceSpace(char *str,int len){
    int start = 0;
    for (start = 0; str[start] != '\0';){
        char temp[100] = {'\0'};
        if(str[start]==' '){
            strcpy(temp, str + start + 1);
            str[start] = '%';
            str[start+1] = '2';
            str[start+2] = '0';
            str[start + 3] = '\0';
            strcat(str, temp);
            start += 3;
        }else{
        start++;}
    }
}
int is__min_step_fib(int n){
    int f1 = 0, f2 = 1, f = 0;
    while(1){
        if(n >=f1 &&n<=f2){
            if(fabs(f1-n)>fabs(f2-n)){
                return fabs(f2 - n);
            }else{
                return fabs(f1 - n);
            }
        }
        f = f1 + f2;
        f1 = f2;
        f2 = f;

    }
}
int main(){
    int x = 0;
    scanf("%d", &x);
    printf("%d",is__min_step_fib(x));
    return 0;
}
// int main(){
//     char str[100];
//     gets(str);
//     replaceSpace(str, strlen(str));
//     puts(str);
//     return 0;
// }