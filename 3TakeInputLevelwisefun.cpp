#include<iostream>
#include"1TreeNode.h"
#include<queue>
using namespace std;

TreeNode<int>* TakeInputLevelwise()
{
    // 1st step: firstly we will create a root node by taking input from the user
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    // 2nd step : now we will create a queue for taking levelwise input
    queue< TreeNode<int>* > pendingNodes;

    // 3rd step : now as we take input from the user we have to insert that node into queue and when the childrens of any node wil
    // completed then we will remove that node which is present on the fromt of queue

    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        // now we will access the first element of the queue, pop it and then ask user for its childrens and if there are any children
        // then we will take them and push into the queue
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the no. of childerens of " << front-> data << endl;
        int numChild;
        cin >> numChild;
        for(int i = 0 ; i < numChild ; i++)
        {
            int childData;
            cout << "Enter the " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }

    } 
    return root;
}

void PrintTree(TreeNode<int>* root){
    cout<<root->data<<":";
    for(int i=0; i < root->children.size(); i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0 ; i < root->children.size() ; i++){
        PrintTree(root->children[i]);
    }
}

int main()
{
    TreeNode<int>* root = TakeInputLevelwise();
    PrintTree(root);
}