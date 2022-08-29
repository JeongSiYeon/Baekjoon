#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fibo(char *dp, int N);
void stringSum(char *s1, char *s2, char *result);

int main(void)
{
    int N;
    scanf("%d%*c", &N);

    if(N == 1 || N == 2)
    {
        printf("%d", N);
        return 0;
    }

    char *dp = (char *)calloc((N+1)*500, sizeof(char));
    fibo(dp, N);

    printf("%s\n", &dp[N*500]);
    return 0;
}

void fibo(char *dp, int N )
{
    strcpy(&dp[500*1], "1");
    strcpy(&dp[500*2], "2");

    for(int i = 3; i <= N; i++)
    {
        char result[500] = {0, };
        stringSum(&dp[(i-1)*500], &dp[(i-2)*500], result);
        if(result[0] == 0) strcpy(&dp[i*500], &result[1]); 
        else strcpy(&dp[i*500], result); 
    }
}


void stringSum(char *s1, char *s2, char *result)
{
    int res_loc = strlen(s1);
    int s2_loc =  strlen(s2) - 1;

    strcpy(&result[1], s1);

    for(int i = 0; i < strlen(s2); i++)
    {
        result[res_loc] = (result[res_loc]-48) + (s2[s2_loc]-48) + 48;

        if(result[res_loc] > '9')
        {
            if(result[res_loc-1] == 0) 
                result[res_loc-1] = '1';
    
            else
                result[res_loc-1] += 1;
                
            result[res_loc] -= 10;
        }

        res_loc--;
        s2_loc--;
    }
}
