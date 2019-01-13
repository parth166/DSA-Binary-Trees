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

int checkSum(struct Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->data;

    if (root->data == (checkSum(root->left) + checkSum(root->right)))
        return root->data;

    return 0;
}

int convert(struct Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->data;

    int left = convert(root->left);
    int right = convert(root->right);

    int old = root->data;
    root->data = left + right;
    return root->data + old;
}

void print(struct Node *root)
{
    if (root == NULL)
        return;
    queue <Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        while (s--)
        {
            Node *cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
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
    */

    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << checkSum(root) << endl;
    print(root);
    int t = convert(root);
    cout << endl;
    print(root);
    cout << "\n" << checkSum(root);

    return 0;
}
