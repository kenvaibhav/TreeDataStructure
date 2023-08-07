#include<iostream>
#include"1TreeNode.h"


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
TreeNode<int>* takeInput()
{
    // 1st step : get the data for the node and create a node
    int rootdata;
    cout<<"Enter root data:"<<endl;
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);

    // 2nd step : take no. of childrens form the user
    int n;
    cout<<"Enter the no. of childrens of "<<rootdata<<endl;
    cin>>n;
    
    // 3rd step : take all the childrens and connect it to the root
    for(int i = 0; i<n ; i++)
    {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    // 4th step : Now return the root 
    return root;
}

int main(){
    // TreeNode<int>* root = new TreeNode<int> (1);
    // TreeNode<int>* Node1 = new TreeNode<int> (2);
    // TreeNode<int>* Node2 = new TreeNode<int> (3);
    // root->children.push_back(Node1);
    // root->children.push_back(Node2);
    // PrintTree(root);
    TreeNode<int>* root = takeInput();
    PrintTree(root);
    return 0;
}