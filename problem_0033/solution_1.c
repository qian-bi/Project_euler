int gcd(int a, int b)
{
    int c;
    c = b % a;
    if (c == 0)
    {
        return a;
    }
    else
    {
        return gcd(c, a);
    }
}

int solution_1()
{
    int a, b;
    int n = 1, d = 1;
    int s = 1;
    for (int i = 1; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            a = i * 10 + j;
            for (int k = 1; k < 10; k++)
            {
                b = j * 10 + k;
                if (a * 1.0 / b == i * 1.0 / k)
                {
                    n *= a;
                    d *= b;
                }
            }
        }
    }
    s = d / gcd(n, d);
    return s;
}