/*
Lattice paths

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

#include <stdio.h>

unsigned long long solution_1(int);
unsigned long long solution_2(int);

int main()
{
    int grid = 20;
    unsigned long long s1, s2;

    s1 = solution_1(grid);
    s2 = solution_2(grid);

    printf("s1: %llu, s2: %llu\n", s1, s2);
    return 0;
}