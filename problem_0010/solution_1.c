#include <math.h>

int is_prime(unsigned long long num)
{
    int b = 1;
    if (num == 2 || num == 3 || num == 5 || num == 7)
    {
        b = 1;
    }
    else if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0)
    {
        b = 0;
    }
    else
    {
        for (unsigned long long i = 11; i < (int)sqrt((double)num) + 1; i += 2)
        {
            if (num % i == 0)
            {
                b = 0;
                break;
            }
        }
    }
    return b;
}

unsigned long long solution_1(int upper_limit)
{
    unsigned long long i = 5;
    unsigned long long s = 5;
    while (i < upper_limit)
    {
        if (is_prime(i))
        {
            s += i;
        }
        i += 2;
    }
    return s;
}