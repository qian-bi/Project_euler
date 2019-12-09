int solution_1(int *data, int d1, int d2, int index)
{
    int p1, p2, p3, p4;
    int i, j;
    int s = 0;
    for (i = 0; i < d1; i++)
    {
        for (j = 0; j < d2; j++)
        {
            p1 = 1;
            p2 = 1;
            p3 = 1;
            p4 = 1;
            if (i < d1 - index + 1)
            {
                for (int c = 0; c < index; c++)
                {
                    p1 *= data[(i + c) * d2 + j];
                }
                if (s < p1)
                {
                    s = p1;
                }
                if (j < d2 - index + 1)
                {
                    for (int c = 0; c < index; c++)
                    {
                        p3 *= data[(i + c) * d2 + j + c];
                    }
                    if (s < p3)
                    {
                        s = p3;
                    }
                }
                if (j > index - 2)
                {
                    for (int c = 0; c < index; c++)
                    {
                        p4 *= data[(i + c) * d2 + j - c];
                    }
                    if (s < p4)
                    {
                        s = p4;
                    }
                }
            }
            if (j < d2 - index + 1)
            {
                for (int c = 0; c < index; c++)
                {
                    p2 *= data[i * d2 + j + c];
                }
                if (s < p2)
                {
                    s = p2;
                }
            }
        }
    }
    return s;
}