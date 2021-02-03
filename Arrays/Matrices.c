#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

// Diagonal matrix implementation

void setMatrix(struct Matrix *A, int i, int j, int key)
{
    if (i >= j)
    {
        A->A[i * (i - 1) / 2 + j - 1] = key;
    }
}

int getMatrix(struct Matrix A, int i, int j)
{
    if (i >= j)
    {
        return A.A[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

int displayMatrix(struct Matrix A)
{
    for (int i = 1; i <= A.n; i++)
    {
        for (int j = 1; j <= A.n; j++)
        {
            if (i >= j)
            {
                printf("%d ", A.A[i * (i - 1) / 2 + j - 1]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix A;
    A.n = 5;

    A.A = (int *)malloc((A.n * (A.n + 1) / 2) * sizeof(int));

    setMatrix(&A, 1, 1, 1);
    setMatrix(&A, 2, 2, 2);
    setMatrix(&A, 2, 1, 3);
    setMatrix(&A, 3, 3, 4);
    setMatrix(&A, 3, 2, 5);
    setMatrix(&A, 3, 1, 6);
    setMatrix(&A, 4, 4, 7);
    setMatrix(&A, 4, 3, 8);
    setMatrix(&A, 4, 2, 9);
    setMatrix(&A, 4, 1, 1);
    setMatrix(&A, 5, 5, 11);
    setMatrix(&A, 5, 4, 12);
    setMatrix(&A, 5, 3, 13);
    setMatrix(&A, 5, 2, 14);
    setMatrix(&A, 5, 1, 15);

    displayMatrix(A);

    // setDiagonalMatrix(&A, 1, 1, 1);
    // setDiagonalMatrix(&A, 2, 2, 2);
    // setDiagonalMatrix(&A, 3, 3, 3);
    // setDiagonalMatrix(&A, 4, 4, 4);
    // setDiagonalMatrix(&A, 5, 5, 5);

    // printf("%d is the element at (%d, %d)\n", getDiagonalMatrix(A, 1, 1), 1, 1);
    // printf("%d is the element at (%d, %d)\n", getDiagonalMatrix(A, 2, 2), 2, 2);
    // printf("%d is the element at (%d, %d)\n", getDiagonalMatrix(A, 3, 3), 3, 3);
    // printf("%d is the element at (%d, %d)\n", getDiagonalMatrix(A, 4, 4), 4, 4);
    // printf("%d is the element at (%d, %d)\n", getDiagonalMatrix(A, 5, 5), 5, 5);

    // displayDiagonalMatrix(A);

    return 0;
}