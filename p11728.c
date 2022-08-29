#include <stdio.h>
#include <stdlib.h>

int *merge(int *list_A, int *list_B, int arrSize_A, int arrSize_B)
{
    int i=0, j=0, loc_A=0, loc_B=0;
    int *merged_list=(int *)malloc(sizeof(int)*(arrSize_A+arrSize_B));

    while(loc_A<arrSize_A && loc_B<arrSize_B)
    {
        if(list_A[loc_A] <= list_B[loc_B])
            merged_list[i++]=list_A[loc_A++];
        
        else if(list_A[loc_A] > list_B[loc_B])
            merged_list[i++]=list_B[loc_B++];
    }

    if(loc_A!=arrSize_A)
        for(j=loc_A; j<arrSize_A; j++)
            merged_list[i++]=list_A[j];
        
    else
        for(j=loc_B; j<arrSize_B; j++)
            merged_list[i++]=list_B[j];

    return merged_list;
}

int *merge_sort(int *list, int start, int end)
{
    int mid=(start+end)/2;

    int *list_A     =(int *)malloc(sizeof(int)*(mid+1));
    int *list_B     =(int *)malloc(sizeof(int)*(end-mid));
    int *merged_list=(int *)malloc(sizeof(int)*(end+1));

    if(start!=end)
    {
        list_A     =merge_sort(list, start, mid); // 0이 아니라 start임
        list_B     =merge_sort(list, mid+1, end);
        merged_list=merge(list_A, list_B, mid-start+1, end-mid); // 0부터 시작한다고 계속 착각하고 있네

        return merged_list;
    }

    else
        return &list[start];
}

int main(void)
{
    int i, arrSize_A, arrSize_B;
    int *list_A, *list_B, *list_merged;

    scanf("%d %d%*c", &arrSize_A, &arrSize_B);
    
    list_A=(int*)malloc(sizeof(int)*arrSize_A);
    list_B=(int*)malloc(sizeof(int)*arrSize_B);
    list_merged=(int*)malloc(sizeof(int)*(arrSize_A+arrSize_B));

    for(i=0; i<arrSize_A; i++)
        scanf("%d%*c", &list_A[i]);

    for(i=0; i<arrSize_B; i++)
        scanf("%d%*c", &list_B[i]);

    list_A=merge_sort(list_A, 0, arrSize_A-1);
    list_B=merge_sort(list_B, 0, arrSize_B-1);
    list_merged=merge(list_A, list_B, arrSize_A, arrSize_B);

    for(i=0; i<arrSize_A+arrSize_B; i++)
        printf("%d ", list_merged[i]);

    return 0;
}