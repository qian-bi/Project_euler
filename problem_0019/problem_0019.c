/*
Counting Sundays

You are given the following information, but you may prefer to do some research for yourself.
1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <stdio.h>

int const InitYear = 1900;

int solution_1(int, int, int *, int);

int main()
{
    int start = 1901, end = 2000;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int length;
    int s1;

    length = sizeof(days) / sizeof(int);

    s1 = solution_1(start, end, days, length);

    printf("s1: %d\n", s1);
    return 0;
}