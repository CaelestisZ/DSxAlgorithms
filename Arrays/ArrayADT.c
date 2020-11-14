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
    while(element<A->A[i]) {
        A->A[i+1] = A->A[i];
        i--;
    }
    A->A[i+1] = element;
    A->length++;
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

struct Array *mergeArrayADT(struct Array *A, struct Array *B) {
    
    int i = 0;
    int j = 0;
    int k = 0;
    struct Array *C;
    C->length = A->length + B->length;
    C->size = A->size + B->size;
    C->A = (int *)malloc(C->size * sizeof(int));
    
    while (i<A->length && j<B->length) {
        if (A->A[i]<B->A[j]) {
            C->A[k++] = A->A[i++];
        }
        else {
            C->A[k++] = A->A[j++];
        }
    }

    for (;i<A->length;i++) {
        C->A[k++] = A->A[i];
    }
    for (;j<B->length;j++) {
        C->A[k++] = B->A[j];
    }
    
    return C;
}

struct Array *unionArrayADT(struct Array *A, struct Array *B) {
    int i = 0;
    int j = 0;
    int k = 0;
    struct Array *C;
    C->length = A->length + B->length;
    C->size = A->size + B->size;
    C->A = (int *)malloc(C->size * sizeof(int));
    
    while (i<A->length && j<B->length) {
        if (A->A[i]<B->A[j]) {
            C->A[k++] = A->A[i++];
        }
        else if (A->A[i]>B->A[j]){
            C->A[k++] = B->A[j++];
        }
        else {
            A->A[k++] = A->A[i++];
            j++;
        }
    }

    C->length = k;

    for (;i<A->length;i++) {
        C->A[k++] = A->A[i];
    }
    for (;j<B->length;j++) {
        C->A[k++] = B->A[j];
    }
    
    return C;
}

struct Array* intersectionArrayADT(struct Array *A, struct Array *B) {
    int i = 0;
    int j = 0;
    int k = 0;
    struct Array *C;
    C->size = A->size + B->size;
    C->A = (int *)malloc(C->size * sizeof(int));
    
    while (i<A->length && j<B->length) {
        if (A->A[i]<B->A[j]) {
            i++;
        }
        else if (A->A[i]>B->A[j]){
            j++;
        }
        else {
            C->A[k++] = A->A[i++];
            j++;
        }
    }

    C->length = k;
    
    return C;
}

struct Array *differenceArrayADT(struct Array *A, struct Array *B) {
    int i = 0;
    int j = 0;
    int k = 0;
    struct Array *C;
    C->length = A->length + B->length;
    C->size = A->size + B->size;
    C->A = (int *)malloc(C->size * sizeof(int));
    
    while (i<A->length && j<B->length) {
        if (A->A[i]<B->A[j]) {
            C->A[k++] = A->A[i++];
        }
        else if (A->A[i]>B->A[j]){
            j++;
        }
        else {
            i++;
            j++;
        }
    }

    C->length = k;

    for (;i<A->length;i++) {
        C->A[k++] = A->A[i];
    }   
    
    return C;
}


int singleMissingElementArrayADT(struct Array* A) {
    int sum = 0;
    for (int i = 0; i<A->length; i++) {
        sum += A->A[i];
    }
    int n = A->A[A->length-1];
    return ((n+1)*n/2)-sum;
}

int singleMissingElementOptimizedArrayADT(struct Array *A, int low, int high) {
    int diff = A->A[low]-low;
    for (int i = 0; i<A->length; i++) {
        if ((A->A[i]-i)!=diff) {
            return i+diff;
        }
    }
}

int multipleMissingElementsArrayADT(struct Array *A, int low, int high) {
    // Time complexity: O(n*missing)
    // Space complexity: O(1)
    int diff = A->A[low]-low;
    for (int i = 0; i<A->length; i++) {
        if (A->A[i]-i!=diff){
            while(A->A[i]-i>diff) {
                printf("%d ", i+diff);
                diff++;
            }
        }
    }
    printf("\n");
    return 0;
}

