#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
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

char pop()
{
    char x = -1;
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

int isEmpty()
{
    return top ? 0 : 1;
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

int isBalance(char *exp)
{
    struct Node *st = (struct Node *)malloc(sizeof(struct Node));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push('(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(*st))
            {
                return 0;
            }
            char x = pop(st);
            if (x != '(')
            {
                return 0;
            }
        }

        if (exp[i] == '[')
        {
            push('[');
        }
        else if (exp[i] == ']')
        {
            if (isEmpty(*st))
            {
                return 0;
            }
            char x = pop(st);
            if (x != '[')
            {
                return 0;
            }
        }

        if (exp[i] == '{')
        {
            push('{');
        }
        else if (exp[i] == '}')
        {
            if (isEmpty(*st))
            {
                return 0;
            }
            char x = pop(st);
            if (x != '{')
            {
                return 0;
            }
        }
    }

    return isEmpty(st) ? 1 : 0;
}

int main()
{
    char *exp = (char *)malloc(10 * sizeof(char));
    printf("Enter the string: ");
    scanf("%s", exp);
    printf("%s\n", isBalance(exp) ? "The string is balanced!" : "The string isn't balanced!");
    free(exp);
    return 0;
}