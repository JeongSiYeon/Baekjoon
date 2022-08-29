#include <stdio.h>

void discrinimation(int arr[]);

int main(void)
{
    int i = 0, j = 1;
    int pitch[10];

    for(i = 0; i < 8; i++)
    {
        scanf("%d", &pitch[i]);
    } 
    
    discrinimation(pitch);
}

void discrinimation(int arr[])
{
    int i = 0, j = 0;

    while (arr[i] == i + 1)       // 첫 번째가 1인경우
    {
        if(i == 7) {
            printf("ascending\n");
            return;
        }
        i++;
    }

    while (arr[j] == 8-j) // 첫 번째가 8인경우
    {
        if(j == 7) {
            printf("descending\n");
            return;
        }
        j++;
    }

    printf("mixed");
}