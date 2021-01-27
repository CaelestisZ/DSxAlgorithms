#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue
{
    int data;
    struct Queue *next;
    struct Queue *prev;
} *front = NULL, *rear = NULL;

void enqueueFront(int ele)
{
    struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));

    if (t == NULL)
    {
        printf("Heap is full!\n");
        return;
    }

    t->data = ele;
    t->next = NULL;
    t->prev = NULL;

    if (front == NULL)
    {
        front = rear = t;
    }
    else
    {
        t->next = front;
        front->prev = t;
        front = t;
    }
}

void enqueueRear(int ele)
{
    struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));

    if (t == NULL)
    {
        printf("Heap is full!\n");
        return;
    }

    t->data = ele;
    t->next = NULL;
    t->prev = NULL;

    if (front == NULL)
    {
        front = rear = t;
    }
    else
    {
        t->prev = rear;
        rear->next = t;
        rear = t;
    }

    return;
}

int dequeueFront()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Queue *q = front;
    int x = front->data;
    front = front->next;
    free(q);
    return x;
}

int dequeueRear()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Queue *p = rear;
    int x = p->data;
    rear = rear->prev;
    rear->next = NULL;
    free(p);
    return x;
}

void display()
{
    struct Queue *q = front;
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

int main()
{
    enqueueRear(2);
    enqueueRear(3);
    enqueueRear(4);
    enqueueRear(5);
    enqueueRear(6);
    enqueueRear(7);
    enqueueRear(8);
    enqueueFront(1);
    enqueueRear(2);
    enqueueRear(3);
    enqueueRear(4);
    enqueueRear(5);
    enqueueRear(6);
    enqueueRear(7);
    enqueueRear(8);
    enqueueFront(1);
    dequeueFront();
    dequeueRear();
    display();
    return 0;
}