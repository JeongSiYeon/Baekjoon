#include <stdio.h>

int main(void)
{
    int i = 0, j = 0, max = 0;
    char rank[14] = "A23456789TJQK";
    int count[13] = {0,};

    // input
    char cards[15];
    gets(cards);

    // loop cards' rank
    for(i = 0; i < 5; i++)
    {
        // find the idx of card's rank
        j = 0;
        while(cards[i*3] != rank[j])
            j++;
        // rank num++
        count[j]++;
    }

    max = count[0];
    for(i = 1; i < 13; i++)
    {
        if(max < count[i])
            max = count[i];
    }
    printf("%d", max);
    return 0;
}