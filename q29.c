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

int getLength(struct Node* head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    int len = getLength(head);
    k %= len;
    if (k == 0) return head;
    struct Node* temp = head;
    for (int i = 1; i < len - k; i++) temp = temp->next;
    struct Node* newHead = temp->next;
    temp->next = NULL;
    struct Node* tail = newHead;
    while (tail->next) tail = tail->next;
    tail->next = head;
    return newHead;
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
    int n, value, k;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &value); head = appendNode(head, value); }
    scanf("%d", &k);
    head = rotateRight(head, k);
    printList(head);
    freeList(head);
    return 0;
}