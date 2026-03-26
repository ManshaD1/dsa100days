#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search in BST (Recursive)
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0; // Not found

    if (root->data == key)
        return 1; // Found

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int n, x, key;
    scanf("%d", &n);

    struct Node* root = NULL;

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Search key
    scanf("%d", &key);

    if (search(root, key))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}