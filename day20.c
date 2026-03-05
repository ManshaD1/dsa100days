#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 100003

typedef struct Node {
    long long sum;
    int count;
    struct Node* next;
} Node;

int hash(long long x) {
    if(x < 0) x = -x;
    return x % HASH_SIZE;
}

void insert(Node* hash_table[], long long sum) {
    int h = hash(sum);
    Node* curr = hash_table[h];
    while(curr) {
        if(curr->sum == sum) {
            curr->count++;
            return;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->count = 1;
    newNode->next = hash_table[h];
    hash_table[h] = newNode;
}

int get_count(Node* hash_table[], long long sum) {
    int h = hash(sum);
    Node* curr = hash_table[h];
    while(curr) {
        if(curr->sum == sum) return curr->count;
        curr = curr->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* hash_table[HASH_SIZE] = {0};
    long long prefix_sum = 0;
    long long count = 0;

    insert(hash_table, 0);

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        count += get_count(hash_table, prefix_sum);
        insert(hash_table, prefix_sum);
    }

    printf("%lld\n", count);
    return 0;
}