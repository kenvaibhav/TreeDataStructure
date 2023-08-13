#include"1TreeNode.h"
using namespace std;

// This function will give the no of nodes present in the whole tree.
int NoOfNodes(TreeNode<int>* root) {
    // Write your code here
    int sum = 0;
    for(int i = 0; i < root->children.size() ; i++)
    {
        sum =  sum + NoOfNodes(root->children[i]) ;

    }
    return sum + 1;
}