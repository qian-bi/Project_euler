#include <math.h>

unsigned long long solution_1(char **data, int length, int digits)
{
    unsigned long long s = 0;
    int l, n = 0;
    l = length;
    while (l > 10)
    {
        l /= 10;
        n++;
    }
    for (int i = 0; i < digits + n; i++)
    {
        s *= 10;
        for (int j = 0; j < length; j++)
        {
            s += (int)(data[j][i] - '0');
        }
    }
    while (s > pow(10, digits))
    {
        s /= 10;
    }
    return s;
}