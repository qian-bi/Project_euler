#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 16

struct sList
{
    char value[NAME_SIZE];
    struct sList *next;
};
typedef struct sList NameList;

void insert_list(FILE *fp, NameList *head, int cnt)
{
    NameList *n, *name;
    n = head;
    name = (NameList *)malloc(sizeof(NameList));
    fscanf(fp, "\"%[a-zA-Z]\",", name->value);
    name->next = NULL;

    for (int i = 0; i < cnt; i++)
    {
        if ((strcmp(n->next->value, name->value) >= 0))
        {
            break;
        }
        n = n->next;
    }
    name->next = n->next;
    n->next = name;
}

int name_score(char name[])
{
    int i = 0, s = 0;
    while (name[i] != '\0')
    {
        s += (int)(name[i] - 'A') + 1;
        i++;
    }
    return s;
}

int total_score(NameList *head, int cnt)
{
    NameList *n;
    int s = 0;
    n = head;
    for (int i = 1; i <= cnt; i++)
    {
        n = n->next;
        s += name_score(n->value) * i;
    }
    return s;
}

void free_list(NameList *n)
{
    if (n->next != NULL)
    {
        free_list(n->next);
    }
    free(n);
}

int solution_2(FILE *fp)
{
    NameList *head;
    int cnt = 0;
    int s;

    fseek(fp, 0, SEEK_SET);
    head = (NameList *)malloc(sizeof(NameList));
    memset(head->value, '\0', NAME_SIZE);
    head->next = NULL;
    while (!feof(fp))
    {
        insert_list(fp, head, cnt);
        cnt++;
    }
    s = total_score(head, cnt);
    free_list(head);
    return s;
}