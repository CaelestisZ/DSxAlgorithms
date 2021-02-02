#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define LESS_THAN_SIZE 7

int hash(int key)
{
    return key % SIZE;
}

int hash2(int key)
{
    return LESS_THAN_SIZE - key % LESS_THAN_SIZE;
}

int linearProbe(int H[], int key)
{
    int index = hash(key);
    int i = 0;

    while (H[(index + i) % SIZE] != 0)
    {
        i++;
    }
    return i;
}

int quadraticProbe(int H[], int key)
{
    int index = hash(key);
    int i = 0;

    while (H[(index + (i * i)) % SIZE] != 0)
    {
        i++;
    }

    return (index + (i * i)) % SIZE;
}

int doubleHashing(int H[], int key)
{
    int index = hash(key);
    int index2 = hash2(key);
    int i = 0;

    while (H[(index + (i * index2)) % SIZE] != 0)
    {
        i++;
    }

    return (index + (i * index2)) % SIZE;
}

int insert(int H[], int key)
{
    int index = hash(key);

    if (H[index] != 0)
    {
        index = doubleHashing(H, key);
    }

    H[index] = key;
}

int linearProbeSearch(int H[], int key)
{
    int index = hash(key);

    int i = 0;

    while (H[(index + i) % SIZE] != key)
    {
        i++;
        if (i == SIZE)
        {
            return -1;
        }
    }
    return (index + i) % SIZE;
}

int quadraticProbeSearch(int H[], int key)
{
    int index = hash(key);

    int i = 0;

    while (H[(index + (i * i)) % SIZE] != key)
    {
        i++;
        if (i == SIZE)
        {
            return -1;
        }
    }
    return (index + (i * i)) % SIZE;
}

int doubleHashingSearch(int H[], int key)
{
    int index = hash(key);
    int index2 = hash2(key);
    int i = 0;

    while (H[(index + (i * index2)) % SIZE] != key)
    {
        i++;
        if (i == SIZE)
        {
            return -1;
        }
    }

    return (index + (i * index2)) % SIZE;
}

int main()
{
    int HT[10] = {0};

    insert(HT, 10);
    insert(HT, 20);
    insert(HT, 30);

    printf("%s\n", doubleHashingSearch(HT, 10) != -1 ? "Element found!" : "Element not found!");
    printf("%s\n", doubleHashingSearch(HT, 20) != -1 ? "Element found!" : "Element not found!");
    printf("%s\n", doubleHashingSearch(HT, 30) != -1 ? "Element found!" : "Element not found!");
    printf("%s\n", doubleHashingSearch(HT, 2) != -1 ? "Element found!" : "Element not found!");

    return 0;
}