#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(char ele)
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
    struct Node *p;
    char x = -1;
    if (top == NULL)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        p = top;
        x = p->data;
        top = top->next;
        free(p);
    }
    return x;
}

int isOperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 0;
    }
    return 1;
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    return 0;
}

char *infixToPostfix(char *infix)
{
    int j = 0;
    int i = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc(20 * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (precedence(infix[i]) > precedence(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }

    while (top != NULL)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *infix;
    infix = (char *)malloc(10 * sizeof(char));
    printf("Enter the Infix expression: ");
    scanf("%s", infix);

    printf("Postfix expression: %s\n", infixToPostfix(infix));
    return 0;
}