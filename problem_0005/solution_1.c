int divisor(int x, int y)
{
    int temp;
    if (x < y)
    {
        temp = y;
        y = x;
        x = temp;
    }
    while (x % y != 0)
    {
        temp = x % y;
        x = y;
        y = temp;
    }
    return y;
}

int solution_1(int upper_limit)
{
    int f;
    int s = 1;
    for (int i = 2; i < upper_limit; i++)
    {
        f = divisor(s, i);
        s *= i / f;
    }
    return s;
}