extern int InitYear;

int solution_1(int start, int end, int *days, int length)
{
    int d = 0, s = 0;

    for (int i = InitYear; i <= end; i++)
    {
        for (int j = 0; j < length; j++)
        {
            d = days[j] + d % 7;
            if (i % 4 == 0 && j == 1 && (i % 100 != 0 || i % 400 == 0))
            {
                d++;
            }
            if (d % 7 == 6 && i >= start)
            {
                s++;
            }
        }
    }
    if (d % 7 == 6)
    {
        s--;
    }
    return s;
}