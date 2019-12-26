#include <stdlib.h>

#define DATA_COUNT 3

typedef struct slist
{
    int value;
    struct slist *next;
} sList;

int is_pandigital(int n[DATA_COUNT])
{
    int d[10] = {0};
    for (int i = 0; i < DATA_COUNT; i++)
    {
        while (n[i] > 0)
        {
            if (d[n[i] % 10] == -1 || n[i] % 10 == 0)
            {
                return 0;
            }
            else
            {
                d[n[i] % 10] = -1;
                n[i] /= 10;
            }
        }
    }
    return 1;
}

void append_list(sList *head, int value)
{
    sList *n, *l;
    int d = 0;
    n = head;
    l = (sList *)malloc(sizeof(sList));
    l->value = value;
    l->next = NULL;
    while (n->next != NULL)
    {
        n = n->next;
        if (n->value == value)
        {
            d = 1;
            break;
        }
    }
    if (d == 0)
    {
        n->next = l;
    }
}

int sum_list(sList *head)
{
    sList *n;
    n = head;
    int s = 0;
    while (n->next != NULL)
    {
        s += n->value;
        n = n->next;
    }
    s += n->value;
    return s;
}

void free_list(sList *n)
{
    if (n->next != NULL)
    {
        free_list(n->next);
    }
    free(n);
}

int solution_1()
{
    int s = 0;
    int value;
    int n[DATA_COUNT];
    sList *head;
    head = (sList *)malloc(sizeof(sList));
    head->value = 0;
    head->next = NULL;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1234; j < 9877; j++)
        {
            n[0] = i;
            n[1] = j;
            n[2] = i * j;
            if (is_pandigital(n))
            {
                value = i * j;
                append_list(head, value);
            }
        }
    }

    for (int i = 12; i < 99; i++)
    {
        for (int j = 123; j < 988; j++)
        {
            n[0] = i;
            n[1] = j;
            n[2] = i * j;
            if (is_pandigital(n))
            {
                value = i * j;
                append_list(head, value);
            }
        }
    }
    s = sum_list(head);
    free_list(head);
    return s;
}