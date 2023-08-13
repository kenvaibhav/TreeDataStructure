// This is the function to get the height of a tree where null tree = 0 height, 1 node = 1 height

#include"1TreeNode.h"
using namespace std;
int getHeight(TreeNode<int>* root) {
    // Write your code here
    int max = 1;
    int count = 1;
    for(int i = 0; i < root->children.size() ; i++)
    {
        count = 1;
        count = count + getHeight( root -> children[i]);
        if( count > max )
        {
            max = count;
        }
    }
    return max;
}