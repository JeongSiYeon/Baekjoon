#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int i, oct, len, start= 0;
    char *bin = (char *)calloc(1000003, sizeof(char));
    
    scanf("%s%*c", bin);

    if(bin[0] == '0')
    {
        printf("0");
        return 0;
    }

    len = strlen(bin);
    start = strlen(bin) % 3;
    

    if(start == 1)
        printf("1");

    else if(start == 2)
    {
        if(bin[1] == '0')
            printf("2");
        else
            printf("3");
    }

    for(i = start; i < len; i+=3)
    {
        oct = (bin[i]-48)*4 + (bin[i+1]-48)*2 + (bin[i+2]-48)*1;
        printf("%d", oct);
    }
    
    return 0;
}