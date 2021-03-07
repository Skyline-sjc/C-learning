#include <stdio.h>
#include <conio.h>
void difference(char *s1,char *s2,char *s3)
{
  int count1, count2, count3 = 0;
  for (count1 = 0; s1[count1] != '\0'; count1++)
  {
    for (count2 = 0; s2[count2] != '\0'; count2++)
      if (s1[count1] == s2[count2])
        break;
    if (s2[count2] == '\0')
      s3[count3++] = s1[count1];
  }
  s3[count3] = '\0';
}

int main()
{
  char s1[20] = "good", s2[20] = "afternoon", s3[20];
  difference(s1, s2, s3);
  if (s3[0] !='\0')
    printf(" difference  is : % s\n", s3);
  else
    printf(" difference is empty\n");
  getch();
  return 0;
}
