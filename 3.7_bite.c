#include <stdio.h>
#pragma pack(4)
struct S1
{char c2;
    double c1;
    
    int i;
    
};//占内存位12
struct S2{
    
    char c2;
    struct S1 b;
    double c1;
};
union Un
{
    char c;
    int i;
};

int main(){
    struct S1 s1;
    union Un u;
    printf("%d\n", sizeof(u));
    return 0;
}