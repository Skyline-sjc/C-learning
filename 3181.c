#include<stdio.h>
int main(){
    int i = 0, j = 0,k=0;
    int n = 0;
    scanf("%d", &n);
    for (i = 0; i <= 333;i++){
        for (j = 0; j <= 200;j++){
            for (k = 0; k <= 150;k++){
                if(n==(3*i+5*j+7*k)){
                    printf("%d %d %d", i, j, k);
                    return 1;
                }
            }
        }
    }
    printf("%d", -1);
    return 0;
}