/*
Lexicographic permutations

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
012   021   102   120   201   210
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <stdio.h>

unsigned long solution_1(int, int);

int main()
{
    int index = 1000000, m = 10;
    unsigned long s1;

    s1 = solution_1(index, m);

    printf("s1: %lu\n", s1);
    return 0;
}