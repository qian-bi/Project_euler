#include <math.h>

int count_divisor(int num)
{
    int cnt = 2;
    int sqr;
    switch (num)
    {
    case 1:
        cnt = 1;
        break;
    case 2:
        cnt = 2;
        break;
    case 3:
        cnt = 2;
        break;
    case 4:
        cnt = 3;
        break;
    default:
        sqr = (int)sqrt((double)num);
        for (int i = 3; i <= sqr; i++)
        {
            if (num % i == 0)
            {
                cnt += 2;
            }
        }
        if (num / sqr == sqr)
        {
            cnt--;
        }
        break;
    }
    return cnt;
}

int solution_1(int cnt)
{
    int num = 0;
    int i = 1;
    while (1)
    {
        num = i * (i + 1) / 2;
        if (count_divisor(num) > cnt)
        {
            break;
        }
        i++;
    }
    return num;
}