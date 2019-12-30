#include <stdio.h>
#include <stdlib.h>

#define MAX_N 30

int solution_1(FILE *fp)
{
    int triangle_num[MAX_N];
    int length;
    char *tmp;
    int c, s = 0;

    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    tmp = (char *)malloc(sizeof(char) * length);
    fseek(fp, 0, SEEK_SET);
    fread(tmp, length, sizeof(char), fp);

    for (int i = 0; i < MAX_N; i++)
    {
        triangle_num[i] = i * (i + 1) / 2;
    }

    for (int i = 0; i < length; i++)
    {
        if (tmp[i] == '"')
        {
            i++;
            c = 0;
            while (tmp[i] != '"')
            {
                c += (int)(tmp[i] - 'A' + 1);
                i++;
            }
            for (int j = 0; j < MAX_N; j++)
            {
                if (triangle_num[j] == c)
                {
                    s++;
                    break;
                }
            }
        }
    }
    free(tmp);
    return s;
}