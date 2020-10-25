// Input: [1,0,2,3,0,4,5,0]
// Output: null
// Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

void duplicateZeros(int* arr, int arrSize){
    int possibleDups = 0;
    int length = arrSize-1;
    for (int i = 0; i<length-possibleDups; i++) {
        if (arr[i] == 0) {
            if (i==length-possibleDups) {
                arr[length] = 0;
                length--;
                break;
            }
            possibleDups++;
        }
    }
    
    int last = length-possibleDups;
    
    for (int i = last; i>=0; i--) {
        if (arr[i]==0) {
            arr[i+possibleDups] = 0;
            possibleDups--;
            arr[i+possibleDups] = 0;
        }
        else {
            arr[i+possibleDups] = arr[i];
        }
    }
}