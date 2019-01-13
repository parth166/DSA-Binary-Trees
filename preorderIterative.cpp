//iterative preorder traversal of a binary tree

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

void preorder(struct Node *root)
{
    /*approach 1
    stack <Node *> stk1;
    stack <Node *> stk2;
    stk1.push(root);
    while (!stk1.empty())
    {
        struct Node *nn = stk1.top();
        if (nn->right)
        {
            if (stk2.empty())
            {
                stk1.push(nn->right);
                continue;
            }
            else if (stk2.top()!=nn->right && stk2.top()!=nn->left)
            {
                stk1.push(nn->right);
                continue;
            }
        }
        if (nn->left)
        {
            if (stk2.empty())
            {
                stk1.push(nn->left);
                continue;
            }
            else if (stk2.top()!=nn->left)
            {
                stk1.push(nn->left);
                continue;
            }
        }
        stk2.push(nn);
        stk1.pop();
    }
    while (!stk2.empty())
    {
        struct Node *n = stk2.top();
        cout << n->data << " ";
        stk2.pop();
    }*/

    // approach 2
    /*
    stack <Node *> stk;
    if (root == NULL)
        return;
    stk.push(root);

    while (!stk.empty())
    {
        Node *curr = stk.top();
        stk.pop();

        if (curr->right)
            stk.push(curr->right);
        if (curr->left)
            stk.push(curr->left);

        cout << curr->data << " ";
    }*/

    //approach 3 - optimised version of approach 2
    stack <Node *> stk;
    Node *cur = root;
    stk.push(cur);
    while (!stk.empty())
    {
        if (cur)
        {
            cout << cur->data << " ";
            if (cur->right)
                stk.push(cur->right);
            cur = cur->left;
        }
        else
        {
            cur = stk.top();
            stk.pop();
        }
    }
}

int main()
{

    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
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

    preorder(root);
    return 0;
}
