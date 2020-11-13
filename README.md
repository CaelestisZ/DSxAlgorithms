# Data Structures & Algorithms
Core concepts in DS and Algorithms coded in C 🐱‍👤

## Stack & Heap memory

 - **Stack**
    - Used up for statically allocated memory
    - Organized manner
 - **Heap**
    - Used up for dynamically allocated memory
    - Unorganized manner
    - Must be treated as a resource

## Physical & Logical data structures

 - **Physical data structures**
    - Arrays
    - Linked Lists
 - **Logical data structures** are implemented using physical data structures
    - Stack (linear)
    - Queue (linear)
    - Tree (non linear)
    - Graph (non linear)
    - Hash table (tables)

## Recursion vs loops

 - Recursion has an ascending as well as a descending phase considering the recursion stack
 - Loops have only an ascending phase

## Types of recursion

 - Tail recursion
 - Head recursion 
 - Tree recursion 
 - Indirect recursion
 - Direct recursion

## Arrays

Remember, the size of an array cannot be increased.

**Array ADT operations** 

 - Inserting element at index
 - Deleting element from index
 - Displaying elements
 - Minimum and maximum elements in array
 - Linear and Binary search
 - Reversing an array
 - Left & right shift
 - Left & right rotate
 - Insert element in sorted array
 - Arrange negative elements on left and positive elements on right
 - Merge two arrays
 - Set operations
 - And more!

## Strings

**ASCII values: (0-127)** A - 65, a - 97, 0 - 48

 - Characters given in single quotes
 - Strings given in double quotes (appends the '\0' delimiter)
 - Character pointers will create the string in heap unlike the previously mentioned two which is created in the stack
 - Delimiter of scanf() is space or new line, whereas for gets() it is new line

**String operations** 

 - Length of string
 - Displaying strings
 - To upper or lower case
 - Reversing strings
 - Check if string is a palindrome or not
 - Check for duplicates in string
 - Check if string is an anagram or not
 - Permutations of a string using recursion

## Matrices

### Types of Matrices

 - Diagonal matrix: A[i][j] = 0 if i!=j
 - Lower triangular matrix: A[i][j] = 0 if i < j and A[i][j] != 0 if i >= j
 - Upper triangular matrix: A[i][j] = 0 if i > j and A[i][j] != 0 if i <= j 
 - Symmetric matrix: A[i][j] = A[j][i] (Can be represented as a lower triangular or upper triangular matrix)
 - Tridiagonal matrix: non zero elements at i-j=0, i-j=1 and i-j=-1. Rest are zeroes.
 - Toeplitz matrix: A[i][j] = A[i-1][j-1] (elements at each of the diagonals are equal)
 