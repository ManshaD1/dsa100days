#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* buildTreeHelper(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end) return NULL;

    struct TreeNode* root = createNode(postorder[*postIndex]);
    (*postIndex)--;

    if (start == end) return root;

    int inIndex = search(inorder, start, end, root->val);

    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = buildTreeHelper(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

struct TreeNode* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1;
    return buildTreeHelper(inorder, postorder, 0, n - 1, &postIndex);
}