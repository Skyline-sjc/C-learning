#include<stdio.h>
#include<math.h>
int is_prime(int n)
{
    int i;
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    for (i = 2; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void fun(int n){
    int i = 0;
    int cnt = 0;
    for (i = 2; i < n;i++){
        if(is_prime(i)==1){
            cnt = 0;
            while(n%i==0){
                cnt++;
                n /= i;
            }
            if(cnt>0){
                printf("%d", i);
                printf("(%d)", cnt);
            }
        }
        if(is_prime(n)){
            printf("%d", n);
            printf("(1)");
            break;
        }
    }
}
int main(){
    int x = 0;
    scanf("%d", &x);
    fun(x);
    return 0;
}