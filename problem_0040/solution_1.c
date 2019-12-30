#include <math.h>

int solution_1(int upper_limit)
{
    int n = 1;
    int i = 0, v = 0;
    int s = 1;
    while (n <= upper_limit)
    {
        v++;
        i += (int)log10(v) + 1;
        if (i >= n)
        {
            s *= v / (int)pow(10, i - n) % 10;
            n *= 10;
        }
    }
    return s;
}