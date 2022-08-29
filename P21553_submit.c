#include <stdio.h>
#include <string.h>

int main(void)
{
    int Plen = 0, Alen =0;
    // 숫자 1~9로 이루어져 있는 문자열 A, B
    // 비밀번호: 문자열 A와 문자열 B가 공통으로 가지는, 길이가 K인 문자열 (다수 가능)
    int P_idx;

    // input
    char A[101], P[101], B[101];
    // A ( 1<= P의 길이 (= K) <= A의 길이 <= 100)
    gets(A);
    // P
    gets(P);

    // sol
    Plen = strlen(P);
    Alen = strlen(A);

    // P's start index in A
    P_idx = (int) (strstr(A,P) - &A[0]);

    // special case
    // (1) |p| == |A| == 100: B = A
    if(Plen == 100 && Alen == 100)
    {
        strcpy(B, &A[P_idx]);
        printf("%s", B);
        return 0;
    }
    // (2) 1 <= |p| == |A| < 100: B = A + '1'
    else if(Plen == Alen)
    {
        strcpy(B, &A[P_idx]);
        B[Plen] = '1';
        B[Plen +1] = '\0';
        printf("%s", B);
        return 0;
    }

    // if P is head of A
    if(P_idx == 0)
    {
        // B = P + (original in A % 9 + 1)
        strcpy(B, &A[P_idx]);
        B[Plen] = (A[P_idx + Plen] - 48) % 9 + 1 + 48;
        B[Plen+1] = '\0';
    }
    // if P is tail of A or else 
    else 
    {
        // B = (original in A % 9 + 1) + P
        strcpy(&B[1],&A[P_idx]);
        B[0] = (A[P_idx -1] - 48) % 9 + 1 + 48;
        B[Plen + 1] = '\0';
    }

    // output
    printf("%s", B); 
    return 0;
}