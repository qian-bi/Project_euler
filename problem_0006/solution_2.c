int solution_2(int upper_limit)
{
    int s1, s2, s;

    s1 = (2 * upper_limit + 1) * (upper_limit + 1) * upper_limit / 6;
    s2 = upper_limit * (upper_limit + 1) / 2;
    s = s2 * s2 - s1;
    return s;
}