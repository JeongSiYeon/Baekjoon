#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void)
{
    int i = 0;
    char oct2bin8[8][5] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    char oct2bin3[4][5] = {" ", "1", "10", "11"};

    // input: octal (max length: 333,334)
    char *oct = (char *)malloc(sizeof(char)*333335);
    scanf("%s", oct);

    // special case: 0
    if(oct[0] == '0')
    {
        printf("0");
        return 0;
    }

    while(oct[i] != '\0')
    {
        if(i == 0 && (oct[i]-48 < 4)) 
            printf("%s", oct2bin3[oct[i]-48]);
        else 
            printf("%s", oct2bin8[oct[i]-48]);
        i++;
    }
    return 0;
}