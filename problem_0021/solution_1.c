#include <math.h>
#include <stdio.h>

int divisorsSum(int num)
{
    int s = 1;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (num / i == i)
            {
                s += i;
            }
            else
            {
                s += i + num / i;
            }
        }
    }
    // printf("n:%d,s:%d\n",num, s);
    return s;
}

int solution_1(int upper_limit)
{
    int s = 0;
    int n;
    for (int i = 1; i <= upper_limit; i++)
    {
        n = divisorsSum(i);
        if (n > i && i == divisorsSum(n))
        {
            s += i + n;
        }
    }
    return s;
}