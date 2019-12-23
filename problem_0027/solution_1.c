#include <stdlib.h>
#include <math.h>

int is_prime(int num)
{
    int b = 1;
    if (num < 2)
    {
        b = 0;
    }
    for (int i = 2; i <= sqrt((double)num); i++)
    {
        if (num % i == 0)
        {
            b = 0;
            break;
        }
    }
    return b;
}

int get_prime(int **prime, int upper_limit)
{
    int n = 0;
    for (int i = 2; i < upper_limit; i++)
    {
        if (is_prime(i))
        {
            (*prime)[n] = i;
            n++;
        }
    }
    return n;
}

int solution_1(int upper_limit)
{
    int *prime;
    int n;
    int a, b, l = 0, m;
    int s;
    prime = (int *)malloc(upper_limit * sizeof(int));

    n = get_prime(&prime, upper_limit);
    for (int i = 0; i < n; i++)
    {
        b = prime[i];
        for (int j = 0; j < n; j++)
        {
            a = prime[j] - b - 1;
            m = 2;
            while (is_prime(m * m + m * a + b))
            {
                m++;
            }
            if (l < m)
            {
                l = m;
                s = a * b;
            }
        }
    }
    free(prime);
    return s;
}