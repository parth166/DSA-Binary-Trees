//spiral order traversal of a binary tree

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

void reverseLevelOrder(struct Node *root)
{
    queue <Node *> q;
    stack <Node *> s;
    Node *cur = root;
    q.push(cur);

    while (!q.empty())
    {
        Node *cur = q.front();
        s.push(cur);
        q.pop();
        if (cur->right)
            q.push(cur->right);
        if (cur->left)
            q.push(cur->left);
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

    reverseLevelOrder(root);
    return 0;
}
