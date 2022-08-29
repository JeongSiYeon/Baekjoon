#include <stdio.h>
#include <malloc.h>

int main(void)
{
    int N, i = 0, holder = 1, L_count = 0;
    scanf("%d", &N); // 1 <= N <= 50

    char *seat = (char *)malloc(sizeof(char)*(N+1));
    scanf("%s", seat);

    while(seat[i] != '\0')
    {
        holder++;
        if(seat[i] == 'S')
            i += 1;
            
        else
        {
            i += 2;
            L_count++;
        }  
    }

    if(L_count == 0)
        printf("%d", holder-1);
    else
        printf("%d", holder);
        
    return 0;
}