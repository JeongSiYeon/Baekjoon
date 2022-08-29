#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[101];

    gets(word);
    printf("%d\n", strlen(word));
    
    return 0;
}