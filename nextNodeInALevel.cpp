//top view of a tree

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


void nextNode(struct Node *root,int val)
{
    queue <Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        if (cur->data == val)
        {
            cout << q.front()->data;
            break;
        }
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
}

int main()
{

    /* Constructed binary tree is
            1
           / \
          2   3
         / \
        4   5
           / \
          6   7
               \
                8
    */

    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->right->right = new Node(8);

    nextNode(root,6);
    return 0;
}
