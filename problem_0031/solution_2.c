#include <stdlib.h>
#include <string.h>

int solution_2(int total, int *coins, int coins_count)
{
    int s = 0;
    int *ways;
    ways = (int *)malloc((total + 1) * sizeof(int));
    memset(ways, 0, (total + 1) * sizeof(int));
    ways[0] = 1;
    for (int i = 0; i < coins_count; i++)
    {
        for (int j = coins[i]; j <= total; j++)
        {
            ways[j] += ways[j - coins[i]];
        }
    }
    s = ways[total];
    free(ways);
    return s;
}