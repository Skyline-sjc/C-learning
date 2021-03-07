#include<stdio.h>
#define N 4
int findcount(int x[][N],int a[],int b[]){
    int count = 0;
    int i = 0, j = 0,k=0;
    for (i = 0; i < N;i++){
        for (j = 0; j < N;j++)
        {
            for (k = 0; k < count;k++){
                if(a[k]==x[i][j])
                    break;
            }
            if(k!=count){
                b[k]++;
            }else{
                a[k] = x[i][j];
                b[k] = 1;
                count++;
            }
        }
    }
    return count;
}
int main(){
    FILE *p = fopen("myf2.out", "w");
    int x[N][N] = {{6, 6, 6, 7}, {1, 6, 3, 7}, {1, 6, 6, 7}, {6, 6, 7, 7}};
    int a[10] = {0};
    int b[10] = {0};
    int count = findcount(x, a, b);
    int i = 0;
    for (i = 0; i < count;i++){
        printf("%d:%d ", a[i], b[i]);
    }
    for (i = 0; i < count;i++){
        fprintf(p,"%d:%d ", a[i], b[i]);
    }
    fclose(p);
    return 0;
}