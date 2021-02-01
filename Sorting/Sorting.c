#include <stdio.h>
#include <stdlib.h>

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
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[i])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

// int kthLargestElement(int A[], int n, int k)
// {
//     for (int i = 0; i < k; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (A[i] > A[i + 1])
//             {
//                 int temp = A[i];
//                 A[i] = A[i + 1];
//                 A[i + 1] = temp;
//             }
//         }
//     }
//     return A[n - k];
// }

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
    int A[] = {8, 7, 3, 6, 2, 5};

    // printf("Enter the number of elements: ");
    // scanf("%d", &n);

    // A = (int *)malloc(sizeof(int));
    // printf("Enter the elements in the array: ");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d ", &A[i]);
    // }

    insertionSort(A, 6);

    display(A, 6);
}