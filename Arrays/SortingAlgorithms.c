#include<stdio.h>
#include<stdbool.h>

void SelectionSort(int* nums, int n){
    // The idea is to compare each of the elements simultaneously and bring the minimum element to the beginning
    // Time complexity = O(n^2)
    // Space complexity = O(1)
    // Therefore, this method is quite useful when memory write is a costly operation but the user is willing to
    // give minimal priority to time.
    // Worst case = Best case = O(n^2)
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

void InefficientBubbleSort(int *arr, int n) {
    // The main idea is to swap each of the adjacent elements after comparing, do this until the last position has the
    // largest element.
    // Time complexity = O(n^2)
    // Space complexity = O(1)
    // Best case = Worst case = O(n^2)
    int temp;
    for (int i = 0; i<n-1; i++) {
        for (int j = 0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        } 
    }
}

void EfficientBubbleSort(int *arr, int n) {
    // The main idea is to swap each of the adjacent elements after comparing, do this until the last position has the
    // largest element.
    // Time complexity = O(n^2)
    // Space complexity = O(1)
    // Best case = O(n) 
    // Worst case = O(n^2)
    int temp;
    bool isSwapped;
    for (int i = 0; i<n-1; i++) {
        isSwapped = false;
        for (int j = 0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSwapped = true;
            }
        }
        if (isSwapped == false) {
            break;
        }
    }
}

void DisplayArray(int *nums, int n) {
    // Classic function to display the array
    for (int i = 0; i<n; i++) {
        printf("%d ", nums[i]);
    }
}

int main() {
    int arr[] = {1, 3, 2, 4, 5};
    // SelectionSort(arr, 5);
    // InefficientBubbleSort(arr, 5);
    // EfficientBubbleSort(arr, 5);
    DisplayArray(arr, 5);
}