#include <stdio.h>
#include <conio.h>
#include <ctype.h>
int wordsearch(char a[], char b[][10])
{
   int i, j, k, m, n, t, c = 0, d;
   for (i = 0; a[i]!='\0'; i++)
   {
      for (j = i, k = i; isalpha(a[k]); k++)
         ;
      m = j;
      n = k - 1;
      while (toupper(a[m]) == toupper(a[n]) && m < n)
      {
         m++;
         n--;
      }
      if (m == n ||m-n==1)
      {
         for (d = 0, t = j; t < k; d++,t++)
            b[c][d] = a[t];
         b[c][d] = '\0';
         c++;
      }
      i = k;
   }
   return c;
}
int main()
{
   char *s1 = "Dad left home at noon.";
   char s2[10][10];
   int i, j;
   puts(s1);
   j = wordsearch(s1, s2);
   printf("found   % d  words\n", j);
   for (i = 0; i < j; i++)
      puts(s2[i]);
   getch();
   return 0;
}