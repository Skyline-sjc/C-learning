#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
char *my_strstr(char *mum, char *child)
{
    assert(mum && child);
    const char *pc = mum;
    while (*pc)
    {
        const char *p1 = pc;
        const char *p2 = child;
        while (*p1 == *p2 && *p1 && *p2)
        {
            p1++;
            p2++;
        }
        if (*p2 == '\0')
        {
            return (char *)pc;
        }
        pc++;
    }
    return NULL;
}
char *my_strcat(char *dest, const char *sorc)
{
    char *ret = dest;
    while (*dest != '\0')
    {
        dest++;
    }
    while (*dest++ = *sorc++)
    {
        ;
    }
    return ret;
}
char *my_strcpy(char *dest, char *sorc)
{
    assert(dest && sorc);
    char *ret = dest;
    while (*dest++ = *sorc++)
    {
        ;
    }
    return ret;
}
int my_strcmp(const char *str1, const char *str2)
{
    assert(str1 && str2);
    while (*str1 == *str2)
    {
        if (*str1 == '\0' && *str2 == '\0')
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
int my_strlen(const char *str){
    assert(str);
    if(*str=='\0'){
        return 0;
    }
    return 1 + my_strlen(str + 1);
}
int main()
{
   char arr[]="skyline&csdn.com";
   char arr2[30]={0};//因为strtok函数会修改源数组，通常复制后处理
   char sep[]="&.";
   strcpy(arr2,arr);
   printf("%s\n",strtok(arr2,sep));
   printf("%s\n",strtok(NULL,sep));
   printf("%s\n",strtok(NULL,sep));
   return 0;
}
// int main()
// {
//     char num1[] = "abcd";
//     char num2[] = "abcd";
//     printf("%d", my_strcmp(num1, num2));
//     return 0;
// }
// int main(){
//     char str[20] = "**********";
//     char sorc[] = "abc";
//     printf("%s\n", my_strcmp(str, sorc));
//     return 0;
// }
// int main(){
//     char mum[] = "abbcded";
//     char child[] = "bbc";
//     char *ret = my_strstr(mum, child);
//     if(ret==NULL){
//         printf("找不到！\n");
//     }else{
//         printf("%s\n", my_strstr(mum, child));
//     }
//     return 0;
// }