#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int max(int rockN, int scissorN, int paperN);

int main(void)
{
    int i = 0, j = 0, R, N, realScore = 0, idealScore = 0;

    scanf("%d%*c", &R);

    char *sang = (char *)malloc(sizeof(char)*(R+1));
    scanf("%s", sang);

    char *temp     = (char *)malloc(sizeof(char)*(R+1));
    char *fRock    = (char *)calloc(R, sizeof(char));
    char *fScissor = (char *)calloc(R, sizeof(char));
    char *fPaper   = (char *)calloc(R, sizeof(char));

    scanf("%d%*c", &N);
    
    for(i = 0; i < N; i++)
    {
        scanf("%s%*c", temp);
        for(j = 0; j < R; j++)
        {
                 if(temp[j] == 'R') fRock[j]++;
            else if(temp[j] == 'S') fScissor[j]++;
            else if(temp[j] == 'P') fPaper[j]++;
        }
    }
        
    for(i = 0; i < R; i++)
    {
        if(sang[i] == 'R')
            realScore += (fScissor[i]*2 + fRock[i]*1);
        else if(sang[i] == 'S') 
            realScore += (fPaper[i]*2 + fScissor[i]*1);
        else if(sang[i] == 'P') 
            realScore += (fRock[i]*2 + fPaper[i]*1);
    }

    for(i = 0; i < R; i++)
        idealScore += max(fRock[i], fScissor[i], fPaper[i]);   
        
    printf("%d\n%d\n", realScore, idealScore);
    return 0;
}

int max(int rockN, int scissorN, int paperN)
{
    int tot1, tot2, tot3;

    tot1 = rockN*2 + paperN;
    tot2 = scissorN*2 + rockN;
    tot3 = paperN*2  + scissorN;

    if(tot1 >= tot2 && tot1 >= tot3)
        return tot1;
    if(tot2 >= tot3 && tot2 >= tot1)
        return tot2;
    if(tot3 >= tot1 && tot3 >= tot2)
        return tot3;
}