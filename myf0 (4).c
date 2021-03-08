#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
void replace_name(char *str, char *orgname, char *newname)
{
  int i, j, k;
  char buf[512];
  for (i=0; str[i] != '\0'; i++)
  {
    for (j = i, k=0; str[j] == orgname[k]; j++, k++)
      ;
    if (orgname[k] == '\0' && (i == 0 || !isalpha(str[i - 1])) && !isalpha(str[j]))
    {
      strcpy(buf, str + j);
      strcpy(str + i, newname);
      strcpy(str + i + strlen(newname), buf);
    }
  }
}
int main()
{
  char s[512] = "Bob is a good boy.We love Bob.";
  char *olds = "Bob", *news = "John";
  puts(s);
  replace_name(s,olds,news);
  puts(s);
  getch();
  return 0;
}
