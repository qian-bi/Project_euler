#include <math.h>

int is_pentagonal(int);

int solution_1()
{
    int s;
    int p1, p2, ps, pd;
    int b = 0;
    int n = 2;
    while (1)
    {
        p1 = n * (3 * n - 1) / 2;
        for (int i = n - 1; i > 0; i--)
        {
            p2 = i * (3 * i - 1) / 2;
            ps = p1 + p2;
            pd = p1 - p2;
            if (is_pentagonal(ps) && is_pentagonal(pd))
            {
                b = 1;
                s = pd;
                break;
            }
        }
        if (b)
        {
            break;
        }
        n++;
    }
    return s;
}

int is_pentagonal(int num)
{
    int n;
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