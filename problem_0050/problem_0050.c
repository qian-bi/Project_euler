/*
Consecutive prime sum

The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.
The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms,
and is equal to 953.
Which prime, below one-million, can be written as the sum of the most consecutive primes
*/

#include <stdio.h>

int solution_1(int);

int main()
{
    int upper_limit = 1000000;
    int s1;

    s1 = solution_1(upper_limit);

    printf("s1: %d\n", s1);
    return 0;
}