#define DIGITS_CNT 10
#define MAX_DATA 10000000

int sum_fac(int data, int *fac)
{
    int f = 0;
    while (data > 0)
    {
        f += fac[data % 10];
        data /= 10;
    }

    return f;
}

int solution_1()
{
    int fac[DIGITS_CNT];
    int f = 1;
    int s = 0;
    fac[0] = 1;
    for (int i = 1; i < DIGITS_CNT; i++)
    {
        f *= i;
        fac[i] = f;
    }
    for (int i = 3; i < MAX_DATA; i++)
    {
        if (i == sum_fac(i, fac))
        {
            s += i;
        }
    }
    return s;
}