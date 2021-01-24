#include<stdio.h>
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
void init(int *arr,int len){
    int i = 0;
    for (i = 0; i < len;i++){
        arr[i] = 0;
    }
}
void print(int *arr,int len){
    int i = 0;
    for (i = 0; i < len;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void reverse(int *arr,int len){
    if(len<=1){
        return;
    }
    int temp = arr[0];
    arr[0] = arr[len - 1];
    arr[len - 1] = temp;
    return reverse(arr + 1, len - 2);
}
void swap(int *num1,int *num2,int len){
    int temp = 0,i=0;
    for (i = 0; i < len;i++){
        temp = num1[i];
        num1[i] = num2[i];
        num2[i] = temp;
    }
}
int main(){
    int num1[9] = {1,1,1,1,1,1,1,1,1};
    int num2[9] = {2,2,2,2,2,2,2,2,2};
    swap(num1, num2, 9);
    print(num1, 9);
    print(num2, 9);
}