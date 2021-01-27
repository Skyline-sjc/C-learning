#include<stdio.h>
#include<string.h>
void reverse_string(char *str,int len){
    for (int i = len-1; i >= 0;i--){
        printf("%c", *(str + i));
    }
}
int sum(int n,int count){
    int result = 0, temp = count;
    while(temp>0){
        result += n;
        n *= 10;
        temp--;
    }
    return result;
    
}
int is_daffodil(int n){
    int result = 0, temp = n;
    while(n>0){
        result += (n % 10) * (n % 10) * (n % 10);
        n = n / 10;
    }
    if(result==temp){
        return 1;
    }else{
        return 0;

    }
}
void print(int n){
    int i = 0;
    for (i = 0; i < 6 - (n / 2);i++){
        printf(" ");
    }
    for (i = 0; i < n;i++){
        printf("*");
    }
    for (i = 0; i < 12 - (n / 2);i++){
        printf(" ");
    }
    printf("\n");
}
int soft_drink(int n){
    int result = 0, temp = 0;
    ;
    while(n>0){
        n--;
        result++;
        temp++;
    }
    while(temp>1){
        result++;
        temp -= 2;
        temp++;
    }
    return result;
}
int main(){
    printf("请输入有多少钱\n");
    int n = 0;
    scanf("%d", &n);
    printf("%d", iteration_water(n));
    return 0;
}
// int main(){
//     int n = 1;
//     for (; n <= 13;n+=2){
//         print(n);
//     }
//     for (n = n - 4; n >= 1;n-=2){
//         print(n);
//     }
//     return 0;
    
// }
// int main(){
//     for (int i = 0; i <= 100000;i++){
//         if(is_daffodil(i)==1){
//             printf("%d ", i);
//         }
//     }
//         return 0;
// }
// int main(){
//     int a;
//     scanf("%d", &a);
//     int result = 0;
//     for (int i = 0; i < 5;i++){
//         result += sum(a, i + 1);
//     }
//     printf("%d", result);
//     return 0;
// }

// int main(){
//     int arr[10] = {0};
//     for (int i = 0; i < 10;i++){
//         printf("%d ", *(arr + i));
//     }
//     return 0;
// }
// int main(){
//     char str[100] = {'\0'};
//     gets(str);
//     reverse_string(str,strlen(str));
//     return 0;
// }
// int main(){
//     char str[20] = {'\0'};
//     char c = '\0';
//     int i = 0;
//     for (int i = 0; c != '\n';i++){
//         str[i] = c;
//         scanf("%c", &c);
//     }
//         reverse_string(str, strlen(str));
//     return 0;
// }