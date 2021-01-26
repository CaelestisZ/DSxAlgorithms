#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int top;
    int size;
    char *s;
};

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

void display(struct Stack s)
{
    for (int i = 0; i <= s.top; i++)
    {
        printf("%d ", s.s[i]);
    }
    printf("\n");
}

int isBalance(char *exp)
{
    struct Stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(&st, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(st))
            {
                return 0;
            }

            char x = pop(&st);
            if (x != '(')
            {
                return 0;
            }
        }

        if (exp[i] == '[')
        {
            push(&st, '[');
        }
        else if (exp[i] == ']')
        {
            if (isEmpty(st))
            {
                return 0;
            }

            char x = pop(&st);
            if (x != '[')
            {
                return 0;
            }
        }

        if (exp[i] == '{')
        {
            push(&st, '{');
        }
        else if (exp[i] == '}')
        {
            if (isEmpty(st))
            {
                return 0;
            }

            char x = pop(&st);
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