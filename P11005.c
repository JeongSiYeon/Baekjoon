#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, remainN = 0, N, system;                      // 1 <= N <= 1 000 000 000

    char permutation[36][3] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
                               "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
                               "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
                               "U", "V", "W", "X", "Y", "Z"};

    scanf("%d %d%*c", &N, &system);     // 2 <= B <= 36
    int *remain = (int *)calloc(30, sizeof(int));
    // -> 저장, <- 출력

    while(N != 0)
    {
        remain[remainN++] = N % system;
        N = N / system;
    }

    for(i = remainN-1; i >= 0; i--)
        printf("%s", permutation[remain[i]]);

    return 0;
}