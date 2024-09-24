Program to Implement Hashing and Collision Resolution Techniques
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Hash table initialization
int hashTable[TABLE_SIZE];

// Initialize all elements of the hash table as -1 (indicating empty)
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Hash function to calculate the index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a value into the hash table using linear probing
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;

    // Linear probing to resolve collisions
    while (hashTable[index] != -1) {
        index = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (index == originalIndex) {
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[index] = key;
}

// Function to search for a value in the hash table
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;

    // Searching with linear probing
    while (hashTable[index] != key) {
        if (hashTable[index] == -1) {
            return -1; // Key not found
        }
        index = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (index == originalIndex) {
            return -1; // Key not found after probing entire table
        }
    }

    return index; // Key found
}

// Function to display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1)
            printf("HashTable[%d] : Empty\n", i);
        else
            printf("HashTable[%d] : %d\n", i, hashTable[i]);
    }
}

int main() {
    initHashTable();

    // Inserting values into the hash table
    insert(23);
    insert(43);
    insert(13);
    insert(27);
    insert(33);

    // Display the hash table
    display();

    // Searching for values
    int key = 27;
    int index = search(key);
    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }

    return 0;
}