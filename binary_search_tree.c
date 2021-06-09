#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

TreeNode *insert(TreeNode *TreeNode, int key)
{
    if (TreeNode == NULL)
        return newTreeNode(key);
    if (key < TreeNode->data)
        TreeNode->left = insert(TreeNode->left, key);
    else if (key > TreeNode->data)
        TreeNode->right = insert(TreeNode->right, key);
    return TreeNode;
}

TreeNode *minValueNode(TreeNode *node)
{
    TreeNode *aux = node;
    while (aux->left != NULL)
        aux = aux->left;
    return aux;
}

TreeNode *search(TreeNode *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (root->data < key)
    {
        return search(root->right, key);
    }
    return search(root->left, key);
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return root;

    //searching node
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        //found it!
        //node has 2 children
        if (root->left == NULL)
        {
            TreeNode *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        TreeNode *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    TreeNode *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 15);
    root = insert(root, 7);

    TreeNode *min = minValueNode(root);
    printf("%d", min->data);
    printf("\n");
    preorder(root);
    root = deleteNode(root, 5);
    printf("\n");
    preorder(root);
    return 0;
}