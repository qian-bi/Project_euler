#include <math.h>
#include <stdlib.h>

int solution_1(int p)
{
    int *d;
    int n;
    int s = 0;
    n = (int)(log10(2) * p) + 1;
    d = (int *)calloc(n, sizeof(int));
    d[n - 1] = 1;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[j] *= 2;
            if (d[j] > 9)
            {
                d[j] %= 10;
                d[j - 1]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        s += d[i];
    }
    free(d);
    return s;
}