#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int i, j, sum = 0, result = 0;
    char X[5], Y[5]; // 1 <= X, Y <= 1000 인 자연수
    scanf("%s %s", X, Y);

    // 거꾸로 자리수 맞춰서 *10 또는 *100 등 곱해주면 돼
    // X = 123 Y = 56
    // 300 + 700 + 20+60 + 1 + 5
    for(i = 0; i < strlen(X); i++)
        sum += (X[i]-48) * (int)round(pow(10, i)); 

    for(i = 0; i < strlen(Y); i++)
        sum += (Y[i]-48) * (int)round(pow(10, i)); 

    // 125
    int length = 0;
    while(sum / pow(10, length++) >= 10) {}

    j = 0;
    while(sum > 0) 
    {
        result += sum / (int)round(pow(10, length-j-1)) * (int)round(pow(10, j));
        sum -= (sum / (int)round(pow(10, length-j-1))) * (int)round(pow(10, length-j-1));
        j++;
    }

    printf("%d\n", result);
    return 0;
}