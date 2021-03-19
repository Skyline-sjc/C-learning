#include<stdio.h>
#include<math.h>
int main(){
    double exp = 10e-10;
    double x1 = 0.0;
    double x2 = 0.0;
    double x = 0.0;
    scanf("%lf", &x);
    x1 = x;
    while(fabs(x1-x2)>exp){
        x2 = x1;
        x1 = 1.0 / 3 * (2 * x1 + x / (x1 * x1));
    }
    printf("%.2lf", x1);
    return 0;
}