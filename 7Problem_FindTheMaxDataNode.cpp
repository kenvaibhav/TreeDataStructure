#include"1TreeNode.h"
using namespace std;
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int>* maxData = root;
    for(int i = 0; i < root->children.size() ; i++)
    {
        TreeNode<int>* Data = maxDataNode(root->children[i]);
        if( Data->data > maxData->data)
        {
            maxData = Data;
        }
    }
    return maxData ;
}