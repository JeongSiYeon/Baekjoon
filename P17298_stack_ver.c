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
    int *result  = (int *)calloc(seriesN, sizeof(int));

    for(i = 0; i < seriesN; i++)
        scanf("%d%*c", &series[i]);
    
    push(&findIDX, 0);

    for(i = 1; i < seriesN; i++)
    {
        while(!StackIsEmpty(&findIDX) && series[Speek(&findIDX)] < series[i])
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