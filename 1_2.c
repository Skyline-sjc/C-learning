#include<stdio.h>
int main(){
    int n = 0, a = 0, d = 0,sum=0,temp=0;
    scanf("%d %d %d", &n, &a, &d);
    while(n>0){
        sum += (a + (n - 1) * d);
        n--;
    }
    printf("%d", sum);
    return 0;
}