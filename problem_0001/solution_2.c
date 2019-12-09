unsigned long solution_2(unsigned long upper_limit)
{
    unsigned long i = 0;
    unsigned long s = 0;
    while (i * 3 < upper_limit)
    {
        s += i * 3;
        if ((i * 5 < upper_limit) && (i % 3))
        {
            s += i * 5;
        }
        i++;
    }
    return s;
}