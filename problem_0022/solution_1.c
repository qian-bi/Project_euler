#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    char *name;
    int length;
} Name;

void namecpy(Name *dest, Name *src)
{
    dest->length = src->length;
    dest->name = (char *)malloc(sizeof(char) * src->length);
    for (int i = 0; i < src->length; i++)
    {
        dest->name[i] = src->name[i];
    }
}

void bubble_sort(Name *name, int length)
{
    Name tmp;
    int l;
    for (int i = length; i >= 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (strcmp(name[j].name, name[j + 1].name) > 0)
            {
                namecpy(&tmp, &name[j + 1]);
                namecpy(&name[j + 1], &name[j]);
                namecpy(&name[j], &tmp);
                free(tmp.name);
            }
        }
    }
    
}

int solution_1(FILE *fp)
{
    Name *name;
    int cnt = 1;
    int length;
    char *tmp;
    int c1, c2, n = 0;
    int c, s = 0;

    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    tmp = (char *)malloc(sizeof(char) * length);
    fseek(fp, 0, SEEK_SET);
    fread(tmp, length, sizeof(char), fp);

    for (int i = 0; i < length; i++)
    {
        if (tmp[i] == ',')
        {
            cnt++;
        }
    }
    name = (Name *)malloc(sizeof(Name) * cnt);

    for (int i = 0; i < length; i++)
    {
        if (tmp[i] == '"')
        {
            i++;
            c1 = i;
            while (tmp[i] != '"')
            {
                i++;
            }
            c2 = i;
            name[n].length = c2 - c1 + 1;
            name[n].name = (char *)malloc((c2 - c1 + 1) * sizeof(char));
            for (int j = 0; j < c2 - c1; j++)
            {
                name[n].name[j] = tmp[c1 + j];
            }
            name[n].name[c2 - c1] = '\0';
            n++;
        }
    }

    bubble_sort(name, cnt);
    
    for (int i = 0; i < cnt; i++)
    {
        c = 0;
        for (int j = 0; j < name[i].length - 1; j++)
        {
            c += (int)(name[i].name[j] - 'A') + 1;
        }
        s += c * (i + 1);
    }

    free(tmp);
    for (int i = 0; i < cnt; i++)
    {
        free(name[i].name);
    }
    free(name);

    return s;
}