#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0, j = 0;
    char N[1006], R[1006];       
    
    // input: N,  binary(without 0), 0 < length <= 1000
    // N: "0000\0"
    for(i = 0; i < 4; i++)
        N[i] = '0';

    // N: "0000" => "000010110111\0"
    scanf("%s", &N[4]);

    // R: "" => "10110111\0"
    strcpy(R, &N[4]);
    
    // N * 17 = N * 16 + N
    // <*16> R: "10110111\0" => "101101110000\0"
    i = 0;
    while(R[i] != '\0')
        i++;
    for(j = i; j < i+4; j++)
        R[j] = '0';
    R[j--] = '\0';
    
    // <+N> R: "101101110000(<-j)\0" => "110000100111\0"
    while(j > 0)
    {
        if(R[j] + N[j] > 97)        //////////////////////// 현재 자리수보다 왼쪽으로 더 늘어날 수 있다는 점
            R[j-1]++;

        if((R[j] + N[j]) % 2 == 0)
            R[j] = '0';
        else
            R[j] = '1';

        j--;
    }

    // j == 0
    if(R[j] + N[j] > 97)
        printf("%c", '1');

    if((R[j] + N[j]) % 2 == 0)
            printf("%c", '0');
    else
        printf("%c", '1');

    printf("%s\n", &R[1]);      // j == 0은 따로 처리했으므로 j ==1부터 뽑아야 한다는 것

    return 0;
}
