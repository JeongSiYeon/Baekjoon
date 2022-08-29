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

    printf("%s", P);
    return 0;
}