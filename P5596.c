#include <stdio.h>
#define SUBN 4

int main(void)
{
    short S = 0, T = 0; // S: min's total score, T: man's
    short min_score[SUBN] = {0,},  man_score[SUBN] = {0,};

    // input
    scanf("%hd %hd %hd %hd", &min_score[0],  &min_score[1], &min_score[2], &min_score[3]);
    scanf("%*c %hd %hd %hd %hd", &man_score[0], &man_score[1], &man_score[2], &man_score[3]);
    
    // sol
    for(int i = 0; i < SUBN; i++)
    {
        S += min_score[i];
        T += man_score[i];
    }

    // output
    if(S >= T)
        printf("%hd", S);
    else   
        printf("%hd", T);
    
    return 0;
}