#include <math.h>

int is_pandigital(int[9]);

int solution_1()
{
    int s = 0;
    int num[9];
    int n, t, d, f, b;
    for (int i = 1; i < 10000; i++)
    {
        n = 0;
        f = 0;
        t = 1;
        b = 0;
        while (1)
        {
            d = i * t;
            f *= pow(10, (int)log10(d) + 1);
            f += d;
            if (f < pow(10, 9) && f > 0)
            {
                while (d > 0)
                {
                    num[n] = d % 10;
                    d /= 10;
                    n++;
                    if (n == 9)
                    {
                        if (d == 0 && is_pandigital(num) && s < f)
                        {
                            s = f;
                        }
                        b = 1;
                        break;
                    }
                }
                t++;
                if (b == 1)
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return s;
}

int is_pandigital(int num[9])
{
    int digits[10] = {0};
    int index;
    int b = 1;
    for (int i = 0; i < 9; i++)
    {
        if (digits[num[i]] == 1 || num[i] == 0)
        {
            b = 0;
            break;
        }
        else
        {
            digits[num[i]] = 1;
        }
    }
    return b;
}