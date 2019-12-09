#include <stdlib.h>

unsigned long long solution_2(int grid)
{
    unsigned long long s = 1;
    int *data;
    int n;
    n = grid - 1;
    data = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        data[i] = i + 2;
    }
    for (int i = 1; i <= grid; i++)
    {
        s *= (grid + i);
        for (int j = 0; j < n; j++)
        {
            if (s % data[j] == 0)
            {
                s /= data[j];
                n--;
                data[j] = data[n];
            }
        }
    }
    free(data);
    return s;
}