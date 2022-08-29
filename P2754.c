#include <stdio.h>
#include <string.h>

typedef struct grade2score
{
    char grade[3];
    double score;
} CONVERT;

int main(void)
{
    int i = 0;
    char grade[3];
    CONVERT REF[13] = {{"A+", 4.3}, {"A0", 4.0}, {"A-", 3.7}, {"B+", 3.3}, {"B0", 3.0}, {"B-", 2.7},
                       {"C+", 2.3}, {"C0", 2.0}, {"C-", 1.7}, {"D+", 1.3}, {"D0", 1.0}, {"D-", 0.7}, {"F", 0.0}};
    scanf("%s", grade);

    while(strcmp(REF[i].grade, grade))
    {
        i++;
    }
    printf("%.1lf", REF[i].score);

    return 0;
}