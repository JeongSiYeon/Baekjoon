#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE       1
#define FALSE      0

#define STACK_LEN 21

typedef struct _arrayStack
{
    int top;
    char stackArr[STACK_LEN];
} Stack;

void StackInit(Stack *pstack);
int  SIsEmpty (Stack *pstack);
void SPush(Stack *pstack, char data);
void SPop(Stack *pstack);

int main(void)
{
    int i, j, string_iter, T;
    Stack word_stack;
    StackInit(&word_stack);

    scanf("%d%*c", &T);
    char *string = (char *)calloc(T*1001, sizeof(char)); 
    
    // get strings(T)
    for(i = 0; i < T; i++)
        gets(&string[i*1001]);
    
    // word flip and print using push & pop
    for(i = 0; i < T; i++)
    {
        char *string_iter = &string[i*1001];
        StackInit(&word_stack);

        for(j = 0; j <= strlen(&string[i*1001]); j++)
        {
            if(*string_iter == ' ' || *string_iter == '\0')
            {
                while(!SIsEmpty(&word_stack))
                    SPop(&word_stack);
                
                if(*(string_iter+1) != '\0' && *string_iter != '\0')
                    printf(" ");
            }
            if(*string_iter != ' ') 
                SPush(&word_stack, *string_iter);

            string_iter++;
        }
        printf("\n");
    }
    return 0;
}

void StackInit(Stack *pstack)
{
    pstack->top = -1;
}

int  SIsEmpty (Stack *pstack)
{
    if(pstack->top == -1)
        return TRUE;
    else    
        return FALSE;
}

void SPush(Stack *pstack, char data)
{
    pstack->top += 1;
    pstack->stackArr[pstack->top] = data;
}   

void SPop(Stack *pstack)
{
    printf("%c", pstack->stackArr[pstack->top]);
    pstack->top -= 1;
}