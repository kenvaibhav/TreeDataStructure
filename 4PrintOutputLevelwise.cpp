#include<iostream>
#include"1TreeNode.h"
#include<queue>
using namespace std;
// This function will print the tree levelwise

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> Nodes;
    Nodes.push(root);
    while(Nodes.size() != 0)
    {
        TreeNode<int>* front = Nodes.front();
        cout<<front->data<<":";
        Nodes.pop();
        for(int i = 0; i < front->children.size(); i++)
        {
            cout<<front->children[i]->data;
            Nodes.push(front->children[i]);
            if(i+1 != front->children.size())
            {
                cout<<',';
            }

        }
        cout<<endl;
    }
}