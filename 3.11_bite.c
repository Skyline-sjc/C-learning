#include <stdio.h>
#include <string.h>
#include <assert.h>
int my_atoi(const char *str)
{
    int i = 0;
    int len = strlen(str);
    int sum = 0;
    for (i = 0; i < len; i++)
    {
        sum = sum * 10 + (str[i] - '0');
    }
    return sum;
}
char *my_strncat(char *dest, const char *sorc, size_t n)
{
    int s = strlen(dest);
    while (*sorc != '\0' && n > 0)
    {
        *(dest + s) = *sorc++;
        s++;
        n--;
    }
    *(dest + s) = '\0';
    return dest;
}
char *my_strncpy(char *dest, char *sorc, size_t n)
{
    assert(dest && sorc);
    char *ret = dest;
    while (*sorc != '\0' && n > 0)
    {
        *dest++ = *sorc++;
        n--;
    }
    *dest = '\0';
    return ret;
}
int FindSingle(int *a, int len, int *record)
{
    int i = 0, j = 0,size=0,k=0;
    for (i = 0; i < len; i++)
    {
        int flag = 0;
        for (j = 0; j < len; j++)
        {
            if (i != j && a[i] == a[j])
            {
                flag = 1;
            }
        }
        if(flag==0){
            for (k = 0;k< size;k++){
                if(record[k]==a[k]){
                    break;
                }
            }
            if(k==size){
                record[size] = a[i];
                size++;
            }
        }
    }
    return size;
}
int main()
{
    int a[11] = {1, 1, 3, 3, 5, 5, 7, 7, 8, 9, 10};
    int record[10];
    int len=FindSingle(a,sizeof(a)/sizeof(a[0]),record);
    int i = 0;
    for (i = 0; i < len;i++){
        printf("%d ", record[i]);
    }
    return 0;
}