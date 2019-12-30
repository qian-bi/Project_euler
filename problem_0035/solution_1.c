#include <math.h>
#include <stdlib.h>

typedef struct dlist
{
    int value;
    struct dlist *pre;
    struct dlist *next;
} dList;

void free_list(dList *);
int is_prime_list(int, dList *);
void add_prime_list(dList *, int);
void get_primes_list(dList *, int);
int is_circular_list(int, dList *);

int solution_1(int upper_limit)
{
    dList *prime, *entry;
    int s = 0;
    prime = (dList *)malloc(sizeof(dList));
    prime->value = 2;
    prime->pre = NULL;
    prime->next = NULL;
    get_primes_list(prime, upper_limit);
    entry = prime;
    while (entry != NULL)
    {
        if (is_circular_list(entry->value, prime))
        {
            s++;
        }
        entry = entry->next;
    }
    free_list(prime);
    return s;
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

int is_prime_list(int n, dList *prime)
{
    if (prime == NULL || prime->value > sqrt(n))
    {
        return 1;
    }
    else
    {
        if (n % prime->value == 0)
        {
            return 0;
        }
        else
        {
            return is_prime_list(n, prime->next);
        }
    }
}

void add_prime_list(dList *prime, int value)
{
    dList *n, *l;
    int d = 0;
    n = prime;
    l = (dList *)malloc(sizeof(dList));
    l->value = value;
    l->pre = NULL;
    l->next = NULL;
    while (n->next != NULL)
    {
        n = n->next;
    }
    n->next = l;
    l->pre = n;
}

void get_primes_list(dList *prime, int upper_limit)
{
    for (int i = 3; i < upper_limit; i += 2)
    {
        if (is_prime_list(i, prime))
        {
            add_prime_list(prime, i);
        }
    }
}

int is_circular_list(int value, dList *prime)
{
    int n, v;
    int b = 1;
    n = (int)log10(value);
    v = value;
    for (int i = 0; i < n; i++)
    {
        v = v / 10 + v % 10 * pow(10, n);
        if (!is_prime_list(v, prime))
        {
            b = 0;
            break;
        }
    }
    return b;
}