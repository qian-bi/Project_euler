#include <math.h>
#include <stdlib.h>

int solution_1(int upper_limit)
{
    int s;
    int *base, d, n = 0;
    s = (upper_limit - 1) * (upper_limit - 1);
    base = (int *)malloc(2 * s * sizeof(int));
    for (int i = 2; i <= sqrt(upper_limit); i++)
    {
        if (i == 4 || i == 8 || i == 9)
        {
            continue;
        }
        for (int j = 2; pow(i, j) <= upper_limit; j++)
        {
            d = upper_limit / j - 1;
            s -= d;
            for (int k = d + 2; k <= upper_limit; k++)
            {
                base[n * 2] = i;
                base[n * 2 + 1] = j * k;
                n++;
            }
        }
    }
    for (int i = 2; i < 2 * n; i += 2)
    {
        for (int j = 0; j < i; j += 2)
        {
            if (base[j] == base[i] && base[j + 1] == base[i + 1])
            {
                s--;
                break;
            }
        }
    }
    free(base);
    return s;
}