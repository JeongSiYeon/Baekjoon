    // sol: 오등 큰수 문제를 오큰수 문제로 만들자
    //      연산은 횟수 배열로 하고 출력은 입력 배열로 한다.
    // 입력을 받으며 입력 배열과 횟수 배열을 채운다.
    // 각 숫자의 횟수는 각 인덱스에 저장한다.
    // 따라서 횟수를 저장하는 배열은 최대 크기여야 할 것이다.
    // 연산은 숫자의 인덱스로 횟수 배열에 접근하여 한다.


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int Data;

typedef struct _arraystack
{
    int top;
    Data *series;
} Stack;

void stackInit(Stack *pstack)
{
    pstack->top = -1;
    pstack->series  = (int *)malloc(sizeof(int)*1000000);
}

int StackIsEmpty(Stack *pstack)
{
    if(pstack->top == -1)
        return 1;
    else    
        return 0;
}

void push(Stack *pstack, Data data)
{
    if(pstack->top == 999999)
    {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    (pstack->top)++;
    pstack->series[pstack->top] = data;
}

int pop(Stack *pstack)
{
    int rdata;

    if(StackIsEmpty(pstack))
    {
        printf("Stack Memory Error!\n");
        exit(-1);
    }   

    rdata = pstack->series[pstack->top];
    (pstack->top)--;

    return rdata;
}

int Speek(Stack *pstack)
{
    if(StackIsEmpty(pstack))
    {
        printf("Stack Memory Error!\n");
        exit(-1);
    }  

    return pstack->series[pstack->top];
}

int main(void)
{
    int i, seriesN;
    Stack findIDX;
    stackInit(&findIDX);

    scanf("%d%*c", &seriesN);
    int *series  = (int *)malloc(sizeof(int)*seriesN);
    int *numCount = (int *)malloc(sizeof(int)*1000001);
    int *result  = (int *)calloc(seriesN, sizeof(int));

    for(i = 0; i < seriesN; i++)
    {
        scanf("%d%*c", &series[i]);
        numCount[series[i]]++;
    }
        
    push(&findIDX, 0);

    for(i = 1; i < seriesN; i++)
    {
        while(!StackIsEmpty(&findIDX) && numCount[series[Speek(&findIDX)]] < numCount[series[i]])
        {
            result[Speek(&findIDX)] = series[i];
            pop(&findIDX);
        }

        push(&findIDX, i);
    }

    while(!StackIsEmpty(&findIDX))
    {
        result[Speek(&findIDX)] = -1;
        pop(&findIDX);
    }

    for(i = 0; i < seriesN; i++)
        printf("%d ", result[i]);
    
    return 0;
}

