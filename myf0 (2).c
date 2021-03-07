#include <stdio.h>
#include <string.h>
#include <conio.h>
char *stringcat(char *s1, char *s2, char *s3)
{
  char *p;
  p = s3;
  while ((*s3++ = *s1++) != '\0')
    ;
  s3--;
  while ((*s3++ = *s2++) != '\0')
    ;
  return p;
}

int main()
{
  char s1[100], s2[100], s3[200];
  puts(" first string : ");
  gets(s1);
  puts("second string");
  gets(s2);
  puts("last string : ");
  if (strlen(s1) < strlen(s2))
    puts(stringcat(s1,s2,s3));
  else
    printf("%s", stringcat(s2,s1,s3));
  getch();
  return 0;
}
