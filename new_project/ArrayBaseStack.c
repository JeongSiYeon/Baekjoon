#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
    if(pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack * pstack, DATA data)
{
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

DATA SPop(Stack * pstack)
{
    int rIdx;

    if(SIsEmpty(pstack))
    {
        printf("Stack Memeory Error!\n");
        exit(-1);
    }

    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;

    return pstack->stackArr[rIdx];
}

DATA Speek(Stack * pstack)
{
    int rIdx;

    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    rIdx = pstack->topIndex;
    return pstack->stackArr[rIdx];
}