int multipleMissingElementsFasterArrayADT(struct Array *A) {
    // Implementing the simplest form of hashing 
    // Time complexity: O(n) [faster than the previous method]
    // Space complexity: O(n+missing)
    int *hash;
    int low=A->A[0];
    int high=A->A[0];
    for (int i = 1; i<A->length; i++) {
        if (low>A->A[i]) {
            low = A->A[i];
        }
    }
    for (int i = 1; i<A->length; i++) {
        if (high<A->A[i]) {
            high = A->A[i];
        }
    }
    hash = (int *)malloc(high * sizeof(int));
    for (int i = 0; i<A->length; i++) {
        hash[A->A[i]]++;
    }
    for (int i = low; i<high; i++) {
        if (hash[i]==0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

int duplicateElementsSortedArrayADT(struct Array* A) {
    // Time complexity: O(n)
    // Space complexity: O(1)
    int lastDuplicate = 0;
    printf("The duplicate elements are: \n");
    for (int i = 0; i<A->length-1; i++) {
        if (A->A[i]==A->A[i+1] && A->A[i]!=lastDuplicate) {
            // int count = 0;
            // int j = i;
            // lastDuplicate = A->A[i];
            // printf("%d, count: ", A->A[i]);
            // while(A->A[j]==lastDuplicate) {
            //     count++;
            //     j++;
            // }
            // printf("%d\n", count);
            int j = i+1;
            lastDuplicate = A->A[i];
            while(A->A[i]==A->A[j]) {
                j++;
            }
            printf("%d occurs %d times\n", A->A[i], j-i);
            i = j-1;
        }
    }
    return 0;
}

int duplicateElementsFasterSortedArrayADT(struct Array *A){
    // Time complexity: O(n)
    // Space complexity: O(n)
    int *hash;
    int high=A->A[0];
    for (int i = 1; i<A->length; i++) {
        if (high<A->A[i]) {
            high = A->A[i];
        }
    }
    hash = (int *)malloc(high * sizeof(int));
    for (int i = 0; i<A->length; i++) {
        hash[A->A[i]]++;
    }
    for (int i = 0; i<high; i++) {
        if (hash[i]!=0) {
            printf("%d occurs %d times", i, hash[i]);
        }
    }
}

int duplicatesUnsortedArrayADT(struct Array A) {
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    for (int i = 0; i<A.length; i++) {
        int count = 1;
        if (A.A[i]!=-1) {
            for (int j = i+1; j<A.length; j++) {
                if (A.A[i]==A.A[j]) {
                    count++;
                    A.A[j] = -1;
                }
            }
            if (count > 1) {
                printf("%d occurs %d times\n", A.A[i], count);
            }
        }
    }
}

int sumOfPairIsKArrayADT(struct Array *A, int sum) {
    printf("Pair of elements with sum = %d\n", sum);
    for (int i = 0; i<A->length-1; i++) {
        for (int j = i+1; j<A->length; j++) {
            if (A->A[j] + A->A[i] == sum) {
                printf("%d + %d = %d\n", A->A[j], A->A[i], sum);
            }
        }
    }
    return 0;
}

int sumOfPairIsKHashingArrayADT(struct Array *A, int sum) {
    // Time complexity: O(n)
    // Space complexity: O(n)
    printf("Pair of elements with sum = %d implemented using hashing\n", sum);
    int *hash;
    int high = A->A[0];
    for (int i = 1; i<A->length; i++) {
        if (high<A->A[i]) {
            high = A->A[i];
        }
    }
    hash = (int *)malloc(high*sizeof(int));
    for (int i = 0; i<A->length; i++) {
        if (hash[sum-(A->A[i])]!=0) {
            printf("%d + %d = %d\n", A->A[i], sum-(A->A[i]), sum);
        }
        hash[A->A[i]]++;
    }
    return 0;
}

int sumOfPairIsKSortedArrayADT(struct Array *A, int sum) {
    int i = 0;
    int j = A->length-1;
    printf("Pair of elements with sum = %d for a sorted array\n", sum);
    while(i<j) {
        if (A->A[i]+A->A[j]>sum) {
            j--;
        }
        else if (A->A[i]+A->A[j]<sum) {
            i++;
        }
        else {
            printf("%d + %d = %d\n", A->A[i], A->A[j], sum);
            i++;
            j--;
        }
    }
    return 0;
}

int minMaxSingleScanArrayADT(struct Array *A) {
    int min = A->A[0];
    int max = A->A[0];
    for (int i = 1; i<A->length; i++) {
        if (min>A->A[i]) {
            min = A->A[i];
        }
        else if (max<A->A[i]) {
            max = A->A[i];
        }
    }
    printf("\nMinimum element: %d\nMaximum element: %d\n", min, max);
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

    // // Call by address because the value of the passed variable is to be changed
    // addArrayADT(&arr, 6);
    // displayArrayADT(arr);

    // // Call by address because the value of the passed variable is to be changed
    // insertAtIndexArrayADT(&arr, 6, 0);
    // displayArrayADT(arr);

    // // Call by address because the value of the passed variable is to be changed
    // deleteAtIndexArrayADT(&arr, 6);
    // displayArrayADT(arr);

    // position = linearSearchArrayADT(arr, 5);
    // printf("Position via Linear Search is: %d\n", position);

    // position = binarySearchIterativeArrayADT(arr, 5);
    // printf("Position via Binary Search Iterative is: %d\n", position);
    
    // position = binarySearchRecursiveArrayADT(arr, 0, arr.length-1, 5);
    // printf("Position via Binary Search Recursive is: %d\n", position);

    // reverseArrayADT(&arr);
    // printf("The array is reversed!\n");
    // displayArrayADT(arr);

    // reverseOptimizedArrayADT(&arr);
    // printf("The array is reversed using an optimized algorithm!\n");
    // displayArrayADT(arr);

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

    // insertSortedArrayADT(&arr, 3);
    // printf("%d inserted such that the resultant array is sorted\n", 3);
    // displayArrayADT(arr);

    // int isSorted = isSortedArrayADT(arr);
    // printf("Returned value for isSorted(): %d\n", isSorted);

    // printf("Missing elements in array are:\n");
    // multipleMissingElementsFasterArrayADT(&arr);

    // duplicatesUnsortedArrayADT(arr);

    // sumOfPairIsKArrayADT(&arr, 10);
    // sumOfPairIsKHashingArrayADT(&arr, 10);
    // sumOfPairIsKSortedArrayADT(&arr, 10);

    // minMaxSingleScanArrayADT(&arr);

    insertSortedArrayADT(&arr, 3);

    displayArrayADT(arr);

    return 0;  
}