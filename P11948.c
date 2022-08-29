#include <stdio.h>
#define SUBN 6

int main(void)
{
    short score[SUBN] = {0,}, science_tot = 0, max = 0;        // 0 <= score[i] <= 100, i = 0,1,2,3,4,5

    for(int i = 0; i < SUBN; i++)
        scanf("%hd%*c", &score[i]);
    
    science_tot = score[0] + score[1] + score[2] + score[3];
    max = science_tot - score[0];

    for(int i = 1; i < 4; i++)
        if(max < science_tot-score[i])
            max = science_tot-score[i];

    if(score[4] >= score[5])
        printf("%hd", max+score[4]);  
    else
        printf("%hd", max+score[5]);    

    return 0;
}