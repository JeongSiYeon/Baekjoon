#include <stdio.h>

int main(void)
{
    int i = 0, j = 0, max = 0;
    char rank[14] = "A23456789TJQK";
    int count[13] = {0,};

    // input:
    char cards[15];
    gets(cards);

    for(i = 0; i < 5; i++)
    {
        j = 0;
        while(rank[j] != cards[3*i])
            j++;
        count[j]++;
    }

    max = count[0];
    for(i = 1; i < 13; i++)
        if(max < count[i])
            max = count[i];

    printf("%d\n", max);
    return 0;
}