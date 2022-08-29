#include <stdio.h>

int main(void)
{
    int pieceN = 0;
    char chessBoardLine[9];
    for(int i = 0; i < 8; i++)
    {
        gets(chessBoardLine);
        for(int j = i % 2; j < 8; j += 2)
            if(chessBoardLine[j] == 'F') pieceN++;           
    }
    printf("%d\n", pieceN);    
    return 0;
}