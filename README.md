# Data Structures & Algorithms

Core concepts in Data Structures and Algorithms coded in C 🐱‍👤

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
    -   Stacks (linear)
    -   Queues (linear)
    -   Trees (non linear)
    -   Graphs (non linear)
    -   Hash tables (tables)

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
-   Representations
    -   3 column representation
    -   Co-ordinate list

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

### Stacks

-   Linear Data Structure
-   Follows a LIFO order for performing operations
-   Insertion and deletion occurs essentially on the same side
-   Implementations
    -   Arrays
    -   Linked Lists
-   Applications
    -   Parenthesis matching
    -   Infix to Postfix conversion
    -   Postfix expression evaluation

### Queues

-   Linear Data Structure
-   Follows a FIFO order for performing operations
-   Insertion occurs on the rear end, deletion occurs on the front end
-   Implementations
    -   Arrays (Circular queues are implemented instead of linear queues to efficiently use all contiguous blocks)
    -   Linked Lists
-   Applications
    -   Task scheduling
    -   Serving requests on a single shared resource
-   Types
    -   Linear queue
    -   Circular queue
    -   Double ended queue
    -   Priority queue

### Trees

-   Non-Linear Data Structure
-   Types
    -   Depending on the maximum number of children for the each node (binary, n-ary trees)
    -   Full Binary Trees
    -   Complete (almost complete (yes. it's the same thing)) Binary Trees
    -   Strict Binary Trees: Degree of each node must be either 0 or 2
-   Implementations
    -   Arrays (parent: i, left: 2i, right: 2i+1)
    -   Linked Lists (structure similar to that of doubly linked lists)
-   It is necessary to have the preorder/postorder traversal along with the inorder traversal for constructing a Binary Tree
-   Number of trees possible with n nodes = Catalan number

#### Binary Search Trees

-   Logical variant of the binary tree, built for search optimization
-   Duplicate elements are not allowed in a BST
-   root->left < root < root->right
-   Left and right subtrees must also be a BST 
-   Inorder traversal gives a sorted order of the nodes
-   Therefore to construct a BST, the preorder/postorder traversal is sufficient 
-   Drawback: The efficiency of a BST is wholly based upon the order of insertion of nodes [O(log(n)) to O(n)]

#### Binary Heap

-   Must be an almost complete binary tree
-   Therefore, height = log(n)
-   Types
    -   Max heap: Ancestors are greater in value than their descendants
    -   Min heap: Ancestors are smaller in value than their descendants
-   Usually represented in arrays
-   Parent: i, Left child: 2i, Right child: 2i+1
-   Implementations
    -   Inserting
    -   Deleting (the root node) 
    -   Heap sort
    -   Heapify
    -   Priority queues (log(n) time complexity achieved using heap)

### Hash Tables

-   Searching possible in O(1) at the cost of large storage space
-   Ideal hash function: maps a distinct set of elements to a set of integers with no collisions
-   Ideal hash functions usually require a large storage space and hence is to be dealt with 

-   **Hashing Techniques to avoid collisions**
    -   Open hashing (dynamically creates additional space)
        -   Chaining
    -   Closed hashing (open addressing)
        -   Linear Probing
        -   Quadratic Probing
        -   Double Hashing

## Popular Sorting Algorithms

-   **Comparison based sort**
    -   O(n^2)
        -   Bubble Sort
        -   Insertion Sort
        -   Selection Sort
    -   O(n*log(n))
        -   Heap Sort
        -   Merge Sort
        -   Quick Sort
        -   Tree Sort
    -   O(n^(3/2))
        -   Shell Sort
-   **Index based sort**
    -   O(n)
        -   Count Sort
        -   Bucket/Bin Sort
        -   Radix Sort
