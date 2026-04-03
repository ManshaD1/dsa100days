#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mirrorTree(struct TreeNode* root) {
    if (root == NULL) return NULL;

    struct TreeNode* left = mirrorTree(root->left);
    struct TreeNode* right = mirrorTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}