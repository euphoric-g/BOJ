#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define LEN 20

typedef int Data;

typedef struct {
    int front;
    int rear;
    Data queArr[LEN];
} Queue;

void QueueInit(Queue* pq)
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == pq->rear)
        return 1;
    else
        return 0;
}

int NextPosIdx(int pos)
{
    if(pos==LEN-1)
        return 0;
    else
        return pos+1;
}

int size(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        return 0;
    }
    return (pq->rear)-(pq->front);
}

Data Enqueue(Queue * pq, Data data)
{
    if(NextPosIdx(pq->rear)==pq->front)
    {
        return -1;
    }
    pq->rear=NextPosIdx(pq->rear);
    pq->queArr[pq->rear]=data;
}

Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        return -1;
    }
    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

void show(Queue *pq) {
	for(int i=0; i<20; i++) {
		printf("%d ", pq->queArr[i]);
	}
	printf("\nfront, rear = %d, %d\n", pq->front, pq->rear);
}

int main()
{
    Queue q;
    QueueInit(&q);
    int n;
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        Enqueue(&q,i+1);
        show(&q);
    }
    while(size(&q)>1)
    {
        Dequeue(&q);
        temp=Dequeue(&q);
        if(QIsEmpty(&q)==1)
            break;
        Enqueue(&q,temp);
        show(&q);
    }
    printf("%d",temp);
 
    return 0;
}

