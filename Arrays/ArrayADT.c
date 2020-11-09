#include<stdio.h>
#include<stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

int getIndexArrayADT(struct Array A, int index) {
    if (index >= 0 && index<A.length) {
        return A.A[index];
    }
}

int setIndexArrayADT(struct Array *A, int index, int value) {
    if (index >= 0 && index<A->length) {
        A->A[index] = value;
        return 0;
    }
    return 1;
}

int maxElementArrayADT(struct Array A) {
    int max = A.A[0];
    for (int i = 1; i<A.length; i++) {
        if (max<A.A[i]) {
            max = A.A[i];
        }
    }
    return max;
}

int sumArrayADT(struct Array A) {
    int sum = 0;
    for (int i = 0; i<A.length; i++) {
        sum += A.A[i];
    }
    return sum;
}

int sumRecursiveArrayADT(struct Array A, int lastIndex) {
    if (lastIndex < 0) {
        return 0;
    }
    else {
        return A.A[lastIndex] + sumRecursiveArrayADT(A, lastIndex - 1);
    }
}

int minElementArrayADT(struct Array A) {
    int min = A.A[0];
    for (int i = 1; i<A.length; i++) {
        if (min > A.A[i]) {
            min = A.A[i];
        }
    }
    return min;
}

int displayArrayADT(struct Array A) {
    printf("The elements of the array are: \n");
    for (int i = 0; i<A.length; i++) {
        printf("%d ", A.A[i]);
    }
    printf("\n");
    return 1;
}

int addArrayADT(struct Array *A, int ele) {
    if (A->size == A->length) {
        printf("Overflow!\n");
        return 1;
    }
    A->A[A->length++] = ele;
    printf("%d was added in the beginning\n", ele);
    return 0;
}

int insertAtIndexArrayADT(struct Array *A, int index, int ele) {
    if (A->size == A->length || index > A->length || index<0) {
        printf("Overflow!\n");
        return 1;
    }
    for (int i = A->length; i>index; i--) {
        A->A[i] = A->A[i-1];
    }
    A->A[index] = ele;
    A->length++;
    printf("%d inserted at %d\n", ele, index);
    return 0;
}

int deleteAtIndexArrayADT(struct Array *A, int index) {
    if (index<0 || index>=A->length) {
        printf("Index out of bounds!\n");
        return 1;
    }
    for (int i = index; i<A->length; i++) {
        A->A[i] = A->A[i+1];
    }
    printf("Deleted element at %d\n", index);
    A->length--;
    return 0;
}

