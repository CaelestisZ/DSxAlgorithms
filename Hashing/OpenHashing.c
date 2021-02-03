#include <stdio.h>
#include <stdlib.h>

// Chaining Implementation

struct Node
{
    int data;
    struct Node *next;
};

int hash(int key)
{
    return key % 10;
}

void insertSorted(struct Node **H, int x)
{
    struct Node *p = *H;
    struct Node *q = NULL;

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
    {
        *H = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = p;
            q->next = t;
        }
    }
}

void insert(struct Node *H[], int key)
{
    int index = hash(key);
    insertSorted(&H[index], key);
}

struct Node *linearSearch(struct Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void display(struct Node *H)
{
    while (H)
    {
        printf("%d ", H->data);
        H = H->next;
    }
}

int main()
{
    struct Node *HT[10];
    int i;

    for (i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }

    insertSorted(HT, 10);
    insertSorted(HT, 20);
    insertSorted(HT, 30);
    insertSorted(HT, 40);

    printf("%d \n", linearSearch(HT[hash(30)], 30)->data);

    display(HT[hash(10)]);

    printf("\n");

    return 0;
}