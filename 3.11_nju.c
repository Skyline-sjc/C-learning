#include<stdio.h>
int main(){
    int fact = 1;
    int n = 1,i=0;
    scanf("%d", &n);
    for (i = 1; i <= n;i++){
        fact *= i;
    }
    printf("%d", fact);
    return 0;
}