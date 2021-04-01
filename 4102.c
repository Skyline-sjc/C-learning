#include<stdio.h>
double Hermite(int n,double x){
    if(n==0){
        return 1;
    }else if(n==1){
        return 2*x;
    }else{
        return 2 * x * Hermite(n - 1, x) - 2 * (n - 1) * Hermite(n - 2, x);
    }
}
int main(){
    int n = 0;
    double x = 0.0;
    scanf("%d %lf", &n, &x);
    printf("%.2lf", Hermite(n, x));
    return 0;
}