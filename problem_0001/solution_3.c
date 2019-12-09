unsigned long solution_3(unsigned long upper_limit)
{
    unsigned long i = 0, b = 0;
    unsigned long s = 0;
    while (i * 3 < upper_limit)
    {
        b = (i * 5 < upper_limit) && (i % 3);
        switch (b)
        {
        case 1:
            s += i * 5;
        default:
            s += i * 3;
            break;
        }
        i++;
    }
    return s;
}