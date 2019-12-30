#include <math.h>

int is_prime(int);
int is_truncatable_prime(int);

int solution_1(int cnt)
{
    int p1[] = {2, 3, 5, 7};
    int p2[] = {3, 7};
    int p3[] = {1, 3, 7, 9};
    int l1, l2, l3, d;
    int k2, tmp;
    int n = 0;
    int digits = 2;
    int s = 0;
    l1 = sizeof(p1) / sizeof(int);
    l2 = sizeof(p2) / sizeof(int);
    l3 = sizeof(p3) / sizeof(int);
    while (1)
    {
        for (int i = 0; i < l1; i++)
        {
            for (int j = 0; j < l2; j++)
            {
                for (int k = 0; k < pow(l3, digits - 2); k++)
                {
                    k2 = k;
                    tmp = 0;
                    for (int m = 0; m < digits - 2; m++)
                    {
                        tmp *= 10;
                        tmp += p3[k2 % l3];
                        k2 /= l3;
                    }
                    d = p1[i] * pow(10, digits - 1) + p2[j] + tmp * 10;
                    if (is_truncatable_prime(d))
                    {
                        s += d;
                        n++;
                        if (n == cnt)
                        {
                            return s;
                        }
                        
                    }
                }
            }
        }
        digits++;
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

int is_truncatable_prime(int num)
{
    int n = 10;
    while (num > n)
    {
        if (is_prime(num % n))
        {
            n *= 10;
        }
        else
        {
            return 0;
        }
    }
    while (num > 0)
    {
        if (is_prime(num))
        {
            num /= 10;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}