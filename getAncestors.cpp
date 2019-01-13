// find all ancestors of a node

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public :
    int data;
    Node *left,*right;
    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};

void getAncestorsUtil(Node *root, int x, bool &flag)
{
    if (root->data == x)
    {
        flag = true;
        return;
    }

    if (flag == false && root->left != NULL)
    {
        getAncestorsUtil(root->left,x,flag);
    }
    if (flag == false && root->right != NULL)
    {
        getAncestorsUtil(root->right,x,flag);
    }
    if (flag == true)
        cout << root->data << " ";
}

void getAncestors(Node *root, int x)
{
    bool flag = false;
    getAncestorsUtil(root,x,flag);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->right->right = new Node(9);

    getAncestors(root,5);
    return 0;
}
