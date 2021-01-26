#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

int isFull(struct Queue q)
{
    return q.rear == q.size - 1 ? 1 : 0;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear ? 1 : 0;
}

void enqueue(struct Queue *q, int element)
{
    if (isFull(*q))
    {
        return;
    }
    ++q->rear;
    q->Q[q->rear] = element;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(*q))
    {
        return -1;
    }
    q->front++;
    int x = q->Q[q->front];
    return x;
}

void display(struct Queue q)
{
    for (int i = q.front + 1; i < q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    printf("Enter the size of the queue: ");
    scanf("%d", &q.size);
    q.front = q.rear = -1;

    q.Q = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 1);
    enqueue(&q, 1);
    enqueue(&q, 1);
    enqueue(&q, 1);

    display(q);
    dequeue(&q);

    display(q);

    return 0;
}

// Drawback:
// Unused spaces after dequeue operation, hence we use a circular queue instead.