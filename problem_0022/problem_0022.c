/*
Names scores

Using names.txt, a 46K text file containing over five-thousand first names, begin by sorting it
into alphabetical order. Then working out the alphabetical value for each name, multiply this value
by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth
3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of
938 × 53 = 49714.
What is the total of all the name scores in the file?
*/

#include <stdio.h>

int solution_1(FILE *);
int solution_2(FILE *);

int main()
{
    FILE *fp;
    int s1, s2;

    fp = fopen("problem_0022/names.txt", "r");
    s1 = solution_1(fp);
    s2 = solution_2(fp);

    fclose(fp);

    printf("s1: %d, s2: %d\n", s1, s2);
    return 0;
}