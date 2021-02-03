#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Stu
{
    char name[20];
    int age;
    float score;
}STU;

int char_cmp(const void* e1,const void *e2){
    return strcmp((char *)e1, (char *)e2);
}
int float_cmp(const void*e1,const void *e2){
    return *((float *)e1) - *((float *)e2);
}
int struct_cmp(const void*e1,const void *e2){
    return ((STU*)e1)->age - ((STU*)e2)->age;
}
int int_cmp(const void *e1,const void *e2){
    return *((int *)e1) - *((int *)e2);
}
void my_swap(char *e1,char *e2,int width){
    int i = 0;
    for (i = 0; i < width; i++){
        char temp = *e1;
        *e1 = *e2;
        *e2 = temp;
        e1++;
        e2++;
        }
}

void my_qsort(void* base,size_t size,size_t width,int (*cmp)(const void* e1,const void *e2)){
    int i = 0, j = 0;
    for (i = 0; i < size - 1;i++){
        for (j = 0; j < size - 1 - i;j++){
            if(cmp((char *)base+j*width,(char *)base+(j+1)*width)>0){
                my_swap((char *)base + j * width, (char *)base + (j + 1) * width, width);
            }
        }
    }
}
void quicksort(int *num){
    
}
int main(){
    STU stu_list [3] = {{"celina", 21, 99.1}, {"angle", 15, 95.2}, {"betty", 13, 89.7}};
    int num[10] = { 2, 5, 7, 8, 1, 3, 4, 6, 10, 9 };
    qsort(stu_list,3,sizeof(stu_list[0]),struct_cmp);
    for (int i = 0; i < 3;i++){
        printf("%d ", (stu_list+i)->age);
    }
    return 0;
}