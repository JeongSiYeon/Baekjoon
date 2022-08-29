#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i = 0, j = 0, n = 0, blankN = 0;
    char counting[7000];
    char temp[10001];

    scanf("%d%*c", &n);
    gets(counting);

    // counting 순회
    // 숫자인 경우 내가 세고 있는 것과 같으면 계속, 아니면 fish 출력 후 return
    // 소문자인 경우 넘기기
    // 공백인 경우 blankN++
    // 다 순회한 경우 공백수 + 1 == n이면 (끝이 숫자인 경우 끝숫자 == n인지 판단 추가) ms 아니면 fifh 출력 후 return
    while(counting[i] != '\0')
    {
        printf("i: %d, counting[%i]: <%d> in integer, <%c> in character\n", i, i, counting[i]-48, counting[i]);

        // 첫 번째 경우 제외, 마지막 경우는 포함안됨 상태에서 공백 다음 글자 또는 숫자를 가리키도록
        if(counting[i] == ' ')
        {
            i++;
            printf("\n\n<%d> in integer or <%c> in character is blank. so i++ ===> i == %d\n", counting[i],counting[i], i);
        }    

        // temp를 순회할 인덱스 0으로 초기화
        j = 0;

        // 숫자인지 문자인지 판단하기 위해서 문자열 복사
        strcpy(temp, &counting[i]);
        printf("temp: <%s> for determinining num or char\n", temp);

        // 공백이 나올 때까지 i++ , 공백이 등장하면 blankN++ (최종적으로 i가 공백 다음을 가리키도록 한다.)
        while(temp[j] != ' ' && temp[j] != '\0')
        {
            printf("present temp[%d] is %c\n", j, temp[j]);
            j++;
        }
        printf("final j is %d\n", j);
        temp[j] = '\0';
        blankN++;
        // 자인 경우 최초로 등장하는 공백에 NULL을 할당하고 atoi 사용 => blankN과 비교하여 현재 숫자를 잘 세고 있는지 판단: o-> continue, x -> print and return 
        // 0인 경우: break
        if(temp[0] == '0')
        {
            printf("0 cannot be here\n");
            printf("something is fishy\n");
            return 0;
        }
        // 0이 아닌 정수인 경우
        else if(atoi(temp) != 0)
        {
            printf("integer without 0\n");
            if(atoi(temp) != blankN)
            {
                printf("miss counting\n");
                printf("something is fishy\n");
                return 0;
            } 
            // 현재 끝숫자인 경우
            if(counting[i+j] == '\0')
            {
                printf("it's final number\n");
                // 끝 숫자가 n이 아니라면
                if(atoi(temp) != n)
                {
                    printf("final num != n\n");
                    printf("something is fishy\n");
                    return 0;
                }
                else 
                    printf("final num != n\n");

            }
        }
        // 공백 또는 널을 가리킴
        i = i + j;
        printf("\n\nwhile last, new i: %d\n", i);
    }
    if(blankN == n)
        printf("makes sense");
    else
        printf("something is fishy\n");

    return 0;
}