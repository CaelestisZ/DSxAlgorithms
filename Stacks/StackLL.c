#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int ele)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack overflow!\n");
        return;
    }
    t->data = ele;
    t->next = top;
    top = t;
}

int pop()
{
    int x = -1;
    if (top == NULL)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        struct Node *p = top;
        x = p->data;
        top = top->next;
        free(p);
    }
    return x;
}

int peek(int pos)
{
    struct Node *p = top;
    int i = 0;
    while (p && i < pos)
    {
        p = p->next;
        i++;
    }
    if (p != NULL)
    {
        return p->data;
    }
    return -1;
}

int isEmpty()
{
    return top ? 0 : 1;
}

int isFull()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        return 1;
    }
    free(t);
    return 0;
}

void display()
{
    struct Node *p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Node *top = (struct Node *)malloc(sizeof(struct Node));

    push(2);
    push(3);
    push(4);
    push(5);
    push(3);
    push(3);
    pop();
    pop();

    printf("%d\n", peek(2));
    printf("%d\n", isEmpty());
    printf("%d\n", isFull());

    display();

    return 0;
}