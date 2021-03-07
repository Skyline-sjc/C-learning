#include <stdio.h>
#include <conio.h>
#define N 8
void move(int a[], int n, int m, int k);
int main()
{
  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8}, m, i, k;
  printf("Input m: \n");
  scanf("%d", &m);
  printf("Input k: \n");
  scanf("%d", &k);
  move(a,N,m,k);
  printf("result  \n");
  for (i = 0; i < N; i++)
    printf("%4d", a[i]);
  printf(" \n");
  getch();
  return 0;
}
void move(int a[], int n, int m, int k)
{
  int i, tmp;
  if (m < 0)
    return;
  while (m>0)
  {
    if (!k)
    {
      tmp = a[n - 1];
      for (i = n - 1; i > 0; i--)
        a[i] = a[i-1];
      a[0] = tmp;
    }
    else
    {
      tmp = a[0];
      for (i = 1; i < n; i++)
        a[i - 1] = a[i];
      a[n-1]= tmp;
    }
    m--;
  }
}
