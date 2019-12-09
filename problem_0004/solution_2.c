int is_palindrome(int);

int solution_2(int upper_limit)
{
    int a, b, c;
    int s = 0;
    c = upper_limit * 2 - 1;
    while (c > upper_limit / 5)
    {
        a = c / 2;
        while (a < upper_limit)
        {
            b = c - a;
            if (is_palindrome(a * b))
            {
                s = a * b;
                break;
            }
            a++;
        }
        if (s)
        {
            break;
        }
        c--;
    }
    return s;
}