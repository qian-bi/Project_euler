unsigned long long solution_2(unsigned long long num)
{
    unsigned long long p = 2;
    while (num > 1)
    {
        if (num % p == 0)
        {
            num /= p;
            p--;
        }
        p++;
    }
    return p;
}