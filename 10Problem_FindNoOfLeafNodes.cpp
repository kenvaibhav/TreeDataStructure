#include<iostream>
#include"1TreeNode.h"
using namespace std;

// This function will print the no of leaf nodes using the Children size count
int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    int leafNodes = 0;
     if( root -> children.size() == 0 )
    {
        return 1;
    }
    for( int i = 0; i < root->children.size() ; i++)
    {
        leafNodes += getLeafNodeCount(root -> children[i]);
    }
   return leafNodes;
}