int linearSearchArrayADT(struct Array A, int key) {
    for (int i = 0; i<A.length; i++) {
        if (A.A[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearchIterativeArrayADT(struct Array A, int key) {
    int low = 0;
    int high = A.length-1;

    while (low <= high) {
        int mid = (low + high)/2;
        if (key == A.A[mid]) {
            return mid;
        }
        else if (key < A.A[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int binarySearchRecursiveArrayADT(struct Array A, int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high)/2;
        if (A.A[mid] == key) {
            return mid;
        }
        else if (A.A[mid] > key) {
            return binarySearchRecursiveArrayADT(A, low, mid - 1, key);
        }
        else {
            return binarySearchRecursiveArrayADT(A, mid + 1, high, key);
        }
    }
    return -1;
}

// Time complexity = O(n)
// Space complexity = O(n);
int reverseArrayADT(struct Array *A) {
    struct Array B;
    B.length = A->length;
    B.size = A->size;
    B.A = (int *)malloc((B.size)*sizeof(int));
    for (int i = B.length-1; i>=0; i--) {
        B.A[B.length-1-i] = A->A[i];
    }
    for (int i = 0; i<A->length; i++) {
        A->A[i] = B.A[i];
    }
    return 0;
}

int *swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Time complexity = O(n)
// Space complexiy = O(1)
int reverseOptimizedArrayADT(struct Array *A) {
    int i = 0;
    int j = A->length-1;
    while (i<j) {
        // swap(&(A->A[i]), &(A->A[j]));
        int temp = A->A[i];
        A->A[i] = A->A[j];
        A->A[j] = temp;
        i++;
        j--;
    }
    return 1;
}

int leftShiftArrayADT(struct Array *A) {
    for (int i = 0; i<A->length-1; i++) {
        A->A[i] = A->A[i+1];
    }
    A->A[A->length-1] = 0;
    return 0;
}

int leftRotateArrayADT(struct Array *A) {
    int temp = A->A[0];
    for (int i = 0; i<A->length; i++) {
        A->A[i] = A->A[i+1];
        if (i==A->length-1) {
            A->A[i] = temp;
        }
    }
    return 0;
}

int rightShiftArrayADT(struct Array *A) {
    for (int i = A->length-1; i>=1; i--) {
        A->A[i] = A->A[i-1];
    }
    A->A[0] = 0;
    return 0;
}

int rightRotateArrayADT(struct Array *A) {
    int temp = A->A[A->length-1];
    for (int i = A->length-1; i>=0; i--) {
        A->A[i] = A->A[i-1];
        if (i==0) {
            A->A[i] = temp;
        }
    }
    return 0;
}

int insertSortedArrayADT(struct Array *A, int element) {
    int i = A->length-1;
    while(A->A[i]>element) {
        A->A[i+1] = A->A[i];
        i--;
    }
    A->A[i+1] = element;
    return 0;
}

int isSortedArrayADT(struct Array A) {
    int i = 0;
    while(i<A.length-1) {
        if (A.A[i]>A.A[i+1]) {
            return 0;
        }
        i++;
    }
    return 1;
} 

int negativePositiveArrayADT(struct Array *A) {
    int i = 0;
    int j = A->length - 1;
    while(i<j) {
        while (A->A[i]<0) {
            i++;
        }
        while (A->A[j]>=0) {
            j--;
        }
        if (i<j) {
            int temp = A->A[i];
            A->A[i] = A->A[j];
            A->A[j] = temp;
        }
    }
    return 0;
}

int main() {
    struct Array arr;
    int position;
    printf("Enter size of an array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));

    arr.length = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &arr.length);

    printf("Enter all elements: ");
    for (int i = 0; i<arr.length; i++) {
        scanf("%d", &(arr.A[i]));
    }

    displayArrayADT(arr);

    // Call by address because the value of the passed variable is to be changed
    addArrayADT(&arr, 6);
    displayArrayADT(arr);

    // Call by address because the value of the passed variable is to be changed
    insertAtIndexArrayADT(&arr, 6, 0);
    displayArrayADT(arr);

    // Call by address because the value of the passed variable is to be changed
    deleteAtIndexArrayADT(&arr, 6);
    displayArrayADT(arr);

    position = linearSearchArrayADT(arr, 5);
    printf("Position via Linear Search is: %d\n", position);

    position = binarySearchIterativeArrayADT(arr, 5);
    printf("Position via Binary Search Iterative is: %d\n", position);
    
    position = binarySearchRecursiveArrayADT(arr, 0, arr.length-1, 5);
    printf("Position via Binary Search Recursive is: %d\n", position);

    reverseArrayADT(&arr);
    printf("The array is reversed!\n");
    displayArrayADT(arr);

    reverseOptimizedArrayADT(&arr);
    printf("The array is reversed using an optimized algorithm!\n");
    displayArrayADT(arr);

    // leftShiftArrayADT(&arr);
    // printf("Left shifted array by one\n");
    // displayArrayADT(arr);

    // rightShiftArrayADT(&arr);
    // printf("Right shifted array by one\n");
    // displayArrayADT(arr);

    // leftRotateArrayADT(&arr);
    // printf("Left rotated array by one\n");
    // displayArrayADT(arr);

    // leftRotateArrayADT(&arr);
    // printf("Left rotated array by one\n");
    // displayArrayADT(arr);

    // rightRotateArrayADT(&arr);
    // printf("Right rotated array by one\n");
    // displayArrayADT(arr);

    insertSortedArrayADT(&arr, 3);
    printf("%d inserted such that the resultant array is sorted\n", 3);
    displayArrayADT(arr);

    int isSorted = isSortedArrayADT(arr);
    printf("Returned value for isSorted(): %d\n", isSorted);

    return 0;  
}