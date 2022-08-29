#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void)
{
    // input: 8진수, 최대 길이 333,334
    // output: 주어진 8진수를 2진수로 변환하여 출력, 0을 제외하고 반드시 1로 시작할 것
    int i = 0;

    char *oct = (char *)malloc(sizeof(char)*333335);
    scanf("%s", oct);

    // solution
    // special case: 0
    if(oct[0] == '0')
    {
        printf("0");
        return 0;
    }    
    
    // general case
    char bin[8][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};

    // i == 0, 수가 인 경우를 제외하고 반드시 1로 시작해야 한다.
    if(oct[i] == '1' || oct[i] == '2' || oct[i] == '3')
        printf("%d", atoi(bin[oct[i++]-48]));

    while(oct[i] != '\0')
        printf("%s", bin[oct[i++]-48]);

    return 0;
}
