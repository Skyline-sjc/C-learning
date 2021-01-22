#include<stdio.h>
void print(int n){
    if(n>10){
        print(n / 10);
    }
    printf("%d ", n%10);
}
int fact_iteration(int n){
    int result = 1;
    while(n>1){
        result *= n;
        n--;
    }
    return result;
}
int fact_recursion(int n){
    if(n==1){
        return 1;
    }
    return n * fact_recursion(n - 1);
}
int mystrlen_iteration(char *a){
    int len = 0;
    while(*a!='\0'){
        len++;
        a++;
    }
    return len;
}
int mystrlen_recursion(char *a){
    if(*a == '\0'){
        return 0;
    }
    return 1+mystrlen_recursion(a + 1);
}
void reverse_string(char *string){
    int len = mystrlen_recursion(string);
    if(len>1){
        char temp = string[0];
        string[0] = string[len - 1];
        string[len - 1] = '\0';
        reverse_string(string + 1);
        string[len - 1] = temp;
    }
}
int Digitsum(int n){
    if(n<10){
        return n;
    }
    return n % 10 + Digitsum(n / 10);
}
int my_pow(int n,int k){
    if(k==1){
        return n;
    }
    return n * my_pow(n, k - 1);
}
int fib_iteration(int n){
    int a=1, b=1, c=1;
    int temp1,temp2;
    if(n==1 || n==2){
        return 1;
    }
    while(n>2){
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}
int fib_recursion(int n){
    if(n<=2){
        return 1;
    }
    return fib_recursion(n - 1) + fib_recursion(n - 2);
}
long tail_recusion_fact(int n,long result){
    if(n==1){
        return result;
    }
    return tail_recusion_fact(n - 1, result * n);
}
int main(){
    printf("%ld",tail_recusion_fact(100,1));
    return 0;
}