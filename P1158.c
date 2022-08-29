#include <stdio.h>
#include <stdlib.h>

#define TRUE       1
#define FALSE      0

#define QUE_LEN  5001

typedef struct _cqueue
{
    int front;
    int  rear;
    int queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit  (Queue *pq);
int  QIsEmpty   (Queue *pq);
int  NextPosIdx (int pos);
void Enqueue    (Queue *pq, int data);
int  Dequeue    (Queue *pq);
int  QSize      (Queue *pq);


int main(void)
{
    int i, N, K;
    scanf("%d %d%*c", &N, &K); // 1 <= K <= N <= 5000

    Queue que;
    QueueInit(&que);

    for(i = 1; i <= N; i++)
        Enqueue(&que, i);
    
    printf("<");
    while(!QIsEmpty(&que))
    {
        if(QSize(&que) != N) printf(", ");
        for(i = 0; i < K-1; i++)
            Enqueue(&que, Dequeue(&que));
        printf("%d", Dequeue(&que));
    }
    printf(">");

    // sol: circular queue, queue가 빌 때까지(K주기마다 dequeue, 그렇지 않은 경우 dequeue 후 enqueue)
    return 0;
}

void QueueInit(Queue *pq)
{
    pq->front = 0;
    pq->rear  = 0; 
}

int  QIsEmpty (Queue *pq)
{
    if(pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int  NextPosIdx (int pos)
{
    if(pos == QUE_LEN-1)
        return 0;
    else
        return pos+1;
}

void Enqueue  (Queue *pq, int data)
{
    if(NextPosIdx(pq->rear) == pq->front)
        exit(-1);
    else
    {
        pq->rear = NextPosIdx(pq->rear);
        pq->queArr[pq->rear] = data;
    }
}

int  Dequeue  (Queue *pq)
{
    if(QIsEmpty(pq))
        exit(-1);
    else
    {
        pq->front = NextPosIdx(pq->front);
        return pq->queArr[pq->front];
    }
}

int  QSize      (Queue *pq)
{
    int size = 0, iter = pq->front;
    
    while(iter != pq->rear)
    {
        iter = NextPosIdx(iter);
        size++;
    }
    
    return size;
}