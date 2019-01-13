//iterative postorder traversal of a binary tree

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

void postorder(struct Node *root)
{
    stack <Node *> stk1;
    Node *cur = root;
    stack <Node *> stk2;
    stk1.push(cur);
    while (!stk1.empty())
    {
        cur = stk1.top();
        stk1.pop();
        stk2.push(cur);
        if (cur->left)
            stk1.push(cur->left);
        if (cur->right)
            stk1.push(cur->right);
    }
    while (!stk2.empty())
    {
        cout << stk2.top()->data << " ";
        stk2.pop();
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
    */

    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    postorder(root);
    return 0;
}
