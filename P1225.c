#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
    long long result = 0;
    // input: A, B, 최대 10 000자리, 0 과 양수
    char *A = (char *)malloc(sizeof(char)*100000);
    char *B = (char *)malloc(sizeof(char)*100000); 

    scanf("%s %s", A, B);

    for(int i = 0; i < strlen(A); i++)
        for(int j = 0; j < strlen(B); j++)
            result += (A[i]-48) * (B[j]-48);

    printf("%lld\n", result);
    return 0;
}