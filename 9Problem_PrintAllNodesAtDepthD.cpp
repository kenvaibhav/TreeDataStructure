// This is the problem where we will find the nodes at depth D
#include<iostream>
#include"1TreeNode.h"
#include<queue>
using namespace std;
// Note: Depth starts from 0. So, root node will have depth=0
void PrintAtDepthK(TreeNode<int>* root, int k) // Here k is the depth 
{
    if( root == NULL) // This is the edge case
    {
        return;
    }
    if(k == 0)
    {
        cout << root -> data << ", ";
        return;
    }
    for(int i = 0; i < root -> children.size(); i++)
    {
        PrintAtDepthK( root -> children[i], k-1);
    }

}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout<<" Enter rootData :"<<endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter no. of childs of "<<front->data<<endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cout << "Enter "<< i << "th child of" << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int k;
    cout << "Enter the depth :" << endl;
    cin >> k;
    PrintAtDepthK(root, k);
}

