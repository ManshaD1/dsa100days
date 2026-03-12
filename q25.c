#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* appendNode(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    while (head) {
        if (head->data == key) count++;
        head = head->next;
    }
    return count;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head) { temp = head; head = head->next; free(temp); }
}

int main() {
    int n, value, key;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &value); head = appendNode(head, value); }
    scanf("%d", &key);
    printf("%d\n", countOccurrences(head, key));
    freeList(head);
    return 0;
}