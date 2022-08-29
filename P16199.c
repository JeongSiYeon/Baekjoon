#include <stdio.h>

typedef struct _date
{
    int year;
    int month;
    int day;
} DATE;

int main(void)
{

    /*
    만 나이  : 태어나면 0살, 생일 지날 때 마다 +1
    세는 나이: 태어나면 1살, 연도 바뀔 때마다 +1
    연 나이  : 태어나면 0살, 연도 바뀔 때마다 +1
    */
    DATE stand, person;
    int sub_year = 0;

    scanf("%d %d %d%*c", &person.year, &person.month, &person.day);
    scanf("%d %d %d%*c", &stand.year, &stand.month, &stand.day);

    sub_year = stand.year - person.year;
    // 만 나이
    if(stand.month < person.month || (stand.month == person.month && stand.day < person.day))
        printf("%d\n", sub_year - 1);
    else
        printf("%d\n", sub_year);
    
    printf("%d\n", sub_year+1);
    printf("%d\n", sub_year);

    return 0;
}