int solution_1(int num)
{
    int ones_counts[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
    int tens_counts[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
    int cnt = 0;

    for (int i = 1; i <= num; i++)
    {
        if (i < 1000)
        {
            if (i >= 100)
            {
                cnt += ones_counts[i / 100] + 7;
                if (i % 100 != 0)
                {
                    cnt += 3;
                }
            }
            if (i % 100 < 20)
            {
                cnt += ones_counts[i % 100];
            }
            else
            {
                cnt += ones_counts[i % 10];
                cnt += tens_counts[(i % 100 - i % 10) / 10];
            }
        }
        else
        {
            cnt += ones_counts[i / 1000] + 8;
        }
    }
    return cnt;
}