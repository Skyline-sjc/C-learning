#include<stdio.h>
int main(){
    int n = 0, v1 = 0, v2 = 0, t = 0;
    scanf("%d %d %d %d", &n, &v1, &v2, &t);
    float result =(float) n / ((float)v1 - (float)v2);
    if(result<t && result>0){
        printf("%.2f\n", result);
    }else if(n==0){
        printf("0.00\n");
    }else if(v1==v2){
        printf("%d", -1);
    }
    else
    {
        printf("%d", -1);
    }
    return 0;
}