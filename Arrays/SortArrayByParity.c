int* sortArrayByParity(int* A, int ASize, int* returnSize){
    // Input: [1, 2, 3, 4]
    // Output: [2, 4, 1, 3]
    // Time complexity: O(n)
    // Space complexity: O(1)
    int i = 0;
    int j = ASize-1;
    *returnSize = ASize;
    
    while(i<j) {
        // Swap if odd number is in the beginning and even number is in the end
        if (A[i]%2 > A[j]%2) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        // If even number is now present at the beginning increment the array pointer
        if (A[i]%2 == 0) i++;
        // If odd number is at the end decrement the array pointer
        if (A[j]%2 == 1) j--;
    }
    return A;
}