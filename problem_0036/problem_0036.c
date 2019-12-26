/*
Double-base palindromes

The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
(Please note that the palindromic number, in either base, may not include leading zeros.)
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