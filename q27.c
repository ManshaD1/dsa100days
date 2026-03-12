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

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    while (len1 > len2) { head1 = head1->next; len1--; }
    while (len2 > len1) { head2 = head2->next; len2--; }
    while (head1 && head2) {
        if (head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head) { temp = head; head = head->next; free(temp); }
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { scanf("%d", &value); head1 = appendNode(head1, value); }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) { scanf("%d", &value); head2 = appendNode(head2, value); }
    struct Node* intersection = findIntersection(head1, head2);
    if (intersection) printf("%d\n", intersection->data);
    else printf("No Intersection\n");
    freeList(head1);
    freeList(head2);
    return 0;
}