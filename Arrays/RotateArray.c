#include <stdio.h>

// Two methods
// - Reverse from 0 upto D, Reverse from D upto N and further reverse from 0 to N O(N)
// - You know what the second method is O(N*D)

void display(int a[], int n) {
    for (int i = 0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// int rotateByOne(int a[], int n) {
//     int temp=a[0], i;
//     for (i = 0; i<n-1; i++) {
//         a[i] = a[i+1];
//     }
//     a[i] = temp;
// }

// int rotateByD(int a[], int n, int d) {
//     for (int i=0; i<d; i++) {
//         rotateByOne(a, n);
//     }
//     display(a, n);
// }

int reverse(int arr[], int start, int end) {
    int temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
	//code
	int T, N, D;
	scanf("%d", &T);
	while(T>0) {
	    scanf("%d %d", &N, &D);
	    int arr[N], temp[N];
	    for(int i = 0; i<N; i++) {
            scanf("%d ", &arr[i]);
        }
	   // rotateByD(arr, N, D);
	   //for(int i = 0; i<N; i++) {
	   //    temp[i] = arr[i];
	   //}
	   //for (int i = D; i<N+D; i++) {
	   //    arr[i-D] = temp[i];
	   //}
	   //for (int i = 0; i<D; i++) {
	   //    arr[i+N-D] = temp[i];
	   //}
	   reverse(arr, 0, D-1);
	   reverse(arr, D, N-1);
	   reverse(arr, 0, N-1);
	   display(arr, N);
       T--;
	}
	return 0;
}