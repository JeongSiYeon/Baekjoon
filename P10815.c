#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

// return pivot index
int partition(int list[], int start, int end);

// quick_sort
void quick_sort(int list[], int start, int end);

// binary search
int binary_search(int list[], int listSize, int key);

int main()
{
    int i, cardN, integerN, isExist;
    int *cardNums, *integerNum;

    // 숫자 카드의 개수 cardN (1 <= cardN <= 500 000)
    scanf("%d%*c\n", &cardN);

    // 숫자 카드에 적혀있는 수 (중복x, -10 000 000 <= cardNums <= 10 000 000)
    cardNums = (int *)malloc(sizeof(int)*cardN);
    for(i = 0; i < cardN; i++)
        scanf("%d%*c", &cardNums[i]);

    // 비교할 정수 (1 <= integerN <= 500 000) (-10 000 000 <= integerNum <= 10 000 000)
    scanf("%d%*c\n", &integerN);
    integerNum = (int *)malloc(sizeof(int)*integerN);
    for(i = 0; i < integerN; i++)
        scanf("%d%*c", &integerNum[i]);

    // 정렬(분할정복)->이진 탐색(분할정복)
    quick_sort(cardNums, 0, cardN-1);

    for(i = 0; i<integerN; i++)
    {
        isExist = binary_search(cardNums, cardN, integerNum[i]);
        printf("%d ", isExist);
    }

    return 0;
}


int partition(int list[], int start, int end)
{
    int pivot, temp;
    int left, right;
    
    right = end;
    left = start+1;
    pivot = list[start];

    while(left<=right)
    {
        while(left<=end && list[left]<pivot)
            left++;

        while(right>=start && list[right]>pivot)
            right--;
        
        if(left<right)
            SWAP(list[left], list[right], temp);
    }

    SWAP(list[start], list[right], temp);
    return right;
}

// in-place quick_sort
void quick_sort(int list[], int start, int end)
{
    int pivotIDX;

    if(start<end){
        pivotIDX=partition(list, start, end);

        quick_sort(list, start, pivotIDX-1);
        quick_sort(list, pivotIDX+1, end);
    }
}

// binary search
int binary_search(int list[], int listSize, int key)
{
    int mid, left=0, right=listSize-1;

    while(left<=right)
    {
        mid=(left+right)/2;
    
        if(list[mid]==key)
            return 1;

        else if(list[mid]>key)
            right=mid-1;

        else
            left=mid+1;
    }
    return 0;
}