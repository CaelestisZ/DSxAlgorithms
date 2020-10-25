#include<stdio.h>

void SelectionSort(int* nums, int n){
    // The idea is to compare each of the elements simultaneously and bring the minimum element to the beginning
    // This is clearly achieved with a time complexity of O(n^2) and a space complexity of O(1) 
    // Therefore, this method is quite useful when memory write is a costly operation but the user is willing to
    // give minimal priority to time.
    int temp;
    for (int i = 0; i<n; i++) {
        for (int j = i+1; j<n; j++) {
            if (nums[i] > nums[j]) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void DisplayArray(int *nums, int n) {
    for (int i = 0; i<n; i++) {
        printf("%d ", nums[i]);
    }
}

int main() {
    int arr[] = {1, 3, 2, 4, 5};
    // SelectionSort(arr, 5);
    DisplayArray(arr, 5);
}