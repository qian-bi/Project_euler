#include <stdlib.h>

int solution_1(int upper_limit)
{
    int *data, *abundant;
    int s, d, n = 0;
    data = (int *)malloc(upper_limit * sizeof(int));
    abundant = (int *)malloc(upper_limit * sizeof(int));
    for (int i = 0; i < upper_limit; i++)
    {
        d = i + 1;
        data[i] = d;
        s = 0;
        for (int j = 1; j < d / 2 + 1; j++)
        {
            if (d % j == 0)
            {
                s += j;
            }
        }
        if (s > d)
        {
            abundant[n] = d;
            n++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (abundant[i] + abundant[j] <= upper_limit)
            {
                data[abundant[i] + abundant[j] - 1] = 0;
            }
        }
    }
    s = 0;
    for (int i = 0; i < upper_limit; i++)
    {
        s += data[i];
    }
    free(data);
    free(abundant);
    return s;
}