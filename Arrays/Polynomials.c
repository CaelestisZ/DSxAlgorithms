#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff;
    int exp;
};

struct poly
{
    int n;
    struct term *t;
};

int main()
{
    struct poly p;
    int sum = 0;
    int x = 0;
    printf("Enter the number of non zero terms: ");
    scanf("%d", &p.n);
    p.t = (struct term *)malloc(p.n * sizeof(struct term));
    printf("Enter the coefficients and exponents in order:\n");
    for (int i = 0; i < p.n; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &p.t[i].coeff, &p.t[i].exp);
    }
    printf("Enter the value of x: ");
    scanf("%d", &x);
    for (int i = 0; i < p.n; i++)
    {
        int pow = 1;
        for (int j = 0; j < p.t[i].exp; j++)
        {
            pow *= x;
        }
        sum += p.t[i].coeff * pow;
    }
    printf("\nThe result is: %d\n", sum);
    return 0;
}