#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue
{
    int data;
    struct Queue *next;
} *front = NULL, *rear = NULL;

void enqueue(int ele)
{
    struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));

    if (t == NULL)
    {
        printf("Heap is full!\n");
        return;
    }

    t->data = ele;
    t->next = NULL;

    if (front == NULL)
    {
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }

    return;
}

int dequeue()
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
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    printf("Deleted %d\n", dequeue());
    printf("Deleted %d\n", dequeue());
    display();
    return 0;
}