// print end nodes of a level

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


void inorder(Node *root, vector <Node *> &v)
{
    if (!root)
        return;
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}

Node* convert(Node *root)
{
    vector <Node *> v;
    inorder(root,v);

    Node *lnode = new Node(v[0]->data);
    Node *cur = lnode;

    for (int i = 1 ; i < v.size() ; i++)
    {
        Node *nn = new Node(v[i]->data);
        cur->right = nn;
        nn->left = cur;
        cur = nn;
    }
    return lnode;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *lnode = convert(root);
    while (lnode != NULL)
    {
        cout << lnode->data << " ";
        lnode = lnode->right;
    }
}
