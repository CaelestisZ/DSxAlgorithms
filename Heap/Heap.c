#include <stdio.h>
#include <stdlib.h>

void insert(int *A, int n)
{
    int temp, i = n;
    temp = A[n];

    while (temp > A[i / 2] && i > 0)
    {
        A[i] = A[i / 2];
        i = i / 2;
    }

    A[i] = temp;
}

void create(int *A, int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        insert(A, i);
    }
}

int Delete(int *A, int n)
{
    int x = A[0];
    A[0] = A[n - 1];
    A[n - 1] = x;
    int i, j;
    i = 0;
    j = (2 * i) + 1;

    while (j < n - 2)
    {
        if (A[j + 1] > A[j])
        {
            j++;
        }
        if (A[i] < A[j])
        {
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
            i = j;
            j = 2 * j + 1;
        }
        else
        {
            break;
        }
    }
    return x;
}

void heapSort(int A[], int n)
{
    int i = n;
    while (i > 0)
    {
        Delete(A, i);
        i--;
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    int *A;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the Binary Heap: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &A[i]);
    }

    // create(A, n);

    // heapSort(A, n);

    heapify(A, n);

    display(A, n);

    return 0;
}