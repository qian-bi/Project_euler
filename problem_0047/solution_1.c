#include <math.h>
#include <stdlib.h>

typedef struct slist
{
    int value;
    struct slist *next;
} sList;

int is_prime(int);
int primes_divisor(int, sList *);
sList *next_prime(sList *);
void free_list(sList *);

int solution_1(int cnt)
{
    int num = 4;
    int n = 0;
    int s;
    sList *primes;
    primes = (sList *)malloc(sizeof(sList));
    primes->value = 2;
    primes->next = NULL;
    while (1)
    {
        if (primes_divisor(num, primes) >= cnt)
        {
            n++;
        }
        else
        {
            n = 0;
        }
        if (n == cnt)
        {
            s = num - cnt + 1;
            break;
        }
        num++;
    }
    return s;
}

int primes_divisor(int num, sList *primes)
{
    int d = 0;
    sList *p;
    p = primes;
    while (p->value <= num)
    {
        if (num % p->value == 0)
        {
            num /= p->value;
            d++;
        }
        p = next_prime(p);
    }
    return d;
}

sList *next_prime(sList *p)
{
    int v;
    sList *l;
    if (p->next == NULL)
    {
        v = p->value;
        if (v == 2)
        {
            v++;
        }
        else
        {
            while (1)
            {
                v += 2;
                if (is_prime(v))
                {
                    break;
                }
            }
        }
        l = (sList *)malloc(sizeof(sList));
        l->value = v;
        l->next = NULL;
        p->next = l;
    }
    else
    {
        l = p->next;
    }
    return l;
}

int is_prime(int num)
{
    int b = 1;
    if (num == 2 || num == 3 || num == 5 || num == 7)
    {
        b = 1;
    }
    else if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0)
    {
        b = 0;
    }
    else
    {
        for (int i = 11; i < (int)sqrt((double)num) + 1; i += 2)
        {
            if (num % i == 0)
            {
                b = 0;
                break;
            }
        }
    }
    return b;
}

void free_list(sList *n)
{
    while (n->next != NULL)
    {
        free_list(n->next);
    }
    free(n);
}