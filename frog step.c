#include <stdio.h>
int helper(int step){
    if(step==1){
        return 1;
    }else if(step==2){
        return 2;
    }else{
        int two_step = helper(step - 2);
        int one_step = helper(step - 1);
        return one_step + two_step;
    }
}
int main(){
    printf("%d", helper(5));
    return 0;
}