#include <math.h>

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

int solution_1(int index)
{
    int p = 0;
    int num = 1;
    while (p < index)
    {
        num++;
        if (is_prime(num))
        {
            p++;
        }
    }
    return num;
}