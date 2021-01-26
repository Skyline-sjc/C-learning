#include<stdio.h>
// int main(){
//     int a, b,c,count=0;
//     scanf("%d%d", &a, &b);
//     c = a ^ b;
//     for (int i = 0; i < 32;i++){
//         if((c>>i)&1==1){
//             //000000000000000000000000110111
//             //000000000000000000000000000001
//             //000000000000000000000000001001
//             count++;
//         }
//     }
//         printf("%d", count);
//     return 0;
// }
// int DtoB(int n,int *arr){
//     int i = 0;
//     while(n>0){
//         if(n%2==0){
//             arr[i++] = 0;
//         }
//         else{
//             arr[i++] = 1;
//         }
//         n = n / 2;
//     }

//     return i ;
// }
// int main(){
//     int x = 55,num[10]={0};
//     int len = DtoB(x, num);
//     printf("奇数位：");
//     for (int i = 0; i < len;i=i+2){
//         printf("%d", num[i]);
//     }
//     printf("\n");
//     printf("偶数位：");
//     for (int i = 1; i < len;i=i+2){
//         printf("%d", num[i]);
//     }
//     printf("\n");
// }
int con(int x){
    int i=0,count=0;
    for (i = 0; i < 32;i++){
        if((x>>i)&1==1){
            count++;
        }
    }
    return count;
}
