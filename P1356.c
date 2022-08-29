#include <stdio.h>
#include <string.h>

int main(void)
{
    char N[11];
    int i, j, front = 1, back = 1;

    scanf("%s", N); // N <= 2 147 483 647 인 자연수

    for(i = 0; i < strlen(N)-1; i++)
    {
        front *= (N[i]-48);

        back = 1;
        for(j = i+1; j < strlen(N); j++)
            back *= (N[j]-48);

        if(front == back)
        {
            printf("YES\n");
            return 0;
        }
    } 

    printf("NO\n");
    return 0;
}