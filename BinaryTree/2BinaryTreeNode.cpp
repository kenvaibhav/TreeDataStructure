#include<iostream>
#include"1BinaryTree.h"
using namespace std;

void PrintBinaryTree(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    if(root->left != NULL)
    {
        cout << "L " << root->left->data << ", ";
    }
    if(root->right != NULL)
    {
        cout << "R " << root->right->data ;
    }
    cout << endl;
    PrintBinaryTree(root->left);
    PrintBinaryTree(root->right);
}
// this below given binary fuction is the function which will take first leftchild
// and then rightchild
BinaryTreeNode<int>* takeInputBinaryTree()
{
    int rootData;
    cout << "Enter rootData :";
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInputBinaryTree();
    BinaryTreeNode<int>* rightChild = takeInputBinaryTree();
    root->left = leftChild;
    root->right = rightChild;
}


int main()
{
    // Creating Binary Tree Manually
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* Node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* Node2 = new BinaryTreeNode<int>(3);
    // root->left = Node1;
    // root->right = Node2;
    // PrintBinaryTree(root);
    BinaryTreeNode<int>* root = takeInputBinaryTree();
    PrintBinaryTree(root);
    return 0;
}