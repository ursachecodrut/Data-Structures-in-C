#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

void initTree(TreeNode **root, int data);

TreeNode *newTreeNode(int data);

int isTreeEmpty(TreeNode *root);

int isInterior(TreeNode *node);

int isLeaf(TreeNode *node);

void preorder(TreeNode *root);

void inorder(TreeNode *root);

void postorder(TreeNode *root);

int height(TreeNode *root);

void printLevel(TreeNode *root, int level);

TreeNode *createTree();

void freeTree(TreeNode **root);

#endif /* BINARY_TREE_H */