#include <stdlib.h>

int solution_2(int upper_limit)
{
    int *p;
    int s = 1;

    p = (int *)malloc(sizeof(int) * upper_limit);
    for (int i = 0; i < upper_limit; i++)
    {
        p[i] = i + 1;
    }
    for (int i = 0; i < upper_limit; i++)
    {
        for (int j = i + 1; j < upper_limit; j++)
        {
            if (p[j] % p[i] == 0)
            {
                p[j] = p[j] / p[i];
            }
        }
        s *= p[i];
    }
    free(p);
    return s;
}