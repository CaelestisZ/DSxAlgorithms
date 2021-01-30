#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Tree
{
    int data;
    struct Tree *lchild;
    struct Tree *rchild;
} *root = NULL;

struct Node
{
    struct Tree *data;
    struct Node *next;
} *top = NULL;

void push(struct Tree *ele)
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

struct Tree *pop()
{
    struct Tree *x = NULL;
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

struct Tree *stackTop()
{
    return top->data;
}

int isEmpty()
{
    return top ? 0 : 1;
}

struct Tree *recursiveSearch(struct Tree *t, int key)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (key == t->data)
    {
        return t;
    }
    else if (key < t->data)
    {
        return recursiveSearch(t->lchild, key);
    }
    else
    {
        return recursiveSearch(t->rchild, key);
    }
}

struct Tree *search(struct Tree *t, int key)
{
    while (t != NULL)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

void insert(struct Tree *t, int key)
{
    struct Tree *r = NULL;

    if (t == NULL)
    {
        r = (struct Tree *)malloc(sizeof(struct Tree));
        r->data = key;
        r->lchild = r->rchild = NULL;
        root = r;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            // If the key is already in the tree, do not insert it.
            return;
        }
    }

    struct Tree *p = (struct Tree *)malloc(sizeof(struct Tree));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

struct Tree *recursiveInsert(struct Tree *t, int key)
{
    struct Tree *p;

    if (t == NULL)
    {
        p = (struct Tree *)malloc(sizeof(struct Tree));
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }

    if (key < t->data)
    {
        t->lchild = recursiveInsert(t->lchild, key);
    }
    else if (key > t->data)
    {
        t->rchild = recursiveInsert(t->rchild, key);
    }
    return t;
}

int height(struct Tree *t)
{
    if (t == NULL)
    {
        return 0;
    }
    int x, y;
    x = height(t->lchild);
    y = height(t->rchild);

    if (x > y)
    {
        return 1 + x;
    }
    else
    {
        return 1 + y;
    }
}

struct Tree *inPre(struct Tree *t)
{
    while (t != NULL && t->rchild != NULL)
    {
        t = t->rchild;
    }
    return t;
}

struct Tree *inSucc(struct Tree *t)
{
    while (t && t->lchild)
    {
        t = t->lchild;
    }
    return t;
}

struct Tree *deleteNode(struct Tree *t, int key)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->lchild == NULL && t->rchild == NULL)
    {
        if (t == root)
        {
            root = NULL;
        }
        free(t);
        return NULL;
    }

    if (key < t->data)
    {
        t->lchild = deleteNode(t->lchild, key);
    }
    else if (key > t->data)
    {
        t->rchild = deleteNode(t->rchild, key);
    }
    else
    {
        if (height(t->lchild) > height(t->rchild))
        {
            struct Tree *q = inPre(t->lchild);
            t->data = q->data;
            t->lchild = deleteNode(t->lchild, q->data);
        }
        else
        {
            struct Tree *q = inSucc(t->rchild);
            t->data = q->data;
            t->rchild = deleteNode(t->rchild, q->data);
        }
    }
    return t;
}

void constructTree(int *A, int n)
{
    struct Node st;
    int i = 0;

    root = (struct Tree *)malloc(sizeof(struct Tree));
    root->data = A[0];
    root->lchild = NULL;
    root->rchild = NULL;

    struct Tree *t = root;

    while (i < n)
    {
        if (A[i] < t->data)
        {
            struct Tree *r = (struct Tree *)malloc(sizeof(struct Tree));
            r->data = A[i++];
            r->lchild = r->rchild = NULL;
            t->lchild = r;
            push(t);
            t = r;
        }
        else
        {
            if ((A[i] > t->data && A[i] < stackTop()->data) || isEmpty())
            {
                struct Tree *r = (struct Tree *)malloc(sizeof(struct Tree));
                r->data = A[i++];
                r->lchild = r->rchild = NULL;
                t->rchild = r;
                t = r;
            }
            else
            {
                t = pop();
            }
        }
    }
}

void inorder(struct Tree *t)
{
    if (t != NULL)
    {
        inorder(t->lchild);
        printf("%d ", t->data);
        inorder(t->rchild);
    }
}

int main()
{
    // root = recursiveInsert(root, 10);
    // recursiveInsert(root, 9);
    // recursiveInsert(root, 12);
    // recursiveInsert(root, 11);

    // deleteNode(root, 12);

    // printf("Inorder: ");
    // inorder(root);
    // printf("\n");

    int A[8] = {30, 20, 10, 15, 25, 40, 50, 45};
    constructTree(A, 8);

    return 0;
}