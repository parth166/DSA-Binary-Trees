// truncate if sum is less than k

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

Node *truncate(Node *root, int val , int k)
{
    if (root == NULL)
        return NULL;

    root->left = truncate(root->left,val + root->data, k);
    root->right = truncate(root->right,val + root->data, k);

    if (root->left == NULL && root->right == NULL && (val + root->data < 20))
    {
        delete root;
        return NULL;
    }

    return root;
}

void truncate(Node *root,int k)
{
    int val = 0;
    root = truncate(root,val,k);
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
    Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(4);
    root->right->right = new Node(2);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(7);
    root->right->right->right = new Node(3);

    cout << "Before truncating " << endl;
    preorder(root);
    truncate(root,20);
    cout << "\nAfter truncating " << endl;
    preorder(root);

    return 0;
}
