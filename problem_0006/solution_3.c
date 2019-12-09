int solution_3(int upper_limit)
{
    int s;
    s = (3 * upper_limit + 2) * (upper_limit + 1) * (upper_limit - 1) * upper_limit / 12;
    return s;
}
