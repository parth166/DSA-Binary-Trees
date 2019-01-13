// check height balanced or not

#include <bits/stdc++.h>
using namespace std;

class Node
{
public :
    int data;
    Node *left,*right;
    Node (int k)
    {
        data = k;
        left = right = NULL;
    }
};

bool checkBalance(Node *root,int depthLeft, int depthRight)
{
    if (root == NULL)
        return false;

    bool left = checkBalance(root->left,depthLeft+1,depthRight);
    bool right = checkBalance(root->right,depthLeft,depthRight+1);
}

void checkBalance(Node *root)
{
    cout << checkBalance(root,0,0);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    checkBalance(root);
    return 0;
}
