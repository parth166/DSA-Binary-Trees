// iterative inorder using stack

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

void inOrder(struct Node *root)
{
    stack <Node *> stk;
    Node *curr = root;

    while (curr || !stk.empty())
    {
        while (curr)
        {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        stk.pop();
        cout << curr->data << " ";

        curr = curr->right;
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
    */

    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    inOrder(root);
    return 0;
}
