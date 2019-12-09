unsigned long solution_1(unsigned long upper_limit)
{
    unsigned long s = 0;
    for (unsigned long i = 0; i < upper_limit; i++)
    {
        if (!(i % 3 && i % 5))
        {
            s += i;
        }
    }
    return s;
}