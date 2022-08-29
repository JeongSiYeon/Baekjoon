#include <stdio.h>
#include <stdlib.h>

typedef struct _location
{
    int x;
    int y;
    int dis;
} LOCATION;

int main(void)
{
    LOCATION B, D, J;
    scanf("%d %d%*c", &B.x, &B.y);
    scanf("%d %d%*c", &D.x, &D.y);
    scanf("%d %d%*c", &J.x, &J.y);

    // distance (bessie and John)
    if(abs(B.x-J.x) >= abs(B.y-J.y))
        B.dis = abs(B.y-J.y) + (abs(B.x-J.x) - abs(B.y-J.y));
    else
        B.dis = abs(B.x-J.x) + (abs(B.y-J.y) - abs(B.x-J.x));        
    
    // distance (daisy and John)
    D.dis = abs(D.x-J.x) + abs(D.y-J.y);

    // compare
    if(B.dis > D.dis)
        printf("daisy\n");
    else if(B.dis < D.dis)
        printf("bessie\n");
    else
        printf("tie\n");

    return 0;
}