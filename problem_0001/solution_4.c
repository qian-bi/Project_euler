unsigned long solution_4(unsigned long upper_limit)
{
    unsigned long c1, c2, c3;
    unsigned long s = 0;

    c1 = (upper_limit - 1) / 3;
    c2 = (upper_limit - 1) / 5;
    c3 = (upper_limit - 1) / 15;

    s = 3 * c1 * (c1 + 1) / 2 + 5 * c2 * (c2 + 1) / 2 - 15 * c3 * (c3 + 1) / 2;
    return s;
}