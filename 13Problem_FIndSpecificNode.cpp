#include<iostream>
#include"1TreeNode.h"
using namespace std;

// this function will return true if the node x is present in our tree and false if not present
bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
    if(root->data == x)
    {
        return true;
    }
    for(int i = 0; i < root->children.size() ; i++)
    {
        bool present = isPresent( root->children[i] , x );
        if(present == true)
        {
            return true;
        }
    }
    return false;
}