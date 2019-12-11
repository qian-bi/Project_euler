#include <math.h>
#include <stdlib.h>

int solution_1(int upper_limit)
{
    double digits = 0;
    int length, n;
    int *num;
    int s = 0;

    for (int i = 2; i <= upper_limit; i++)
    {
        digits += log10(i);
    }
    length = (int)digits + 2;
    num = (int *)calloc(length, sizeof(int));
    num[length-1] = 1;
    for (int i = 2; i <= upper_limit; i++)
    {
        for (int j = 1; j < length; j++)
        {
            num[j] *= i;
            n = (int)log10(i)+2;
            for (int k = 0; k <= n; k++)
            {
                num[j-k-1]+=num[j-k]/10;
                num[j-k]%=10;
            }
            num[j]%=10;
        }
    }
    for (int i = 0; i < length; i++)
    {
        s += num[i];
    }
    return s;
}