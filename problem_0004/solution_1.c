int reverse(int num)
{
    int reversed = 0;
    while (num > 0)
    {
        reversed = 10 * reversed + num % 10;
        num /= 10;
    }
    return reversed;
}

int is_palindrome(int num)
{
    int b;
    if (num % 11 != 0)
    {
        b = 0;
    }
    else
    {
        b = num == reverse(num);
    }
    return b;
}

int solution_1(int upper_limit)
{
    int a, b;
    int s = 0;
    a = upper_limit - 1;
    while (a > upper_limit / 10)
    {
        b = upper_limit - 1;
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
            b--;
        }
        a--;
    }
    return s;
}