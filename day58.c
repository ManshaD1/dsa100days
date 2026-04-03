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

struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end) return NULL;

    struct TreeNode* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (start == end) return root;

    int inIndex = search(inorder, start, end, root->val);

    root->left = buildTreeHelper(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

struct TreeNode* buildTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, n - 1, &preIndex);
}