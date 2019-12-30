int solution_1(int upper_limit)
{
    int a, b, c;
    int cnt, max_cnt = 0;
    int s;
    for (int i = 3; i <= upper_limit; i++)
    {
        cnt = 0;
        for (a = 1; a <= i / 3; a++)
        {
            for (b = a; b <= (i - a) / 2; b++)
            {
                c = i - a - b;
                if (a + b > c && a * a + b * b == c * c)
                {
                    cnt++;
                }
            }
        }
        if (cnt > max_cnt)
        {
            max_cnt = cnt;
            s = i;
        }
    }
    return s;
}