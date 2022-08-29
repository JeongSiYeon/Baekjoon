#include <stdio.h>

char str[7] = "가힣";
int main(void)
{
    for(int i = 0; str[i]; i++)
    {
        for(int j = 7; j >= 0; j--)
            printf("%d", (str[i]&(1<<j))?1:0);
        printf(" ");
    }
    return 0;
}