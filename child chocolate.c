#include<stdio.h>
int helper(int chocolate,int limit){
    if(chocolate==0){
        return 1;
    }else if(chocolate <0){
        return 0;
    }else if(limit==0){
        return 0;
    }else{
        int with_it = helper(chocolate - limit, limit);
        int without_it = helper(chocolate, limit - 1);
        return with_it+without_it;
    }
}
int main(){
    printf("%d", helper(6, 4));
    return 0;
}