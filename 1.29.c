#include<stdio.h>
// int main(){
//     int a = 15;   //00000000000000000000000000001111
//     int b = 19;   //00000000000000000000000000010011
//     int c = a & b;//00000000000000000000000000000011
//     printf("%d", c);
//     return 0;
// }
// int main(){
//     int a = 15;   //00000000000000000000000000001111
//     int b = 19;   //00000000000000000000000000010011
//     int c = a | b;//00000000000000000000000000011111
//     printf("%d", c);//输出结果为31
//     return 0;
// }
// int main(){
//     int a = 15;   //00000000000000000000000000001111
//     int b = 19;   //00000000000000000000000000010011
//     int c = a ^ b;//00000000000000000000000000011100
//     printf("%d", c);//输出结果为28
//     return 0;
// }
// int main(){
//     int a = 19;//00000000000000000000000000010011
//     int b = ~a;//11111111111111111111111111101100(内存中的补码)
//                //11111111111111111111111111101011（反码，即补码-1）
//                //10000000000000000000000000010100（原码，即反码符号位不变，其余位数取反）
//     printf("%d", b);
//     return 0;
// }
// int main(){
//     int a = 16;  //00000000000000000000000000010011
//     int b = a<<1;//00000000000000000000000000100110
//     printf("%d", b);//输出结果38
//     return 0;
// }
// int main(){
//     int a = -19; //10000000000000000000000000010011（原码）
//                  //11111111111111111111111111101100（反码）
//                  //11111111111111111111111111101101(补码)
//     int b = a>>1;//11111111111111111111111111110110（补码）
//                  //11111111111111111111111111110101（反码）
//                  //10000000000000000000000000001010（原码
//     printf("%d", b);//输出结果-10
//     return 0;
// }
// #include<math.h>
// int main(){
//     int a = 120;
//     int i = 0;
//     int temp = 1;
//     for (i = 1; i <= 3;i++){
//         temp *= 2;
//         printf("%d\n", a >> i);
//         printf("%d\n", a / temp);
//     }
//     return 0;
// }
// int main(){
//     int a = 10, b = 5;
//     printf("a=%d b=%d\n", a, b);
//     a = a ^ b;
//     b = a ^ b;
//     a = a ^ b;
//     printf("a=%d b=%d", a, b);
//     return 0;
// }
// int main(){
//     int a = 55,count=0;//55-->00000000000000000000000000110111
//                        //1 -->00000000000000000000000000000001
//                        //a&1->00000000000000000000000000000001
//                        //a/2->00000000000000000000000000011011
//     while(a>0){
//         if(a&1==1){
//             count++;
//         }
//         a = a / 2;
//     }
//     printf("%d", count);
// }
int is_two_pow(int n){
    if((n&(n-1))==0){
        return 1;
    }else{
        return 0;
    }
}
int count_one(int n){
    int count = 0;
    while(n>0){
        count++;
        n = n & (n - 1);
    }
    return count;
}
int reverse(int n){
    int result = 0;
    for (int i = 0; i < 32;i++){
        result = result << 1;
        result += (n&1);
        n >>1;
    }
    return result;
}
int main(){
    int a = 55;//55-->   00000000000000000000000000110111
               //54-->   00000000000000000000000000110110
               //55&54-->00000000000000000000000000110110-->54
               //53-->   00000000000000000000000000110101
               //54&53-->00000000000000000000000000110100-->52
               //51-->   00000000000000000000000000110011
               //52&51-->00000000000000000000000000110000--48
               //47-->   00000000000000000000000000101111
               //47&46-->00000000000000000000000000100000--32
               //31-->   00000000000000000000000000011111
               //32&31-->00000000000000000000000000000000--0 循环结束
    printf("%d", count_one(a));
    return 0;
}