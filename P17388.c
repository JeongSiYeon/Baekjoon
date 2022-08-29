#include <stdio.h>

int main(void)
{
    short sum, min, minidx;
    short pr[3]; //  0 <= S, K, H <= 100 인 서로 다른 자연수
    char name[3][10] = {"Soongsil", "Korea", "Hanyang"};

    scanf("%hd %hd %hd", &pr[0], &pr[1], &pr[2]);
    sum = pr[0] + pr[1] + pr[2];

    if(sum < 100)
    {
        minidx = 0;
        for(int i = 1; i < 3; i++)
        {
            if(pr[minidx] > pr[i])
                minidx = i;
        }
        printf("%s", name[minidx]);
    }

    else    
        printf("OK\n");

    return 0;
}