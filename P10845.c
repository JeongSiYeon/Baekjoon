#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#define TRUE      1
#define FASLE     0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next;
} Node;

typedef struct _lQueue
{
    Node *front;
    Node  *rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq);
void push   (Queue *pq, Data data);
void pop    (Queue *pq);
void size   (Queue *pq);
void empty  (Queue *pq);
void front  (Queue *pq);
void back   (Queue *pq);

void command_execution(Queue *pq, char *command);

int main(void)
{
    int i, commandN; // command number

    scanf("%d%*c", &commandN);
    char *command = (char *)calloc(commandN*12, sizeof(char)); // command length max: 11 => 11*N + 1(NULL character)

    Queue q;
    QueueInit(&q);

    for(i = 0; i < commandN; i++)
        gets(&command[11*i]);

    for(i = 0; i < commandN; i++)
        command_execution(&q, &command[11*i]);

    return 0;
}

void QueueInit(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

void push(Queue *pq, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(pq->front == NULL)
    {
        pq->front = newNode;
        pq->rear  = newNode;
    }
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

void pop(Queue *pq)
{
    Node *delNode;
    Data retData;

    if(pq->front == NULL)
        printf("-1\n");
    else
    {
        delNode = pq->front;
        retData = delNode->data;
        pq->front = pq->front->next;

        free(delNode);
        printf("%d\n", retData);
    }
}

void size   (Queue *pq)
{
    int size = 0;
    Node *np = pq->front;

    if(pq->front == NULL)
        printf("0\n");
    else
    {
        while(np != NULL)
        {
            size++;
            np = np->next;
        }
        printf("%d\n", size);
    }
}
void empty  (Queue *pq)
{
    if(pq->front == NULL)
        printf("1\n");
    else 
        printf("0\n");
}

void front  (Queue *pq)
{
    if(pq->front == NULL)
        printf("-1\n");
    else    
        printf("%d\n", pq->front->data);
}

void back   (Queue *pq)
{
    if(pq->front == NULL)
        printf("-1\n");
    else
        printf("%d\n",pq->rear->data);
}


void command_execution(Queue *pq, char *command)
{
    if(strstr(command, "push") != NULL)
        push(pq, atoi( &command[5] ));
    else if(strstr(command, "pop") != NULL) 
        pop(pq);
    else if(strstr(command, "size") != NULL) 
        size(pq);
    else if(strstr(command, "empty") != NULL) 
        empty(pq);
    else if(strstr(command, "front") != NULL) 
        front(pq);
    else if(strstr(command, "back") != NULL) 
        back(pq);
}
