#include <math.h>

unsigned long long solution_1(int upper_limit, int digits)
{
    unsigned long long d, s = 0;
    for (int i = 1; i <= upper_limit; i++)
    {
        d = 1;
        for (int j = 0; j < i; j++)
        {
            d *= i;
            if (d > pow(10, digits))
            {
                d %= (unsigned long long)pow(10, digits);
            }
        }
        s += d;
        if (s > pow(10, digits))
        {
            s %= (unsigned long long)pow(10, digits);
        }
    }
    return s;
}