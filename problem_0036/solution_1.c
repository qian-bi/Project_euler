#include <stdlib.h>
#include <math.h>

int is_palindromic_dec(int);
int is_palindromic_bin(int, int *);

int solution_1(int upper_limit)
{
    int *bin;
    int max_len, n;
    int s = 0;
    max_len = (int)(log(upper_limit) / log(2)) + 1;
    bin = (int *)malloc(max_len * sizeof(int));
    for (int i = 0; i <= upper_limit; i++)
    {
        if (is_palindromic_dec(i) && is_palindromic_bin(i, bin))
        {
            s += i;
        }
    }
    free(bin);
    return s;
}

int is_palindromic_dec(int value)
{
    int v1, v2 = 0;
    int b;
    v1 = value;
    while (value > 0)
    {
        v2 *= 10;
        v2 += value % 10;
        value /= 10;
    }
    if (v1 == v2)
    {
        b = 1;
    }
    else
    {
        b = 0;
    }
    return b;
}

int is_palindromic_bin(int value, int *bin)
{
    int n = 0;
    int b = 1;
    while (value > 0)
    {
        bin[n] = value % 2;
        value /= 2;
        n++;
    }
    for (int i = 0; i < n / 2; i++)
    {
        if (bin[i] != bin[n - i - 1])
        {
            b = 0;
            break;
        }
    }
    return b;
}
