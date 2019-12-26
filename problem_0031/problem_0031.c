/*
Coin sums

In the United Kingdom the currency is made up of pound (£) and pence (p).
There are eight coins in general circulation:
1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:
1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/

#include <stdio.h>

int solution_1(int, int *, int);
int solution_2(int, int *, int);

int main()
{
    int total = 200;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int coins_count;
    int s1, s2;

    coins_count = sizeof(coins) / sizeof(int);
    s1 = solution_1(total, coins, coins_count);
    s2 = solution_2(total, coins, coins_count);

    printf("s1: %d, s2: %d\n", s1, s2);
    return 0;
}