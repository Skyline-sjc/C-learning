#include <stdio.h>
void sort(int arrayl[3][3])
{
    int i = 0, j = 0, k = 0, temp = 0;
    for (k = 0; k < 3; k++)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (arrayl[k][j] > arrayl[k][j + 1])
                {
                    temp = arrayl[k][j];
                    arrayl[k][j] = arrayl[k][j + 1];
                    arrayl[k][j + 1] = temp;
                }
            }
        }
    }
    for (k = 0; k < 3; k++)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (arrayl[j][k] < arrayl[j + 1][k])
                {
                    temp = arrayl[j][k];
                    arrayl[j][k] = arrayl[j + 1][k];
                    arrayl[j + 1][k] = temp;
                }
            }
        }
    }
}
int main()
{
    FILE *p = fopen("myf2.out", "w");
    int arrayl[3][3] = {{1, 7, 6}, {2, 4, 8}, {5, 3, 9}};
    sort(arrayl);
    int i = 0, j = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", arrayl[i][j]);
        }
        printf("\n");
    }
        for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            fprintf(p,"%d ", arrayl[i][j]);
        }
        fprintf(p,"\n");
    }
    fclose(p);
    return 0;
}