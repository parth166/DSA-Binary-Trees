//Bottom up traversal for a perfect binary tree
//for the question - https://www.techiedelight.com/print-nodes-binary-tree-specific-order/

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

void bottomUp(struct Node *root)
{
    queue <Node *> q;
    stack <Node *> s;
    q.push(root);
    if (root->left)
    {
        q.push(root->left);
        q.push(root->right);
    }
    q.pop();
    s.push(root);
    while (!q.empty())
    {
        Node *a = q.front();
        q.pop();
        Node *b = q.front();
        q.pop();
        s.push(b);
        s.push(a);
        if (a->right && b->left)
        {
            q.push(a->right);
            q.push(b->left);
        }
        if (a->left && b->right)
        {
            q.push(a->left);
            q.push(b->right);
        }
    }
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}

int main()
{

    /* Constructed binary tree is
               1
            /    \
          2        3
        /  \      /  \
      4    5     6     7
     / \  / \   / \   /  \
    8  9 10 11 12 13 14  15
    */

    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->right = new Node(11);
    root->left->right->left = new Node(10);

    bottomUp(root);
    return 0;
}
