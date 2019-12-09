#include <math.h>

int is_prime(unsigned long long num)
{
    int b = 1;
    for (unsigned long long i = 2; i < (unsigned long long)sqrt((double)num) + 1; i++)
    {
        if (num % i == 0)
        {
            b = 0;
            break;
        }
    }
    return b;
}

unsigned long long solution_1(unsigned long long num)
{
    unsigned long long p = 0;
    for (unsigned long long i = 2; i < (unsigned long long)sqrt((double)num) + 1; i++)
    {
        if (num % i == 0)
        {
            if (is_prime(num / i))
            {
                p = num / i;
                break;
            }
            if (is_prime(i))
            {
                p = i;
            }
        }
    }
    return p;
}