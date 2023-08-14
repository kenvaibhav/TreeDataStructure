// IN this problem we will print in pre order and post order traversal
#include<iostream>
#include"1TreeNode.h"
using namespace std;
// This function will print the tree in PostOrder Traversal
void PrintPostOrder(TreeNode<int>* root)
{
    for(int i = 0 ; i < root->children.size(); i++)
    {
        PrintPostOrder(root->children[i]);
    }
    cout << root->data << " ";
}
// This function will print the tree in preOrder traversal 
void PrintPreOrder(TreeNode<int>* root)
{
    cout << root->data << " ";
    for(int i = 0 ; i < root->children.size(); i++)
    {
        PrintPreOrder(root->children[i]);
    }
}