#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * head;

void create(int A[], int n)
{
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    // Using a do-while instead of a while loop to execute for the first element
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void displayRecursive(struct Node *p)
{
    static int flag = 0;
    if (flag == 0 || p != head)
    {
        flag = 1;
        printf("%d ", p->data);
        displayRecursive(p->next);
    }
}

void insert(struct Node *p, int data, int pos)
{
    if (p == NULL)
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->next = p;
        head = p;
    }
    else
    {
        if (pos == 0)
        {
            struct Node *t = (struct Node *)malloc(sizeof(struct Node));
            t->data = data;
            t->next = p;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            head = t;
        }
        else
        {
            int i = 0;
            while (i < pos - 1)
            {
                p = p->next;
                i++;
            }

            struct Node *t = (struct Node *)malloc(sizeof(struct Node));
            t->data = data;
            t->next = p->next;
            p->next = t;
        }
    }
}

void delete (struct Node *p, int pos)
{
    if (head == NULL)
    {
        return;
    }
    if (pos == 0)
    {
        while (p->next != head)
        {
            p = p->next;
        }

        struct Node *t = head;

        p->next = t->next;
        head = t->next;

        free(t);
    }
    else
    {
        int i = 0;
        while (i < pos - 1)
        {
            p = p->next;
            i++;
        }
        struct Node *q = p->next;
        p->next = q->next;
        free(q);
    }
}

int main()
{
    // int A[] = {1, 2, 3, 4, 5};
    // create(A, 5);

    // display(head);
    // displayRecursive(head);

    insert(head, 3, 0);

    insert(head, 5, 1);

    insert(head, 4, 1);

    insert(head, 1, 0);

    insert(head, 2, 1);

    // delete (head, 0);

    // delete (head, 3);

    display(head);

    return 0;
}