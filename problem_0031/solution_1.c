void rec_sol(int total, int *coins, int coin_index, int *s)
{
    int n = 0;
    if (total == 0 || coin_index == 0)
    {
        (*s)++;
    }
    else
    {
        while (total - coins[coin_index] * n >= 0)
        {
            rec_sol(total - coins[coin_index] * n, coins, coin_index - 1, s);
            n++;
        }
    }
}

int solution_1(int total, int *coins, int coins_count)
{
    int s = 0;
    rec_sol(total, coins, coins_count - 1, &s);
    return s;
}