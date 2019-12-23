#include <stdlib.h>

unsigned long solution_1(int index, int m)
{
    int *d, *r;
    int f = 1;
    unsigned long s = 0;
    double n;
    int c;

    d = (int *)malloc(m * sizeof(int));
    r = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        d[i] = f;
        r[i] = i;
        f *= i + 1;
    }
    for (int i = 0; i < m; i++)
    {
        n = index * 1.0 / d[m - i - 1];
        if (n == 0)
        {
            c = m - 1;
            while (r[c] == -1)
            {
                c--;
            }
        }
        else
        {
            c = 0;
            for (int j = 0; j < m; j++)
            {
                if (r[j] != -1)
                {
                    c++;
                }
                if (c >= n)
                {
                    c = j;
                    break;
                }
            }
        }

        s = s * 10 + r[c];
        r[c] = -1;
        index %= d[m - i - 1];
    }

    free(d);
    free(r);
    return s;
}
