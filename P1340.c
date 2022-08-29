#include <stdio.h>
#include <string.h>

int main(void)
{
    // input: Month DD, YYYY HH:MM
    char month_in[10] = {0,};
    char month_ref[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int date, year, month, hour, min, pastTime = 0, div = 525600;
    int month_date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 초기값: 평년의 각 달 당 날짜 수

    scanf("%s %d, %d %d:%d", month_in, &date, &year, &hour, &min);

    // month 판단
    for(int i = 0; i < 12; i++)
        if(strcmp(month_ref[i], month_in) == 0)
        {
            month = i+1;
            break;
        }
    
    // 1) 윤년, 평년 판단 => 각 달의 월 수 필요 시 변경, div 필요시 변경(초기값: 평년)
    if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        month_date[1] = 29;
        div += 1440;
    }
    
    // 해당 달의 1일로 맞춘다. ex) May 10, 1981 00:31의 경우, May 01, 1981 00:00
    for(int i = 0; i < month-1; i++)
        pastTime += month_date[i]*1440;
    
    pastTime += (date-1)*1440; // May 10, 1981 00:00
    
    pastTime += hour*60 + min;
    
    printf("%.15lf\n", 100*pastTime/(double)div);
    return 0;
}