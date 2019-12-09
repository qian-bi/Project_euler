/*
Special Pythagorean triplet

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <stdio.h>

int solution_1(int);
int solution_2(int);

int main()
{
    int sum = 1000;
    int s1, s2;

    s1 = solution_1(sum);
    s2 = solution_2(sum);

    printf("s1: %d, s2: %d\n", s1, s2);
    return 0;
}