#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // 0 <= num <= 99 인 정수
    // 0 <= num < 10: 0을 붙여 두 자리 수로 만들고
    // 각 자리의 숫자를 더한다.
    // 주어진 수의 가장 오른쪽 자리 수와 앞에서 구한 합의 가장 오른쪽 자리수를
    // 이어 붙이면 새로운 수를 만들 수 있다.

    // 26 => 2 + 6 = 8, 68
    int cycleN = 0, sum = 0;
    char num[3] = {0,}, temp[3] = {0,}, new_num[3] = {0,};
    
    scanf("%s", &num);
    strcpy(temp, num);

    do
    {
        sum = 0;

        if(atoi(temp) < 10)
        {
            temp[2] = '\0';
            temp[1] = temp[0];
            temp[0] = '0';
        }

        for(int i = 0; i < strlen(temp); i++)
            sum += temp[i]-48;

        new_num[0] = temp[strlen(temp)-1];

        if(new_num[0] == '0')
        {
            new_num[0] = (sum % 10) + 48;
            new_num[1] = '\0';
        }
        else
        {
            new_num[1] = (sum % 10) + 48; // 9 => 9, 99 => 9. 10 => 0, 11 => 1
            new_num[2] = '\0';
        }

        strcpy(temp, new_num);
        cycleN++;

    }  while(strcmp(num, new_num) != 0);

    printf("%d", cycleN);
    return 0;
}