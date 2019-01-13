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

void spiralOrder(struct Node *root)
{
    queue <Node *> q;
    Node *cur = root;
    int s,n = 1;
    q.push(cur);

    while (!q.empty())
    {
        s = q.size();
        if (n%2 == 1)
        {
            while (s--)
            {
                cur = q.front();
                cout << cur->data << " ";
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        else
        {
            while (s--)
            {
                cur = q.front();
                cout << cur->data << " ";
                q.pop();
                if (cur->right)
                    q.push(cur->right);
                if (cur->left)
                    q.push(cur->left);
            }
        }
        n++;
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

    spiralOrder(root);
    return 0;
}
