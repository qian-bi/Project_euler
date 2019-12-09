int is_palindrome(int);

int solution_3(int upper_limit)
{
    int a, b, d;
    int s = 0;
    a = upper_limit - 1;
    while (a > upper_limit / 10)
    {
        if (a % 11 == 0)
        {
            b = upper_limit - 1;
            d = 1;
        }
        else
        {
            b = upper_limit / 11 * 11;
            d = 11;
        }
        while (b > a)
        {
            if (a * b <= s)
            {
                break;
            }
            if (is_palindrome(a * b))
            {
                s = a * b;
            }
            b -= d;
        }
        a--;
    }
    return s;
}