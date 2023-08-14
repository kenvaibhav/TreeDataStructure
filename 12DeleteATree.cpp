#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector< TreeNode<T>* > children;
    TreeNode(T data){
        this->data = data;
    }
    // Below given is destructor which is called when the program will be delted or when we delete
    // keyword or when anyone tries to delete the object created
    ~TreeNode()
    {
        for(int i = 0; i<children.size(); i++)
        {
            delete children[i];
        }
    }
};

// Another way to delete the tree is by creating the recursive function
void deletingTheTree(TreeNode<int>* root)
{
    // if we want to delete the tree first delete the children and then root 
    // delete in postOrder way
    for( int i = 0; i < root->children.size(); i++)
    {
        deletingTheTree(root->children[i]);
    }
    delete root;
}
