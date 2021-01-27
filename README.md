# Data Structures & Algorithms

Core concepts in DS and Algorithms coded in C 🐱‍👤

### Stack & Heap memory

-   **Stack**
    -   Used up for statically allocated memory
    -   Organized manner
-   **Heap**
    -   Used up for dynamically allocated memory
    -   Unorganized manner
    -   Must be treated as a resource

### Physical & Logical data structures

-   **Physical data structures**
    -   Arrays
    -   Linked Lists
-   **Logical data structures** are implemented using physical data structures
    -   Stack (linear)
    -   Queue (linear)
    -   Tree (non linear)
    -   Graph (non linear)
    -   Hash table (tables)

### Recursion vs loops

-   Recursion has an ascending as well as a descending phase considering the recursion stack
-   Loops have only an ascending phase

**Types of recursion**

-   Tail recursion
-   Head recursion
-   Tree recursion
-   Indirect recursion
-   Direct recursion

## Physical Data Structures

### Arrays

-   Array size is immutable
-   Stored in contiguous memory blocks
-   Memory allocated statically or dynamically

**Array ADT operations**

-   Inserting element at index
-   Deleting element from index
-   Displaying elements
-   Minimum and maximum elements in array
-   Linear and Binary search
-   Reversing an array
-   Left & right shift
-   Left & right rotate
-   Insert element in sorted array
-   Arrange negative elements on left and positive elements on right
-   Merge two arrays
-   Set operations
-   And more!

#### Strings

**ASCII values: (0-127)** A - 65, a - 97, 0 - 48

-   Characters given in single quotes
-   Strings given in double quotes (appends the '\0' delimiter)
-   Character pointers will create the string in heap unlike the previously mentioned two which is created in the stack
-   Delimiter of scanf() is space or new line, whereas for gets() it is new line

**String operations**

-   Length of string
-   Displaying strings
-   To upper or lower case
-   Reversing strings
-   Check if string is a palindrome or not
-   Check for duplicates in string
-   Check if string is an anagram or not
-   Permutations of a string using recursion

#### Matrices

**Types of Matrices**

-   **Diagonal matrix:** A[i][j] = 0 if i!=j
-   **Lower triangular matrix:** A[i][j] = 0 if i < j and A[i][j] != 0 if i >= j
-   **Upper triangular matrix:** A[i][j] = 0 if i > j and A[i][j] != 0 if i <= j
-   **Symmetric matrix:** A[i][j] = A[j][i] (Can be represented as a lower triangular or upper triangular matrix)
-   **Tridiagonal matrix:** non zero elements at i-j=0, i-j=1 and i-j=-1. Rest are zeroes.
-   **Toeplitz matrix:** A[i][j] = A[i-1][j-1] (elements at each of the diagonals are equal)

##### Sparse Matrices

-   Matrix in which most of the elements are zero
-   **3 column representation**
-   **Co-ordinate list**

### Linked Lists

-   Self referential data structures
-   Stored in heap memory
-   Memory allocated dynamically
-   Non contiguous memory blocks

**Singly linked list operations**

-   Displaying elements
-   Count number of nodes
-   Sum of elements
-   Maximum element
-   Linear search
-   Insert at a specific position
-   Delete at a specific position
-   Check if sorted
-   Remove duplicate elements
-   Reverse the nodes
    -   Using an auxilliary array
    -   Using sliding pointers
    -   Using recursion
-   Concatenate two linked lists
-   Merge two linked lists
-   Check for the presence of loops

**Circular linked list operations**

-   Displaying elements (recursive and iterative approach)
-   Inserting at a position
-   Deleting from a position

**Doubly linked list operations**

-   Displaying elements (recursive and iterative approach)
-   Inserting at a position
-   Deleting from a position
-   Reversing a doubly linked list

## Logical Data Structures

### Stack

-   Linear Data Structures
-   Follows a LIFO order for performing operations
-   Stacks can be implemented using
    -   Arrays
    -   Linked Lists
-   Insertion and deletion occurs essentially on the same side
-   Applications
    -   Parenthesis matching
    -   Infix to Postfix conversion
    -   Postfix expression evaluation

### Queue

-   Linear Data Structures
-   Follows a FIFO order for performing operations
-   Queues can be implemented using
    -   Arrays (Circular queues are implemented rather than the linear queues to efficiently use all contiguous blocks)
    -   Linked Lists
-   Insertion occurs on the rear end, deletion occurs on the front end
-   Applications
    -   Task scheduling
    -   Serving requests on a single shared resource
-   Types
    -   Linear queue
    -   Circular queue
    -   Double ended queue
    -   Priority queue
