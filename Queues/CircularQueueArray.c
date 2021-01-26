#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue
{
    int *Q;
    int front;
    int rear;
    int size;
};

void enqueue(struct Queue *q, int ele)
{
    if (q->front == (q->rear + 1) % q->size)
    {
        printf("Overflow!\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = ele;
    }
}

int dequeue(struct Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Underflow!\n");
        return -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        return q->Q[q->front];
    }
}

void display(struct Queue q)
{
    int i = (q.front + 1) % q.size;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("\n");
}

int main()
{
    struct Queue q;
    printf("Enter the size of the queue: ");
    scanf("%d", &q.size);
    q.front = q.rear = -1;
    q.Q = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10);
    display(q);

    return 0;
}