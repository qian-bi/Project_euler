int solution_1(int upper_limit)
{
    int s1 = 0, s2 = 0;
    int s;

    for (int i = 1; i <= upper_limit; i++)
    {
        s1 += i * i;
        s2 += i;
    }
    s = s2 * s2 - s1;
    return s;
}