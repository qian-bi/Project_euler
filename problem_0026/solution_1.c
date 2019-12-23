#include <stdlib.h>

int len_rem(int n, int *rem, int upper_limit)
{
    int r = 1000;
    int l = 0;
    for (int i = 0; i < upper_limit; i++)
    {
        rem[i] = r % n;
        r = rem[i] * 10;
        for (int j = 0; j < i; j++)
        {
            if (rem[j] == rem[i])
            {
                l = i - j;
                r = 0;
            }
            break;
        }
        if (r == 0)
        {
            break;
        }
    }
    return l;
}

int solution_1(int upper_limit)
{
    int *rem;
    int l, ml = 0, s = 0;
    rem = (int *)malloc(upper_limit * sizeof(int));
    for (int i = 2; i < upper_limit; i++)
    {
        l = len_rem(i, rem, upper_limit);
        if (ml < l)
        {
            ml = l;
            s = i;
        }
    }
    free(rem);
    return s;
}