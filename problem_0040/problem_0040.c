/*
Champernowne's constant

An irrational decimal fraction is created by concatenating the positive integers:
0.123456789101112131415161718192021...
It can be seen that the 12th digit of the fractional part is 1.
If dn represents the nth digit of the fractional part, find the value of the following expression.
d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
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