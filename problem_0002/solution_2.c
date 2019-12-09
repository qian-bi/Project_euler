unsigned long even_fib()
{
    static unsigned long a = 0, b = 1;
    unsigned long tmp;
    tmp = a + b;
    a = tmp + b;
    b = tmp + a;
    return a;
}

unsigned long solution_2(unsigned long upper_limit)
{
    unsigned long f = 0, s = 0;
    while (f < upper_limit)
    {
        s += f;
        f = even_fib();
    }
    return s;
}
