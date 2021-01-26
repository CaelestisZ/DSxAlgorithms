#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int top;
    int size;
    char *s;
};

void create(struct Stack *s)
{
    printf("Enter the size of the stack: ");
    scanf("%d", &(s->size));
    s->s = (char *)malloc(s->size * sizeof(char));
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

void push(struct Stack *s, char ele)
{
    if (isFull(*s))
    {
        printf("Stack overflow!\n");
        return;
    }
    s->top++;
    s->s[s->top] = ele;
}

char pop(struct Stack *s)
{
    if (isEmpty(*s))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    char x = s->s[s->top--];
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

char stackTop(struct Stack s)
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
        printf("%c ", s.s[i]);
    }
    printf("\n");
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
    struct Stack st;
    st.top = -1;
    st.size = strlen(infix);
    st.s = (char *)malloc(st.size * sizeof(char));

    char *postfix = (char *)malloc(st.size * sizeof(char));
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (!isOperand(infix[i]))
        {
            if (precedence(stackTop(st)) >= precedence(infix[i]))
            {
                postfix[j++] = pop(&st);
            }
            push(&st, infix[i]);
        }
        else
        {
            postfix[j++] = infix[i];
        }
    }

    while (!isEmpty(st))
    {
        postfix[j++] = pop(&st);
    }

    postfix[j] = '\0';

    free(st.s);

    return postfix;
}

int main()
{
    char *infix = (char *)malloc(10 * sizeof(char));
    printf("Enter the Infix expression: ");
    scanf("%s", infix);

    printf("Postfix expression: %s\n", infixToPostfix(infix));

    return 0;
}