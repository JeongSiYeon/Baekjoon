#include <stdio.h>
#include <malloc.h>

void insertionSort(int arr_s[], int arr_t[], int arr_b[], int n);

int main(void)
{
    int i, j, k, N;

    // N: the number of cows
    scanf("%d", &N);

    int * s = (int *)malloc(sizeof(int)*N);
    int * t = (int *)malloc(sizeof(int)*N);
    int * b = (int *)malloc(sizeof(int)*N);
    int * r = (int *)malloc(sizeof(int)*N*10); 

    // input start time, end time, bucket numbers
    for(i = 0; i < N; i++)
    {
        // initilization r
        r[i] = 0;
        scanf("%d %d %d", &s[i], &t[i], &b[i]);
    }

    insertionSort(s, t, b, N);

    // ith cow
    for(i = 0; i < N; i++)
    {
        // loop for number(ith cow need)
        for(j = 0; j < b[i]; j++)
        {
            // loop for determining of reservation: r contains bucket i's using end time
            k = 0;
            while(r[k] > s[i])
            {
                k++;
            }
            // reservation complete
            r[k] = t[i];
        }
    }

    i = 0;
    while(r[i] != 0)
    {
        i++;
    }

    printf("%d", i);
    
    free(s);
    free(t);
    free(b);
    free(r);

    return 0;
}

void insertionSort(int arr_s[], int arr_t[], int arr_b[], int n)
{
    int key_s, key_t, key_b, i = 0, j = 0;

    for(i = 1; i < n ; i++)
    {
        key_s = arr_s[i];
        key_t = arr_t[i];
        key_b = arr_b[i];

        j = i - 1;

        while(key_s < arr_s[j])
        {
            arr_s[j+1] = arr_s[j];
            arr_t[j+1] = arr_t[j];
            arr_b[j+1] = arr_b[j];
            j--;
            if(j<0) break;
        } 

        arr_s[j+1] = key_s;
        arr_t[j+1] = key_t; 
        arr_b[j+1] = key_b;      
    }
}