#include <stdio.h>
#include <stdlib.h>

// Self referential structure
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Display all elements in the linked list using an iterative method
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Display all elements in the linked list using a recursive method
void displayRecursive(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        displayRecursive(p->next);
    }
}

// Display all elements in the linked list in the reverse order using a recursive method
void displayReverse(struct Node *p)
{
    if (p != NULL)
    {
        displayReverse(p->next);
        printf("%d ", p->data);
    }
}

// Count number of nodes in linked list using an iterative approach
int count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

// Count number of nodes in linked list using a recursive approach
int countRecursive(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countRecursive(p->next);
    }
}

// Return sum of data in nodes using an iterative approach
int sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sumRecursive(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return p->data + sumRecursive(p->next);
    }
}

int maxElement(struct Node *p)
{
    int max = -32768; // minimum integer
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int maxElementRecursive(struct Node *p)
{
    int x = 0;
    if (p == NULL)
    {
        return -32678;
    }
    else
    {
        x = maxElementRecursive(p->next);
        if (x > p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

// Usually, we don't talk in terms of indices in linked lists. Therefore we avoid returning the index
// Instead we return the node.
struct Node *linearSearch(struct Node *p, int key)
{
    struct Node *q = NULL;

    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int binarySearch(struct Node *p, int key)
{
    // Why is this empty?
}

struct Node *linearSearchRecursive(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if (p->data == key)
    {
        return p;
    }
    return linearSearchRecursive(p->next, key);
}

void insertAtIndex(int index, int data)
{
    struct Node *p = NULL;

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else if (index > 0)
    {
        int i = 0;
        p = first;
        while (p != NULL && i < index - 1)
        {
            p = p->next;
            i++;
        }
        if (p)
        {
            t->next = p->next;
            p->next = t;
        }
    }
}

void insertEnd(int data)
{
    struct Node *t, *last = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    struct Node *p = first;

    if (first == NULL)
    {
        first = t;
        last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void insertSorted(int data)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    struct Node *p = first, *q = NULL;

    if (first == NULL)
    {
        first = t;
        return;
    }

    while (p != NULL && p->data < data)
    {
        q = p;
        p = p->next;
    }

    if (p == first)
    {
        t->next = first;
        first = t;
    }
    else
    {
        t->next = q->next;
        q->next = t;
    }
}

int deleteFront()
{
    struct Node *p = first;
    int x = p->data;
    first = first->next;
    free(p);
    return x;
}

int deleteAtIndex(int index)
{
    struct Node *p = first, *q = NULL;
    int i = 0;

    if (index == 1)
    {
        int x = p->data;
        first = first->next;
        free(p);
        return x;
    }

    while (p != NULL && i < index - 1)
    {
        q = p;
        p = p->next;
        i++;
    }

    if (p)
    {
        q->next = p->next;
        int x = p->data;
        free(p);
        return x;
    }
}

int isSorted()
{
    int x = -32678;
    struct Node *p = first;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

int removeDuplicates()
{
    struct Node *p = first;
    struct Node *q = first->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }

    printf("\nRemoved duplicates from the linked list!\n");
    display(first);
}

int reverse()
{
    // Time complexity: O(3n)
    // Space complexity: O(n)
    struct Node *p = first;
    int count = 0;

    // Compute the length of linked list
    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    int auxilliaryArray[count];
    int i = 0;
    // Start from the beginning of the linked list
    p = first;

    // Copy elements in the linked list to an array
    while (p != NULL && i < count)
    {
        auxilliaryArray[i++] = p->data;
        p = p->next;
    }

    // Start from the beginning of the linked list
    p = first;
    i--;

    // Copy elements back into the linked list starting from the end of the array
    while (p != NULL && i >= 0)
    {
        p->data = auxilliaryArray[i--];
        p = p->next;
    }

    printf("\nReversed the linked list using an auxilliary array!\n");
    display(first);
}

int reverseSlidingPointer()
{
    struct Node *p = first;
    struct Node *q = NULL;
    struct Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;

    printf("\nReversed the linked list using the sliding pointer approach!\n");
    display(first);
}

void reverseRecursive(struct Node *q, struct Node *p)
{
    if (p)
    {
        reverseRecursive(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void concatenate(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(struct Node *p, struct Node *q)
{
    // Space complexity: O(1)
    // Time complexity: O(n+m)`
    struct Node *last = NULL;

    // Copy the lesser of each of linked list's elements
    if (p->data < q->data)
    {
        third = p;
        last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = q;
        last = q;
        q = q->next;
        third->next = NULL;
    }

    // Copy the elements in first and second linked lists depending upon which of them is of lesser value
    while (p != NULL && q != NULL)
    {
        if (p->data > q->data)
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
        else
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
    }

    // Copy the remaining elements
    if (p != NULL)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
}

int isLoop(struct Node *first)
{
    struct Node *p = first;
    struct Node *q = first;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int middleElement(struct Node *p)
{
    struct Node *q = p;
    while (q)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
        }
        if (q)
        {
            p = p->next;
        }
    }
    return p->data;
}

// int intersection(struct Node *p, struct Node *q) {
//     // Store both the linked lists into a stack
//     // Pop elements simultaneously from the stack as long as there is a common node
//     // Stop when there is no common node
//     // The node at which the pointer stops is the intersection!
// }

int main()
{
    int A[] = {1, 2, 3, 4};
    int B[] = {4, 7, 12, 14, 17};
    create(A, 4);
    create2(B, 5);

    printf("Linked List 1: ");
    display(first);
    printf("Linked List 2: ");
    display(second);

    // concatenate(first, second);
    // printf("Concatenated linked list: ");
    // display(third);

    merge(first, second);
    printf("Merged linked list: ");
    display(third);

    printf("%d is the middle element!\n", middleElement(first));

    // struct Node *t1, *t2;

    // // Add a loop into the linked list!
    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;

    // printf("\n%s\n", isLoop(first) ? "The linked list has a loop!" : "The linked list doesn't have a loop!");

    // display(first);

    // printf("%p\n", first);
    // struct Node *t3 = first;
    // printf("%p\n", t3);

    // first = (struct Node *)malloc(sizeof(struct Node));
    // first = NULL;
    // last = (struct Node *)malloc(sizeof(struct Node));
    // last = NULL;

    // second = (struct Node *)malloc(sizeof(struct Node));
    // second = NULL;
    // insertEnd(3);
    // insertEnd(5);
    // insertEnd(5);
    // insertEnd(8);
    // insertEnd(8);
    // insertEnd(8);

    // display(first);

    // removeDuplicates();

    // reverse();

    // reverseSlidingPointer();

    // reverseRecursive(NULL, first);
    // printf("\nReversed the linked list using recursion!\n");
    // display(first);

    // concatenate(first, second);

    // printf("\n%s\n", isSorted() ? "The linked list is sorted!" : "The linked list is not sorted!");

    return 0;
}