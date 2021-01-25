#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->prev = NULL;
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int length(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insert(struct Node *p, int data, int pos)
{
    if (pos < 0 || pos > length(p))
    {
        return;
    }
    if (head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
    }
    else
    {
        if (pos == 0)
        {
            struct Node *t = (struct Node *)malloc(sizeof(struct Node));
            t->data = data;
            t->prev = NULL;
            t->next = p;
            p->prev = t;
            head = t;
        }
        else
        {
            struct Node *t = (struct Node *)malloc(sizeof(struct Node));
            t->data = data;
            int i = 0;
            while (i < pos - 1)
            {
                p = p->next;
                i++;
            }
            t->next = p->next;
            t->prev = p;
            if (p->next)
            {
                p->next->prev = t;
            }
            p->next = t;
        }
    }
}

void delete (struct Node *p, int pos)
{
    if (pos < 0 || pos > length(p))
    {
        return;
    }
    if (pos == 0)
    {
        p->next->prev = NULL;
        head = head->next;
        free(p);
    }
    else
    {
        int i = 0;

        while (i < pos)
        {
            p = p->next;
            i++;
        }
        p->prev->next = p->next;

        if (p->next)
        {
            p->next->prev = p->prev;
        }

        free(p);
    }
}

void reverse(struct Node *p)
{

    struct Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
        {
            head = p;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);

    // insert(head, 4, 0);
    // insert(head, 3, 0);
    // insert(head, 2, 2);
    // insert(head, 1, 0);
    // delete (head, 3);
    reverse(head);
    display(head);

    return 0;
}