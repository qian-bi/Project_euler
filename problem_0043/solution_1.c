#define DIGITS_CNT 10
#define PRIMES_CNT 7

void swap(int *, int *);
int next_pandigital(int *);

unsigned long long solution_1()
{
    int num[DIGITS_CNT] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
    int primes[PRIMES_CNT] = {2, 3, 5, 7, 11, 13, 17};
    int b;
    int d;
    unsigned long long ds, s = 0;
    while (next_pandigital(num))
    {
        b = 1;
        for (int i = 0; i < PRIMES_CNT; i++)
        {
            d = num[i + 1] * 100 + num[i + 2] * 10 + num[i + 3];
            if (d % primes[i] != 0)
            {
                b = 0;
                break;
            }
        }
        if (b == 1)
        {
            ds = 0;
            for (int i = 0; i < DIGITS_CNT; i++)
            {
                ds *= 10;
                ds += num[i];
            }
            s += ds;
        }
    }
    return s;
}

int next_pandigital(int *num)
{
    int b = 1;
    int index = DIGITS_CNT - 1;
    int p;
    while (index > 0 && num[index] < num[index - 1])
    {
        index--;
    }
    if (index == 0)
    {
        b = 0;
    }
    else
    {
        p = index;
        for (int i = DIGITS_CNT - 1; i > index; i--)
        {
            if (num[i] > num[index - 1] && num[i] < num[p])
            {
                p = i;
            }
        }
        swap(&num[p], &num[index - 1]);
        for (int i = DIGITS_CNT - 1, j = index; i > j; i--, j++)
        {
            swap(&num[i], &num[j]);
        }
    }
    return b;
}

void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}