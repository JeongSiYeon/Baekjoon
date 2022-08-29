#include <stdio.h>

int main(void)
{
    int KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN; 
    scanf("%d %d %d %d %d %d", &KING, &QUEEN, &ROOK, &BISHOP, &KNIGHT, &PAWN);
    printf("%d %d %d %d %d %d", 1-KING, 1-QUEEN, 2-ROOK, 2-BISHOP, 2-KNIGHT, 8-PAWN);
    return 0;
}