#include <math.h>
#include <stdlib.h>
#include <string.h>

void get_primes_array(int *, int);
int is_circular_array(int, int *);

int solution_2(int upper_limit)
{
    int *primes;
    int s = 0;
    primes = (int *)malloc((upper_limit + 1) * sizeof(int));
    memset(primes, 0, (upper_limit + 1) * sizeof(int));
    get_primes_array(primes, upper_limit);
    for (int i = 2; i < upper_limit; i++)
    {
        if (primes[i] == 0 && is_circular_array(i, primes))
        {
            s++;
        }
    }
    return s;
}

void get_primes_array(int *primes, int upper_limit)
{
    for (int i = 2; i <= upper_limit; i++)
    {
        if (primes[i] == 0 && i <= sqrt(upper_limit))
        {
            for (int j = i * i; j <= upper_limit; j += i)
            {
                primes[j] = 1;
            }
        }
    }
}

int is_circular_array(int value, int *primes)
{
    int n, v;
    int b = 1;
    n = (int)log10(value);
    v = value;
    for (int i = 0; i < n; i++)
    {
        v = v / 10 + v % 10 * pow(10, n);
        if (primes[v] == 1)
        {
            b = 0;
            break;
        }
    }
    return b;
}
