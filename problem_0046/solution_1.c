#include <stdlib.h>
#include <math.h>

typedef struct slist
{
    int value;
    struct slist *next;
} sList;

int is_prime(int);
sList *append_list(int, sList *);
void free_list(sList *);

int solution_1()
{
    int s = 3;
    int b = 1, v;
    sList *primes, *p, *pl;
    primes = (sList *)malloc(sizeof(sList));
    primes->value = 2;
    primes->next = NULL;
    pl = primes;
    while (1)
    {
        if (is_prime(s))
        {
            pl = append_list(s, pl);
        }
        else
        {
            p = primes;
            b = 0;
            while (p != NULL)
            {
                v = sqrt((s - p->value) / 2);
                if (v * v * 2 + p->value == s)
                {
                    b = 1;
                    break;
                }
                p = p->next;
            }
        }
        if (b == 0)
        {
            break;
        }
        s += 2;
    }
    free_list(primes);
    return s;
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

sList *append_list(int value, sList *pl)
{
    sList *l;
    l = (sList *)malloc(sizeof(sList));
    l->value = value;
    l->next = NULL;
    pl->next = l;
    return l;
}

void free_list(sList *n)
{
    if (n->next != NULL)
    {
        free_list(n->next);
    }
    free(n);
}