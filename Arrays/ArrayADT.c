#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Array {
    int *A;
    int size;
    int length;
};

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

    return 0;  
}