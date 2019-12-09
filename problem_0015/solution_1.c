#include <stdlib.h>

unsigned long long solution_1(int grid)
{
    int n;
    unsigned long long *data, s;

    n = grid + 1;
    data = (unsigned long long *)malloc(n * n * sizeof(unsigned long long));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i * j == 0)
            {
                data[i * n + j] = 1;
            }
            else
            {
                data[i * n + j] = data[(i - 1) * n + j] + data[i * n + j - 1];
            }
        }
    }
    s = data[n * n - 1];
    free(data);
    return s;
}