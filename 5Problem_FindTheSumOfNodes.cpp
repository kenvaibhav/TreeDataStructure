// This is the solution of the problem find the sum of nodes SumOfNodes(TreeNode<int>* root); is the
// function used to find the sum of nodes data
#include <iostream>
#include <vector>
#include <queue>
//#include "solution.h"  this file must include when we don't declare TreeNode class here in this prog.
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
int sumOfNodes(TreeNode<int>* root) {
    // Write your code here
    int sum = 0;
    for(int i = 0; i < root->children.size() ; i++)
    {
        sum =  sum + sumOfNodes(root->children[i]) ;

    }
    return sum + root->data;
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
    cout << sumOfNodes(root);
}