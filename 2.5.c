#include <stdio.h>
#include <assert.h>
void my_memcpy(void *dest, void *src, size_t count){
    assert(dest && src);
    while (count--)
        {
            *(((char *)dest)) = *(((char *)src));
            dest=(char*)dest+1;
            src=(char*)src+1;
        }
}
void my_memmove(void *dest, void *src, size_t count)
{
    assert(dest && src);
    if (dest > src)
    {
        while (count--)
        {
            *(((char *)dest) + count) = *(((char *)src) + count);
        }
    }
    else
    {
        while (count--)
        {
            *(((char *)dest)) = *(((char *)src));
            dest=(char*)dest+1;
            src=(char*)src+1;
        }
    }
}
int main()
{
    int num1[6] = {1, 2, 3, 4, 5, 6};
    my_memcpy(num1+2, num1, 16);//希望得到121234
                                //实际得到121212
    for (int i = 0; i < 6;i++){
        printf("%d", num1[i]);
    }
    return 0;
}