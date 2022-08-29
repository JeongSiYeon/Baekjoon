#include <stdio.h>
#include <malloc.h>

int maker_3_5(int N);

int main(void)
{
    int num = 0;
    for(int i = 0; i < 200000000; i++)
    {
        num = maker_3_5(i+1);
        if(num == -1) printf("%d\n", i+1);
    }
        

    return 0;   
}

int maker_3_5(int N)
{
    int share, remainder;             // 3 <= N <= 5000
    
    share     = N / 5;
    remainder = N % 5;

    switch(remainder) 
    {
        case 0:
            return share;
            break;
        case 1:
            if(share >= 1) return (share-1) + 2; // 5*share + 1 => 5*(share-1) + 3*2
            break;
        case 2:
            if(share >= 2) return (share-2) + 4; // 5*share + 2 => 5*(share-2) + 3*4
            break;
        case 3:
            return share + 1;                    // 5*share + 3*1
            break;
        case 4:
            if(share >= 1) return (share-1) + 3; // 5*share + 4 => 5*(share-1) + 3*3
            break;
    }
    return -1;
}