#include <stdio.h>
#include <string.h>
#include <conio.h>
struct phonebook
{
  char name[30];
  char phone[20];
  int count;
};
int find_insert(struct phonebook *s, int len, struct phonebook x)
{
  int i, j;
  for (i = 0; i < len; i++)
    if (strcmp(s[i].phone, x.phone) == 0)
    {
      s[i].count++;
      return len;
    }
  for (i = 0; i < len; i++)
    if (strcmp(s[i].name, x.name) > 0 || strcmp(s[i].name, x.name) == 0 &&
                                             strcmp(s[i].phone, x.phone) > 0)
      break;
  if (i < len)
  {
    for (j = len; j > i; j--)
      s[j] = s[j - 1];
    s[i] = x;
    s[i].count = 1;
  }
  else
  {
    s[len] = x;
    s[len].count = 1;
  }
  return len+1;
}

int main()
{
  struct phonebook tb[10] = {{"an", "13112345678", 2},
                             {"deng", "13351513333", 1},
                             {"li", "18720152016", 2},
                             {"zhang", "13977778888", 1},
                             {"zhang", "18711119999", 1}};
  struct phonebook m;
  int i, ct = 5;
  scanf("%s %s", m.name, m.phone);
  ct = find_insert(tb, ct, m);
  for (i = 0; i < ct; i++)
    printf("% - 20s% - 20s%5d\n", tb[i].name, tb[i].phone, tb[i].count);
  getch();
  return 0;
}
