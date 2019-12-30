#include <math.h>

#define DIGITS_CNT 4

int is_prime(int);
int prime_permutations(int, int *);
int next_pandigital(int *);
void swap(int *, int *);

void solution_1(int *s)
{
    int d[24];
    int t, cnt;
    for (int i = 1123; i < 7789; i += 2)
    {
        if (is_prime(i) && i != 1487)
        {
            cnt = prime_permutations(i, d);
            if (cnt >= 3)
            {
                for (int j = 1; j < cnt - 1; j++)
                {
                    for (int k = j + 1; k < cnt; k++)
                    {
                        if (d[k] - d[j] == d[j] - d[0])
                        {
                            s[0] = d[0];
                            s[1] = d[j];
                            s[2] = d[k];
                            return;
                        }
                    }
                }
            }
        }
    }
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
        for (int i = 11; i < (int)sqrt((double)num) + 1; i += 2)
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

int prime_permutations(int num, int *permutations)
{
    int digits[DIGITS_CNT];
    int n = DIGITS_CNT;
    int d;
    permutations[0] = num;
    while (num > 0)
    {
        n--;
        digits[n] = num % 10;
        num /= 10;
    }
    while (next_pandigital(digits) == 1)
    {
        d = 0;
        for (int i = 0; i < DIGITS_CNT; i++)
        {
            d *= 10;
            d += digits[i];
        }
        if (is_prime(d))
        {
            n++;
            permutations[n] = d;
        }
    }
    n++;
    return n;
}

int next_pandigital(int *digits)
{
    int b = 1;
    int index = DIGITS_CNT - 1;
    int p;
    while (index > 0 && digits[index] <= digits[index - 1])
    {
        index--;
    }
    if (index == 0)
    {
        b = 0;
    }
    else
    {
        p = index;
        for (int i = DIGITS_CNT - 1; i > index; i--)
        {
            if (digits[i] > digits[index - 1] && digits[i] < digits[p])
            {
                p = i;
            }
        }
        swap(&digits[p], &digits[index - 1]);
        for (int i = DIGITS_CNT - 1, j = index; i > j; i--, j++)
        {
            swap(&digits[i], &digits[j]);
        }
    }
    return b;
}

void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}