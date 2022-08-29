#include <stdio.h>

int main(void)
{
    int N = 0, i;
    int lowerN  [100] = {0, };
    int upperN  [100] = {0, };
    int numberN [100] = {0, };
    int blankN  [100] = {0, };

    char element;

    while((element = getchar()) != EOF)
    {
        while(element != '\n')
        {
            if(97 <= element && element <= 122)
            {
                lowerN[N]++;
            }
            else if(65 <= element && element <= 90)
            {
                upperN[N]++;
            }
                
            else if(48 <= element && element <= 57)
            {
                numberN[N]++;
            }
                
            else
            {
                blankN[N]++;
            }
            scanf("%c", &element);
        }
        N++;
    }

    for(i = 0; i < N; i++)
        printf("%d %d %d %d\n", lowerN[i], upperN[i], numberN[i], blankN[i]);
    
    return 0;
}