unsigned long long solution_1(int data[], int length, int n)
{
    unsigned long long p, s = 0;
    int c;
    for (int i = 0; i < length - n + 1; i++)
    {
        c = 0;
        p = 1;
        while (c < n)
        {
            p *= data[i + c];
            c++;
        }
        if (s < p)
        {
            s = p;
        }
    }
    return s;
}