#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char first[] = "hello world!!!";
    char second[] = "**************";
    int left= 0;
    int right = strlen(first) - 1;
    while(left<=right){
        second[left] = first[left];
        second[right] = first[right];
        Sleep(1000);
        printf("%s\n", second);
        
        left++;
        right--;
        system("cls");
    }
    return 0;
}