#include <math.h>
#include <stdlib.h>

typedef struct slist
{
    int value;
    struct slist *pre;
    struct slist *next;
} sList;

void free_list(sList *);
int is_prime_list(int, sList *);
void add_prime_list(sList *, int);
void get_primes_list(sList *, int);
int is_circular_list(int, sList *);

int solution_1(int upper_limit)
{
    sList *prime, *entry;
    int s = 0;
    prime = (sList *)malloc(sizeof(sList));
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

void free_list(sList *n)
{
    while (n->next != NULL)
    {
        n = n->next;
        free(n->pre);
    }
    free(n);
}

int is_prime_list(int n, sList *prime)
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

void add_prime_list(sList *prime, int value)
{
    sList *n, *l;
    int d = 0;
    n = prime;
    l = (sList *)malloc(sizeof(sList));
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

void get_primes_list(sList *prime, int upper_limit)
{
    for (int i = 3; i < upper_limit; i += 2)
    {
        if (is_prime_list(i, prime))
        {
            add_prime_list(prime, i);
        }
    }
}

int is_circular_list(int value, sList *prime)
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