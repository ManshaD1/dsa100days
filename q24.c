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

struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp) {
        if (temp->data == key) {
            if (prev) prev->next = temp->next;
            else head = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void printList(struct Node* head) {
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
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
    head = deleteFirstOccurrence(head, key);
    printList(head);
    freeList(head);
    return 0;
}