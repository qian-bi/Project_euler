#include <math.h>
#include <stdlib.h>

typedef struct dlist
{
    int value;
    struct dlist *pre;
    struct dlist *next;
} dList;

int is_prime(int);
int next_prime(int);
dList *add_primes(dList *);
void free_list(dList *);

int solution_1(int upper_limit)
{
    dList *primes, *p, *p1, *p2;
    int v = 0, n = 0, b = 0;
    int s;
    primes = (dList *)malloc(sizeof(dList));
    primes->value = 2;
    primes->pre = NULL;
    primes->next = NULL;
    p = primes;
    while (v < upper_limit)
    {
        v += p->value;
        p = add_primes(p);
    }
    p = p->pre;
    while (1)
    {
        for (int i = 0; i <= n; i++)
        {
            s = v;
            p1 = primes;
            p2 = p;
            for (int j = 0; j < i; j++)
            {
                s -= p1->value;
                p1 = p1->next;
            }
            for (int j = 0; j < n - i; j++)
            {
                s -= p2->value;
                p2 = p2->pre;
            }
            if (is_prime(s) && s < upper_limit)
            {
                b = 1;
                break;
            }
        }
        if (b == 1)
        {
            break;
        }
        n++;
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

int next_prime(int value)
{
    if (value == 2)
    {
        value++;
    }
    else
    {
        while (1)
        {
            value += 2;
            if (is_prime(value))
            {
                break;
            }
        }
    }
    return value;
}

dList *add_primes(dList *last_primes)
{
    dList *p;
    p = (dList *)malloc(sizeof(dList));
    p->value = next_prime(last_primes->value);
    p->pre = last_primes;
    p->next = NULL;
    last_primes->next = p;
    return p;
}

void free_list(dList *n)
{
    while (n->next != NULL)
    {
        n = n->next;
        free(n->pre);
    }
    free(n);
}