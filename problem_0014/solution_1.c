int count_collatz_1(unsigned long long n)
{
    int cnt = 1;

    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            cnt++;
        }
        else
        {
            n *= 3;
            n++;
            cnt++;
        }
    }
    return cnt;
}

int solution_1(int upper_limit)
{
    int s = 0, c = 0, p = 0;
    for (int i = upper_limit; i > 0; i--)
    {
        c = count_collatz_1(i);
        if (c > p)
        {
            p = c;
            s = i;
        }
    }
    return s;
}