#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *s;
};

void create(struct Stack *s)
{
    printf("Enter the size of the stack: ");
    scanf("%d", &(s->size));
    s->s = (int *)malloc(s->size * sizeof(int));
    s->top = -1;
}

int isEmpty(struct Stack s)
{
    if (s.top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack s)
{
    if (s.top == s.size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *s, int ele)
{
    if (isFull(*s))
    {
        printf("Stack overflow!\n");
        return;
    }
    s->top++;
    s->s[s->top] = ele;
}

int pop(struct Stack *s)
{
    if (isEmpty(*s))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    int x = s->s[s->top--];
    return x;
}

int peek(struct Stack s, int pos)
{
    if (s.top - pos + 1 < 0)
    {
        return -1;
    }
    return s.s[s.top - pos + 1];
}

int stackTop(struct Stack s)
{
    if (s.top == -1)
    {
        return -1;
    }
    else
    {
        return s.s[s.top];
    }
}

void display(struct Stack s)
{
    for (int i = 0; i <= s.top; i++)
    {
        printf("%d ", s.s[i]);
    }
    printf("\n");
}

int main()
{
    struct Stack s;
    create(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    push(&s, 6);
    push(&s, 7);
    push(&s, 8);

    pop(&s);
    pop(&s);

    // printf("%s\n", isEmpty(s) ? "The stack is empty!" : "The stack is not empty!");
    // printf("%s\n", isFull(s) ? "The stack is full!" : "The stack is not full!");

    display(s);
    printf("%d\n", stackTop(s));
    printf("%d\n", peek(s, 2));

    return 0;
}