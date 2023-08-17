#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int CountNodes(BinaryTreeNode<int>* root)
{
    //Base Case
    if( root == NULL)
    {
        return 0;
    }
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}
void printLevelWise(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        if (frontNode == NULL)
        {
            cout << "\n";
            if (!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << ":";
            cout << "L:";
            if (frontNode->left)
            {
                pendingNodes.push(frontNode->left);
                cout << frontNode->left->data << ",";
            }
            else
            {
                cout << -1 << ",";
            }
            cout << "R:";
            if (frontNode->right)
            {
                pendingNodes.push(frontNode->right);
                cout << frontNode->right->data << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
// input as 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printLevelWise(root);
    int numOfNodes = CountNodes(root);
    cout << " NO of NOdes in Above binary tree are " << numOfNodes; 
    delete root;
}