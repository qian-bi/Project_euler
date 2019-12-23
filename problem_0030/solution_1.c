#include <math.h>

int solution_1(int p)
{
    int upper_limit, d, m;
    int n = 1;
    int s = 0;
    while (pow(9, p) * n > pow(10, n + 1))
    {
        n++;
    }
    n++;
    upper_limit = pow(9, p) * n;
    for (int i = 2; i <= upper_limit; i++)
    {
        d = i;
        m = 0;
        while (d > 0)
        {
            m += pow(d % 10, p);
            d /= 10;
        }
        if (m == i)
        {
            s += m;
        }
    }

    return s;
};