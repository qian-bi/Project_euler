int solution_1(int sum)
{
    int a, b, c;
    int s = 0;
    for (c = sum - 7; c > sum / 3; c--)
    {
        for (b = sum - c - 1; b > sum - c - b; b--)
        {
            a = sum - c - b;
            if (a * a + b * b == c * c)
            {
                s = a * b * c;
                break;
            }
        }
        if (s)
        {
            break;
        }
    }
    return s;
}