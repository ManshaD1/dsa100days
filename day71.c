#include <stdio.h>

#define SIZE 7

int table[SIZE];

// initialize table
void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    if (table[index] == -1) {
        table[index] = key;
        return;
    }

    // Quadratic probing
    for (int i = 1; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;

        if (table[newIndex] == -1) {
            table[newIndex] = key;
            return;
        }
    }

    printf("Hash Table is full! Cannot insert %d\n", key);
}

int search(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;

        if (table[newIndex] == key)
            return 1;

        if (table[newIndex] == -1)
            return 0;
    }
    return 0;
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d -> %d\n", i, table[i]);
    }
}

int main() {
    init();

    insert(10);
    insert(17);
    insert(24);
    insert(31);

    display();

    if (search(17))
        printf("\n17 Found\n");
    else
        printf("\n17 Not Found\n");

    return 0;
}