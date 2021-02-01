#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubbleSort(int A[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void insertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = A[i];

        while (j > -1 && x < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
    return;
}

void selectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (A[k] > A[j])
            {
                k = j;
            }
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while (i < j);

    swap(&A[low], &A[j]);
    return j;
}

void quickSort(int A[], int low, int high)
{
    int pivotPosition;
    if (low < high)
    {
        pivotPosition = partition(A, low, high);
        quickSort(A, low, pivotPosition);
        quickSort(A, pivotPosition + 1, high);
    }
}

void merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    for (; i <= mid; i++)
    {
        B[k++] = A[i];
    }
    for (; j <= high; j++)
    {
        B[k++] = A[j];
    }

    for (int m = low; m <= high; m++)
    {
        A[m] = B[m];
    }
}

void IterativeMergeSort(int A[], int n)
{
    int p, i, low, mid, high;

    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;

            merge(A, low, mid, high);
        }
    }

    if (p / 2 < n)
    {
        merge(A, 0, (p / 2) - 1, n - 1);
    }
}

void recursiveMergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        recursiveMergeSort(A, low, mid);
        recursiveMergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

void countSort(int A[], int n)
{
    int count[100];

    for (int i = 0; i < 100; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[A[i]]++;
    }

    int k = 0;

    int i = 0;

    while (k < 100)
    {
        if (count[k] > 0)
        {
            A[i++] = k;
            count[k]--;
        }
        else
        {
            k++;
        }
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
    int A[] = {8, 7, 3, 6, 2, 5, 9, 9, 4, 2};

    // printf("Enter the number of elements: ");
    // scanf("%d", &n);

    // A = (int *)malloc(sizeof(int));
    // printf("Enter the elements in the array: ");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d ", &A[i]);
    // }

    // quickSort(A, 0, 6);

    countSort(A, 10);

    // recursiveMergeSort(A, 0, 6);

    display(A, 10);
}