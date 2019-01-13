// sum tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left,*right;
    Node (int k)
    {
        this->data = k;
        left = right = NULL;
    }
};

int convert(struct Node *root)
{
    if (root == NULL)
        return 0;

    int left = convert(root->left);
    int right = convert(root->right);

    int old = root->data;
    root->data = left + right;
    return root->data + old;
}

int main()
{

    /* Constructed binary tree is
               1
            /    \
          2        3
        /  \      /  \
      4    5     6     7
    */

    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "The new value of root is : " << convert(root);
    return 0;
}
