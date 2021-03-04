#include <stdio.h >
#include <conio.h >
int leap(int year)
{
   int y;
   y = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
   return y;
}
void month_day(int year, int yearday, int *month, int *day)
{
   int k, p;
   int tab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
   p = leap(year);
   for (k = 1; yearday > 0; k++)
      yearday = yearday - tab[p][k];
   *month = k-1;
   *day = yearday+tab[p][k-1];
}
int main()
{
   int year, days, month, day;
   printf("Input year and days ! \n");
   scanf("%d,%d", &year, &days);
   if (leap(year) == 1 && days <= 366 || leap(year) == 0 && days <= 365)
   {
      month_day(year, days,&month,&day);
      printf("\n%d/%d/%d", year, month, day);
   }
   else
      puts("days is Wrong!");
   getch();
   return 0;
}