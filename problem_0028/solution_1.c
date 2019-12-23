int solution_1(int upper_limit)
{
    int s = 1, n = 1, d = 2;
    while (n < upper_limit * upper_limit)
    {
        for (int i = 0; i < 4; i++)
        {
            n += d;
            s += n;
        }
        d += 2;
    }
    return s;
}