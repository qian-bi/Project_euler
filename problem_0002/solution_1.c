unsigned long fib()
{
    static unsigned long a = 0, b = 1;
    unsigned long tmp;
    tmp = a;
    a = b;
    b = tmp + b;
    return b;
}

unsigned long solution_1(unsigned long upper_limit)
{
    unsigned long f = 0, s = 0;
    while (f < upper_limit)
    {
        if (f % 2 == 0)
        {
            s += f;
        }
        f = fib();
    }
    return s;
}
