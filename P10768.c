#include <stdio.h>

int main(void)
{
    short month, day;
    scanf("%hd", &month);
    scanf("%*c%hd", &day);

    if(month == 2 && day == 18)
        printf("Special\n");
    else if ( (month == 1) || (month == 2 && day < 18))
        printf("Before\n");
    else
        printf("After\n");

    return 0;
}