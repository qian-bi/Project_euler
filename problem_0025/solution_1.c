#include <stdlib.h>
#include <string.h>

void fib(int **d1, int **d2, int digits)
{
    int *d;
    d = (int *)malloc(sizeof(int) * digits);
    memset(d, 0, sizeof(int) * digits);
    for (int i = 0; i < digits; i++)
    {
        d[i] += (*d1)[i] + (*d2)[i];
        if (d[i] > 9)
        {
            d[i + 1]++;
            d[i] %= 10;
        }
    }
    free(*d1);
    *d1 = *d2;
    *d2 = d;
}

int solution_1(int digits)
{
    int *d1, *d2;
    int n = 2;

    d1 = (int *)malloc(sizeof(int) * digits);
    d2 = (int *)malloc(sizeof(int) * digits);
    memset(d1, 0, sizeof(int) * digits);
    memset(d2, 0, sizeof(int) * digits);
    d1[0] = 1;
    d2[0] = 1;
    while (d2[digits - 1] == 0)
    {
        n++;
        fib(&d1, &d2, digits);
    }
    free(d1);
    free(d2);
    return n;
}