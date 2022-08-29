#include <stdio.h>
#include <stdlib.h>

typedef struct _person
{
    char name[61];
    char words[20];
} PERSON;

int main(void)
{
    int i, j, k, groupN = 0, nasty = 0;                  // (groupN)th group
    int personN[100] = {0,};                             // store participant in (groupN)th group
    PERSON *group[100];                                  // store PERSON array(s)

    while(1)
    {
        scanf("%d%*c", &personN[groupN]);

        if(personN[groupN] == 0) 
            break;

        group[groupN] = (PERSON *)calloc(personN[groupN], sizeof(PERSON));  // there are the number of personN people
        
        for(i = 0; i < personN[groupN]; i++)
        {
            scanf("%s%*c", (group[groupN]+i)->name);
            for(j = 0; j < personN[groupN]-1; j++)
                scanf("%c%*c", &( (group[groupN]+i)->words[j] ));
        }

        groupN++;
    }

    for(i = 0; i < groupN; i++)            // i loop group    groupN: 0(1st)
    {
        nasty = 0;
        printf("Group %d\n", i+1);

        for(j = 0; j < personN[i]; j++)    // j loop people     personN[0]: 5, j: 01234
        {
            for(k = 0; k < personN[i]-1; k++)       // k loop words     k: 0123
            {
                if( (group[i]+j)->words[k] == 'N' )
                {
                    nasty++;
                    printf("%s was nasty about %s\n", ( group[i]+ (j + personN[i]-1-k) % personN[i] ) ->name ,(group[i]+j)->name);
                }
            }
        }

        if(nasty == 0) printf("Nobody was nasty\n");
        printf("\n");
    }

    return 0;
}