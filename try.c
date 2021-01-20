#include<stdio.h>
void sort(int *a,int len){
    int j=0,temp=0;
    if (len==1){
        return;
    }
    for (j = 0; j < len - 1; j++)
    {
        if(a[j]<a[j+1]){
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }
    return sort(a, len - 1);
}
// #include<stdio.h>
// // int gcd(int a,int b){
// //     if(b==0){
// //         return a;
// //     }
// //     return gcd(b, a % b);
// // }
// #include<stdio.h>
// #include<math.h>
// int count_nine(int n){
//     int counter = 0;
//     while(n>0){
//         if(n%10==9){
//             counter++;
//         }
//         n = n / 10;
//     }
//     return counter;
// }
// #include<stdio.h>
// #include<math.h>
// #include<stdio.h>
// int bin_seatch(int *num,int value){
//     int left = 0;
//     int size = sizeof(num) / sizeof(num[0]);
//     printf("%d", size);
//     int right = size - 1;
//     int mid = 0;
//     while(left<=right){
//         mid = (left + right) / 2;
//         if(num[mid]<value){
//             left = mid+1;   
//         }else if(num[mid]>value){
//             right = mid-1;
//         }else
//         {
//             return mid;
//         }    
//     }
//     if(left>right){
//         return -1;
//     }
// }
// int main(){
//     int num[10] = {0};
//     int value = 0,i=0;
//     printf("请输入10个数\n");
//     for (i = 0; i < 10;i++){
//         scanf("%d", &num[i]);
//     }
//     printf("请输入查找值\n");
//     scanf("%d", &value);
//     if(bin_seatch(num,value)>=0){
//         printf("下标为：%d", bin_seatch(num,value));
//     }else{
//         printf("找不到");
//     }
// }
#include<stdio.h>
int size(int *num){
    return sizeof(num);
}
int main(){
    int num[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1,1};
    printf("%d", size(num));
}