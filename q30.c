#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node* appendNode(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void printPolynomial(struct Node* head) {
    while (head) {
        printf("%d", head->coeff);
        if (head->exp > 0) printf("x");
        if (head->exp > 1) printf("^%d", head->exp);
        head = head->next;
        if (head) printf(" + ");
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head) { temp = head; head = head->next; free(temp); }
}

int main() {
    int n, coeff, exp;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = appendNode(head, coeff, exp);
    }
    printPolynomial(head);
    freeList(head);
    return 0;
}