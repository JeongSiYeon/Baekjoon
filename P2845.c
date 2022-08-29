#include <stdio.h>

int main(void)
{
    int L, P, tot;
    int N1, N2, N3, N4, N5;
    scanf("%d %d", &L, &P);
    
    tot = L * P;
    scanf("%d %d %d %d %d", &N1, &N2, &N3, &N4, &N5);
    printf("%d %d %d %d %d\n", N1-tot, N2-tot, N3-tot, N4-tot, N5-tot);

    return 0;
}