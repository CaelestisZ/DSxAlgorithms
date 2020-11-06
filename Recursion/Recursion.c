#include<stdio.h>

// Whenever a recursive approach is used, make sure to consider the space complexity due to the recursion stack

// Compute the sum of first n natural numbers using recursion
int sumOfFirstN(int n) {
    if (n==0) {
        return 0;
    }
    return n + sumOfFirstN(n-1);
}

// Compute the factorial of n
int factorial(int n) {
    if (n==0) {
        return 1;
    }
    return n * factorial(n-1);
}

// Compute the value of m to the power of n
int power(int m, int n) {
    if (n==0) {
        return 1;
    }
    return m*power(m, n-1);
}

// Optimized algorithm for the above
int powerOptimized(int m, int n) {
    if (n==0) {
        return 1;
    }
    else if (n%2==0) {
        return powerOptimized(m*m, n/2);
    }
    else {
        return m*powerOptimized(m*m, (n-1)/2); // n is subtracted by 2 to make it even
    }
}

// Compute taylor series for x upto n terms
double taylorSeries(int x, int n) {
    static double p = 1.0;
    static double f = 1.0;
    double r;
    if(n==0) {
        return 1;
    }
    else {
        r = taylorSeries(x, n-1);
        p = p*x;
        f = f*n;
        return r + (p/f);
    }
}

// Optimized algorithm for the above
// Managed to reduce multiplication from n^2 as in the above case to n
double taylorSeriesOptimized(int x, int n) {
    // Iterative solution
    // double s = 1;
    // double num = 1;
    // double den = 1;
    // for (int i = 1; i<=n; i++) {
    //     num *= x;
    //     den *= i;
    //     s += num/den;
    // }
    // return s;

    // Recursive solution
    static double s = 1;
    if (n==0) {
        return s;
    }
    else {
        s = 1 + (x*s/n);
        return taylorSeriesOptimized(x, n-1);
    }
} 

int nthFibonacciSeries(int n) {
    // Iterative solution
    // int t0 = 0;
    // int t1 = 1;
    // int s = 0;
    // if (n<=1) {
    //     return n;
    // }
    // for (int i = 2; i<=n; i++) {
    //     s = t0+t1;
    //     t0 = t1;
    //     t1 = s;
    // }
    // return s;

    // Recursive solution
    if(n<=1) {
        return n;
    }
    else {
        return nthFibonacciSeries(n-1) + nthFibonacciSeries(n-2);
    }
    // This tree based recursive approach doesn't use the previously evaluated values of the fibonacci of the same number
    // To resolve this we use memoization to store that previously generated fibonaccis in an array to evaluate taking lesser time   
}

int nCr(int n, int r) {
    // Iterative solution
    // int t1 = factorial(n);
    // int t2 = factorial(r);
    // int t3 = factorial(n-r);

    // return t1/(t2*t3);

    // Recursive solution
    if (r==0 || n==r) {
        return 1;
    }
    else {
        return (nCr(n-1, r-1) + nCr(n-1, r)); 
    }
}

int TOH(int n, int A, int B, int C) {
    if (n>0) {
        TOH(n-1, A, C, B);
        printf("Move a disk from %d to %d\n", A, C);
        TOH(n-1, B, A, C);
    }
    return 0;
}

int main() {
    int m = 5;
    int n = 10;
    int x = 1;
    printf("Sum of first %d natural numbers: %d\n", n, sumOfFirstN(n));
    printf("Factorial of %d: %d\n", n, factorial(n));
    printf("%d to the power of %d: %d\n", m, n, power(m, n));
    printf("%d to the power of %d using a smaller recursion stack: %d\n", m, n, powerOptimized(m, n));
    printf("The taylor series for %d upto %d terms: %lf\n", x, n, taylorSeries(x, n));
    printf("The taylor series for %d upto %d terms using Horner's rule: %lf\n", x, n, taylorSeriesOptimized(x, n));
    printf("The %dth fibonacci number: %d\n", n, nthFibonacciSeries(n));
    printf("%dC%d: %d\n", n, m, nCr(n, m));
    printf("\nTower of Hanoi!\n");
    TOH(3, 1, 2, 3);
    return 0;
}