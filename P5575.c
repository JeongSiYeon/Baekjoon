#include <stdio.h>

void calculator(short startTT[3], short endTT[3], short result[3]);

int main(void)
{
    short A_s[3], B_s[3], C_s[3];
    short A_e[3], B_e[3], C_e[3];
    short R[3];

    scanf("%hd %hd %hd %hd %hd %hd%*c", &A_s[0], &A_s[1], &A_s[2], &A_e[0], &A_e[1], &A_e[2]);
    scanf("%hd %hd %hd %hd %hd %hd%*c", &B_s[0], &B_s[1], &B_s[2], &B_e[0], &B_e[1], &B_e[2]);
    scanf("%hd %hd %hd %hd %hd %hd%*c", &C_s[0], &C_s[1], &C_s[2], &C_e[0], &C_e[1], &C_e[2]);

    calculator(A_s, A_e, R);
    calculator(B_s, B_e, R);
    calculator(C_s, C_e, R);

    return 0;
}

void calculator(short startTT[3], short endTT[3], short result[3])
{
    if(endTT[2] < startTT[2])
    {
        endTT[1]--;
        result[2] = 60 + endTT[2] - startTT[2];
    }
    else
        result[2] = endTT[2] - startTT[2];

    if(endTT[1] < startTT[1])
    {
        endTT[0]--;
        result[1] = 60 + endTT[1] - startTT[1];
    }
    else
        result[1] = endTT[1] - startTT[1];

    result[0] = endTT[0] - startTT[0];
    printf("%hd %hd %hd\n", result[0], result[1], result[2]);
}
