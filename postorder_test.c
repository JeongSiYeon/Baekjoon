#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double Data;

typedef struct _node
{
    Data data;
    struct _node *link;
} Node;

typedef struct _stack
{
    Node *head;
} Stack;

void stakcInit(Stack *pstack);
void push(Stack *pstack, Data data);
Data  pop(Stack *pstack);
int  stackIsEmpty(Stack *pstack);

int main(void)
{
    int operandN, i = 0;
    double operand_1, operand_2, result;
    char posterior_notation[101];

    Stack stack;
    stakcInit(&stack);

    // input1: number of operand
    scanf("%d%*c", &operandN);      // 1 <= N <= 26

    // input2: posterior_notation
    gets(posterior_notation);

    // input3: numbers matching alphabet in order
    int *numbers = (int *)malloc(sizeof(int)*operandN);

    for(i = 0; i < operandN; i++)
        scanf("%d%*c", &numbers[i]);

    i = 0;

    // calculate with STACK
    while(posterior_notation[i] != '\0')
    {
        printf("currenT: %d %c\n", posterior_notation[i], posterior_notation[i]);

        if(65 <= posterior_notation[i] && posterior_notation[i] <= 90)
        {
            printf("push: %d\n", numbers[posterior_notation[i]-65]);
            push(&stack, (double)numbers[posterior_notation[i]-65]);
        }

        else
        {
            operand_2 = pop(&stack);
            operand_1 = pop(&stack);

            printf("operand_1: %f, operand_2: %f\n", operand_1, operand_2);

            if(posterior_notation[i] == '+')
                result = operand_1 + operand_2;
        
            else if(posterior_notation[i] == '-')
                result = operand_1 - operand_2;
                
            else if(posterior_notation[i] == '*')
                result = operand_1 * operand_2;

            else if(posterior_notation[i] == '/')
                result = operand_1 / operand_2;

            printf("calculate, input: %f\n", result);
            push(&stack, result);
        }    

        i++;  
    }

    result = pop(&stack);
    printf("%.2f", result);

    return 0;
}

void stakcInit(Stack *pstack)
{
    pstack->head = NULL;
}

int  stackIsEmpty(Stack *pstack)
{
    if(pstack->head == NULL)
        return 1;
    else
        return 0;
}

void push(Stack *pstack, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = pstack->head;
    pstack->head = newNode;
}

Data  pop(Stack *pstack)
{
    Node *delNode;
    Data delData;

    if(stackIsEmpty(pstack))
    {
        printf("Stack Memory Error!\n");
        exit(-1);
    }

    delNode = pstack->head;
    delData = delNode->data;
    pstack->head = pstack->head->link;
    
    free(delNode);
    return delData;
}