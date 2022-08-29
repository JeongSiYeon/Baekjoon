#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
    // Stack의 생성 및 초기화 ///////
    Stack stack;
    StackInit(&stack);

    // Data Input ///////
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);
    SPush(&stack, 5);

    // Data Output ///////
    while(stack.topIndex != -1)
        printf("%d\n", SPop(&stack));

    return 0;
}