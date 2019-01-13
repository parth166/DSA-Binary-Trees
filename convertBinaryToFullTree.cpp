// convert binary tree to full tree

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

Node *truncate(Node *root)
{
    if (root == NULL)
        return NULL;

    root->left = truncate(root->left);
    root->right = truncate(root->right);

    if ((root->left && root->right) || (root->left == NULL && root->right == NULL))
        return root;

    Node *child = (root->left) ? root->left : root->right;
    delete root;
    return child;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(5);
    root->right->left = new Node(4);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);

    cout << "Before truncating " << endl;
    preorder(root);
    truncate(root);
    cout << "\nAfter truncating " << endl;
    preorder(root);

    return 0;
}
