#include <stdio.h>
#include <conio.h>
void d2b(int a[], int b[][8], int n)
{
  int i, k, j, t;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < 8; j++)
      b[i][j] = 0;
    k = a[i], j = 0;
    do
    {
      b[i][j++] = k % 2;
      k /= 2;
    } while (k);
    for (j = 0; j < 4; j++)
    {
      t = b[i][j];
      b[i][7 - j] = b[i][j];
      b[i][7 - j] = t;
    }
  }
}

int main()
{
  int a[3] = {255,0,253}, b[3][8], i, j;
  d2b(a,b,3);
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 8; j++)
      printf("%d", b[i][j]);
  }
  printf("\n");
  getch();
  return 0;
}
