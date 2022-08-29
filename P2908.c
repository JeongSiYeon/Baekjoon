#include <stdio.h>
#include <stdlib.h>

int char2int (char c);
void compare(char n1[], char n2[]);

int main(void)
{
    char num1[5], num2[5];

    scanf("%s %s", num1, num2);
    compare(num1, num2);
    
    return 0;
}

int char2int (char c)
{
    return c - 48;
}

void compare(char n1[], char n2[])
{
    int idx = 2, ret = 0;
    
    while(n1[idx] == n2[idx]) 
    {
        idx--;
    }

    if(n1[idx] > n2[idx])
    {
        ret += (100 * char2int(n1[2]));
        ret += ( 10 * char2int(n1[1]));
        ret += (  1 * char2int(n1[0]));

        printf("%d", ret);
    }
    else
    {
        ret += (100 * char2int(n2[2]));
        ret += ( 10 * char2int(n2[1]));
        ret += (  1 * char2int(n2[0]));

        printf("%d", ret);
    }
}