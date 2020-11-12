#include<stdio.h>
#include<string.h>

int lengthString(char string[]) {
    int i;
    for (i = 0; string[i]!='\0'; i++) {

    }
    printf("The length of the string is: %ld\n", strlen(string));
    return 0;
}

int displayString(char string[]) {
    printf("The string is: %s\n", string);
    return 0;
}

int toUpperCase(char string[]) {
    for (int i = 0; string[i]!='\0'; i++) {
        string[i] = string[i]-32;
    }
    return 0;
}

int isValid(char string[]) {
    for (int i = 0; string[i]!='\0'; i++) {
        if (!(string[i]>=65 && string[i]<=90) && !(string[i]>=97 && string[i]<=122)) {
            return 0;
        }
    }
    return 1;
}

int reverseString(char string[]) {
    // Time complexity: O(n)
    // Space complexity: O(n) (to store the reversed array)
    char reversedString[strlen(string)];
    int i; 
    int j = 0;
    // find the end of the string; i can be initialized to strlen(string) instead
    for (i = 0; string[i]!='\0'; i++) {

    }
    i--;
    // copy the string from the end into the beginning of the reversedString
    while (i>=0) {
        reversedString[j] = string[i];
        i--;
        j++;
    }
    reversedString[j] = '\0';
    // copy it back
    j = 0;
    for (i = 0; string[i]!='\0'; i++) {
        string[i] = reversedString[j];
        j++;
    }
    return 0;
}

int reverseStringOptimized(char string[]) {
    int i = 0;
    int j = strlen(string)-1;
    // int j = 0;
    // for (j = 0; string[j]!='\0'; j++) {

    // }
    // j--;
    while (i<j) {
        char temp;
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++;
        j--;
    }
    return 0;
}

int isPalindromeString(char string[]) {
    // Reverse the string and store it in another
    // Check whether both the string and the reversed string are equal
    int i = 0;
    int j = 0;
    char reverse[strlen(string)];

    for (i = 0; string[i]!='\0'; i++) {

    }
    i--;
    while (i>=0) {
        reverse[j] = string[i];
        i--;
        j++;
    }
    
    for (i = 0, j = 0; string[i]!='\0' && reverse[i]!='\0'; i++, j++) {
        if (reverse[i]!=string[i]) {
            return 0;
        }
    }
    return 1;
}

int isPalindromeOptimizedString(char *string) {
    int i = 0;
    int j = strlen(string)-1;
    while (i<j) {
        if (string[i]!=string[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int duplicatesString(char *string) {
    for (int i = 0; string[i]!='\0'; i++) {
        int key = string[i];
        int count = 1;
        if (string[i]!='0') {
            for (int j = i+1; string[j]!='\0'; j++) {
                if (string[i] == string[j]) {
                    count++;
                    *(string + j) = '0';
                }
            }
            if (count > 1) {
                printf("%c is repeated %d times\n", key, count);
            }
        }        
    }
    return 0;
}

int duplicatesHashingString(char *string) {
    int hash[52] = {0};
    for (int i = 0; string[i]!='\0'; i++) {
        if (string[i]>=97 && string[i]<=122) {
            hash[string[i]-97]++;
        }
        else if (string[i]>=65 && string[i]<=90) {
            hash[string[i]-65+26]++;
        }
        else {
            printf("This program supports only A-Z and a-z!\n");
        }
    }
    for (int i = 0; i<52; i++) {
        if (hash[i]>1 && i<=26) {
            printf("%c is repeated %d times\n", i+97, hash[i]);
        }
        else if (hash[i]>1 && i>=27) {
            printf("%c is repeated %d times\n", i-26+65, hash[i]);
        }
    }
    return 0;
}

int duplicatesBitWiseString(char *string) {
    int H = 0, x;
    for (int i = 0; string[i]!='\0'; i++) {
        x = 1;
        x = x << (string[i] - 97);
        if (string[i]!='0') {
            if ((x & H) > 0) {
                printf("Duplicate: %c\n", string[i]);
                string[i] = '0'; 
            }
            else {
                H = x|H;
            }
        }
    }
    return 0;
}

int anagramString(char *A, char *B) {
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    int found;
    for (int i = 0; A[i]!='\0'; i++) {
        found = 0;
        for (int j = 0; B[j]!='\0'; j++) {
            if (A[i]==B[j] && found==0) {
                found = 1;
            }
        }
        if (found == 0) {
            return found;
        }
    }
    return found;
}

int anagramHashingString(char *A, char *B) {
    // Time complexity: O(n)
    // Space complexity: O(n)
    int hash[26] = {0};
    for (int i = 0; A[i]!='\0'; i++) {
        hash[A[i]-97]++;
    }
    for (int j = 0; B[j]!='\0'; j++) {
        hash[B[j]-97]--;
        if (hash[B[j]-97]<0) {
            return 0;
        }
    }
    return 1;
}

void permutationsString(char string[], int k) {
    static int A[10] = {0};
    static char res[10];
    int i;

    if (string[k]=='\0') {
        res[k] = '\0';
        printf("%s\n", res);
    }
    else {
        for (i = 0; string[i]!='\0'; i++) {
            if (A[i]==0) {
                A[i] = 1;
                res[k] = string[i];
                permutationsString(string, k+1);
                A[i] = 0; 
            }
        }
    }
}

void permutationsOptimizedString(char string[], int low, int high) {
    if (low==high) {
        printf("%s\n", string);
    }
    else {
        for (int i = low; i<=high; i++) {
            char temp;
            // Swap first
            temp = string[low];
            string[low] = string[i];
            string[i] = temp;
            permutationsOptimizedString(string, low+1, high);
            // Swap it back
            string[i] = string[low];
            string[low] = temp;
        }
    }
}

int main() {
    char ctring[] = "welcomeeee";
   
    char string1[] = "helloooooooooo";
    
    char A[] = "medical";
    char B[] = "decimak";

    displayString(ctring);
    lengthString(ctring);

    toUpperCase(ctring);
    displayString(ctring);

    printf("String validation: %d\n", isValid(ctring));

    reverseString(ctring);
    displayString(ctring);

    reverseStringOptimized(ctring);
    displayString(ctring);

    if (isPalindromeString(string1)) {
        printf("The string is a palindrome! (Using a reversed copy of the array)\n");
    }
    else {
        printf("The string is not a palindrome! (Using a reversed copy of the array)\n");
    }

    if (isPalindromeOptimizedString(string1)) {
        printf("The string is a palindrome! (Without using a reversed copy of the array)\n");
    }
    else {
        printf("The string is not a palindrome! (Without using a reversed copy of the array)\n");
    }

    if (anagramHashingString(A, B)) {
        printf("The strings are anagrams!\n");
    }
    else {
        printf("The strings are not anagrams!\n");
    }

    // permutationsString(A, 0);


    printf("\nPermutations of the string are:\n");
    permutationsOptimizedString(A, 0, 6);
    
    return 0;
}