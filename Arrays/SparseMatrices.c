#include<stdio.h>
#include<stdlib.h>

struct Element {
    int i;
    int j;
    int x;
};

struct Sparse {
    int m;
    int n;
    int nonZeroes;
    struct Element *e;
};

int create(struct Sparse *S) {
    printf("Enter the number of rows: ");
    scanf("%d", &S->m);
    printf("Enter the number of columns: ");
    scanf("%d", &S->n);
    printf("Enter the number of non zero elements: ");
    scanf("%d", &S->nonZeroes);
    S->e = (struct Element *)malloc(S->nonZeroes * sizeof(struct Element));
    printf("Enter the elements (format: rowNumber columnNumber value):\n");
    for (int i = 0; i<S->nonZeroes; i++) {
        scanf("%d %d %d", &S->e[i].i, &S->e[i].j, &S->e[i].x);
    }
    return 0;
}

int display(struct Sparse S) {
    int k = 0;
    printf("Sparse Matrix: \n");
    for (int i = 0; i<S.m; i++) {
        for (int j = 0; j<S.n; j++) {
            if (i == S.e[k].i && j == S.e[k].j) {
                printf("%d ", S.e[k++].x);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}

void main() {
    struct Sparse S;
    struct Sparse S1;
    create(&S);
    display(S);
    create(&S1);
    display(S1);
    // add(S);
}