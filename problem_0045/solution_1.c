#include <math.h>

int is_triangle(unsigned long long);
int is_pentagonal(unsigned long long);

unsigned long long solution_1(int lower_limit)
{
    unsigned long long s;
    int n = lower_limit;
    while (1)
    {
        s = n * (2 * n - 1);
        if (is_pentagonal(s) && is_triangle(s))
        {
            break;
        }
        n++;
    }
    return s;
}

int is_triangle(unsigned long long num)
{
    unsigned long long n;
    int b;
    n = (sqrt(8 * num + 1) - 1) / 2;
    if (n * (n + 1) / 2 == num)
    {
        b = 1;
    }
    else
    {
        b = 0;
    }
    return b;
}

int is_pentagonal(unsigned long long num)
{
    unsigned long long n;
    int b;
    n = (sqrt(24 * num + 1) + 1) / 6;
    if (n * (3 * n - 1) / 2 == num)
    {
        b = 1;
    }
    else
    {
        b = 0;
    }
    return b;
}