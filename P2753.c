#include <stdio.h>

int main(void)
{
    int year;
    // 입력 
    // year (1 <= year <= 4000인 자연수)
    scanf("%d", &year);
    // 출력
    // 윤년이면 1, 아니면 0 출력
    // 윤년: 연도가 4의 배수 + 100의 배수가 아닐 때 또는 4의 배수 + 400의 배수
    if((year % 4 == 0 && year % 100 != 0) ||(year % 400 == 0))
    {
        printf("1");
    } 
    else 
    {
        printf("0");
    }
    return 0;
}