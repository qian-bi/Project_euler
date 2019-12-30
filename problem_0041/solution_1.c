#include <math.h>

#define MAX_PANDIGITAL 7654321

int is_prime(int);
int is_pandigital(int);

int solution_1()
{
    for (int i = MAX_PANDIGITAL; i > 2; i -= 2)
    {
        if (is_pandigital(i) && is_prime(i))
        {
            return i;
        }
    }
    return 0;
}

int is_prime(int num)
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
        for (int i = 11; i < sqrt(num) + 1; i += 2)
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

int is_pandigital(int num)
{
    int digits[10] = {0};
    int n, d;
    int b = 1;
    n = log10(num) + 1;
    while (num > 0)
    {
        d = num % 10;
        if (d == 0 || d > n || digits[d] == 1)
        {
            b = 0;
            break;
        }
        else
        {
            digits[d] = 1;
            num /= 10;
        }
    }
    return b;
}