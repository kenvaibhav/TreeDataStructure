// This is the .h file which contains TreeNode class for creating tree objects or nodes 
// This file is used in all tree programs
#include<vector>
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector< TreeNode<T>* > children;
    TreeNode(T data){
        this->data = data;
    };
};
