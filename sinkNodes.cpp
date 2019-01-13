// sink nodes to the bottom of the binary tree

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

void sink(Node *root)
{
    if (root == NULL)
        return;

    if (root->left && root->left->data != 0)
    {
        int t = root->data;
        root->data = root->left->data;
        root->left->data = t;

        sink(root->left);
    }
    else if (root->right && root->right->data != 0)
    {
        int t = root->data;
        root->data = root->right->data;
        root->right->data = t;

        sink(root->right);
    }
}

void sinkNodes(Node *root)
{
    if (root == NULL)
        return;

    sinkNodes(root->left);
    sinkNodes(root->right);

    if (root->data == 0)
        sink(root);
}

void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(0);
    root->right->left = new Node(0);
    root->right->left->left = new Node(3);
    root->right->left->right = new Node(4);
    root->right->right = new Node(2);

    cout << "Before sinking " << endl;
    printInorder(root);
    sinkNodes(root);
    cout << "\nAfter sinking" << endl;
    printInorder(root);

    return 0;
}
