#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
} *root = NULL;

struct Queue
{
    struct Tree *data;
    struct Queue *next;
} *front = NULL, *rear = NULL;

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

int isStackEmpty()
{
    return top ? 0 : 1;
}

struct Tree *stackTop()
{
    return top->data;
}

void enqueue(struct Tree *ele)
{
    struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));

    if (t == NULL)
    {
        printf("Heap is full!\n");
        return;
    }

    t->data = ele;
    t->next = NULL;

    if (front == NULL)
    {
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }

    return;
}

struct Tree *dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return NULL;
    }
    struct Queue *q = front;
    struct Tree *x = front->data;
    front = front->next;
    free(q);
    return x;
}

int isQueueEmpty(struct Queue q)
{
    return front == NULL ? 1 : 0;
}

void create()
{
    struct Tree *p, *t;

    struct Queue q;

    root = (struct Tree *)malloc(sizeof(struct Tree));

    printf("Enter the root node: ");
    scanf("%d", &(root->data));
    root->left = root->right = NULL;

    enqueue(root);

    while (!isQueueEmpty(q))
    {
        int x;

        p = dequeue();

        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            t = (struct Tree *)malloc(sizeof(struct Tree));
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            enqueue(t);
        }

        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            t = (struct Tree *)malloc(sizeof(struct Tree));
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(t);
        }
    }
}

void preorder(struct Tree *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void inorder(struct Tree *tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

void postorder(struct Tree *tree)
{
    if (tree != NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->data);
    }
}

void preorderIterative(struct Tree *t)
{
    struct Node st;

    while (t != NULL || !isStackEmpty())
    {
        if (t != NULL)
        {
            printf("%d ", t->data);
            push(t);
            t = t->left;
        }
        else
        {
            t = pop();
            t = t->right;
        }
    }
}

void inorderIterative(struct Tree *t)
{
    struct Node st;

    while (t != NULL || !isStackEmpty())
    {
        if (t != NULL)
        {
            push(t);
            t = t->left;
        }
        else
        {
            t = pop();
            printf("%d ", t->data);
            t = t->right;
        }
    }
}

void levelOrder(struct Tree *t)
{
    struct Queue q;

    printf("%d ", t->data);
    enqueue(t);

    while (!isQueueEmpty(q))
    {
        t = dequeue();

        if (t->left)
        {
            printf("%d ", t->left->data);
            enqueue(t->left);
        }
        if (t->right)
        {
            printf("%d ", t->right->data);
            enqueue(t->right);
        }
    }
}

int count(struct Tree *t)
{
    // int x;
    // int y;
    // if (t != NULL)
    // {
    //     x = count(t->left);
    //     y = count(t->right);
    //     return 1 + x + y;
    // }
    // return 0;
    if (t == NULL)
    {
        return 0;
    }
    return count(t->left) + count(t->right) + 1;
}

int sum(struct Tree *t)
{
    int x, y;
    if (t != NULL)
    {
        x = sum(t->left);
        y = sum(t->right);
        return x + y + t->data;
    }
    return 0;
}

int height(struct Tree *t)
{
    int x, y;
    if (t != NULL)
    {
        x = height(t->left);
        y = height(t->right);
        if (x > y)
        {
            return 1 + x;
        }
        else
        {
            return 1 + y;
        }
    }
}

int countLeafNodes(struct Tree *t)
{
    int x, y;
    if (t != NULL)
    {
        x = countLeafNodes(t->left);
        y = countLeafNodes(t->right);
        if (t->left == NULL && t->right == NULL)
        {
            return 1 + x + y;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int countNonLeafNodes(struct Tree *t)
{
    int x, y;
    if (t != NULL)
    {
        x = countNonLeafNodes(t->left);
        y = countNonLeafNodes(t->right);

        if (t->left != NULL || t->right != NULL)
        {
            return 1 + x + y;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int countDegreeOneNodes(struct Tree *t)
{
    int x, y;
    if (t != NULL)
    {
        x = countDegreeOneNodes(t->left);
        y = countDegreeOneNodes(t->right);
        if ((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL))
        {
            return 1 + x + y;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int countDegreeTwoNodes(struct Tree *t)
{
    int x, y;

    if (t != NULL)
    {
        x = countDegreeTwoNodes(t->left);
        y = countDegreeTwoNodes(t->right);

        if (t->left != NULL && t->right != NULL)
        {
            return 1 + x + y;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int main()
{
    create();

    printf("Preorder: ");
    preorderIterative(root);
    printf("\n");

    printf("Inorder: ");
    inorderIterative(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Levelorder: ");
    levelOrder(root);
    printf("\n");

    printf("Number of nodes: %d\n", count(root));
    printf("Sum of nodes in tree: %d\n", sum(root));
    printf("Height of tree: %d\n", height(root));
    printf("Number of leaf nodes in tree: %d\n", countLeafNodes(root));
    printf("Number of non leaf nodes in tree: %d\n", countNonLeafNodes(root));
    printf("Number of first degree nodes in tree: %d\n", countDegreeOneNodes(root));
    printf("Number of second degree nodes in tree: %d\n", countDegreeTwoNodes(root));

    return 0;
}