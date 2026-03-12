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

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    while (l1 && l2) {
        struct Node* temp;
        if (l1->data <= l2->data) {
            temp = l1;
            l1 = l1->next;
        } else {
            temp = l2;
            l2 = l2->next;
        }
        temp->next = NULL;
        if (!head) head = tail = temp;
        else { tail->next = temp; tail = temp; }
    }
    if (l1) tail->next = l1;
    if (l2) tail->next = l2;
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head) { temp = head; head = head->next; free(temp); }
}

int main() {
    int n, m, value;
    struct Node *l1 = NULL, *l2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &value); l1 = appendNode(l1, value); }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) { scanf("%d", &value); l2 = appendNode(l2, value); }
    struct Node* merged = mergeLists(l1, l2);
    printList(merged);
    freeList(merged);
    return 0;
}