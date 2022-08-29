#include <stdio.h>

int main(void)
{
    short ang1, ang2, ang3; // 0 < ang < 180 

    scanf("%hd", &ang1);
    printf("[1] %hd %hd %hd\n\n", ang1, ang2, ang3);
    scanf("%*c %hd", &ang2);
    printf("[2] %hd %hd %hd\n\n", ang1, ang2, ang3);
    scanf("%*c %hd", &ang3);
    printf("[3] %hd %hd %hd\n\n", ang1, ang2, ang3);

    printf("[4] %hd %hd %hd\n\n", ang1, ang2, ang3);

    // 내각의 합이 180이 아닌 경우
    if(ang1 + ang2 + ang3 != 180)
        printf("Error\n");
    // 모든 각이 같은 경우
    else if(ang1 == 60 && ang2 == 60 && ang3 == 60)
        printf("Equilateral\n");
    // 같은 각이 없는 경우 
    else if(ang1 != ang2 && ang1 != ang3 && ang2 != ang3)
        printf("Scalene\n");
    // 두 각이 같은 경우
    else
        printf("Isosceles\n");

    return 0;
}