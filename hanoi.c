#include<stdio.h>
void hanoi(char A,char B,char C,int n)
{
    if(n==1){
        printf("\n move %d from %c to %c ",1,A,C);
    }else{
        hanoi(A, C, B, n - 1);//将n-1个铁片从a柱通过c柱子移动b柱
        printf("\n move %d from %c to %c", 1, A, C);//将1个贴片从a柱移动到c柱
        hanoi(B, A, C, n - 1);//将n-1个贴片从b柱通过a柱移动到c柱
    }
    
}
int main(){
    hanoi('a', 'b', 'c', 4);
    return 0;
}
