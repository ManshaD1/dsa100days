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

struct Node* makeCircular(struct Node* head) {
    if (!head) return NULL;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = head;
    return head;
}

void printCircularList(struct Node* head) {
    if (!head) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void freeCircularList(struct Node* head) {
    if (!head) return;
    struct Node* temp = head->next;
    head->next = NULL;
    struct Node* nextNode;
    while (temp) { nextNode = temp->next; free(temp); temp = nextNode; }
    free(head);
}

int main() {
    int n, value;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &value); head = appendNode(head, value); }
    head = makeCircular(head);
    printCircularList(head);
    freeCircularList(head);
    return 0;
}