#include <stdlib.h>

int solution_1(int *data, int length)
{
    int *sum;
    int s = 0;

    sum = (int *)malloc(length * length * sizeof(int));
    sum[0] = data[0];

    for (int i = 1; i < length; i++)
    {
        sum[i * length] = sum[(i - 1) * length] + data[i * length];
        for (int j = 1; j < i; j++)
        {
            if (sum[(i - 1) * length + j] > sum[(i - 1) * length + j - 1])
            {
                sum[i * length + j] = sum[(i - 1) * length + j] + data[i * length + j];
            }
            else
            {
                sum[i * length + j] = sum[(i - 1) * length + j - 1] + data[i * length + j];
            }
        }
        sum[i * (length + 1)] = sum[(i - 1) * (length + 1)] + data[i * (length + 1)];
    }
    for (int i = 1; i <= length; i++)
    {
        if (s < sum[length * length - i])
        {
            s = sum[length * length - i];
        }
    }
    free(sum);
    return s;
}