// height of a tree(iterative)

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

int height(struct Node *root)
{
    queue <Node *> q;
    q.push(root);
    int h = 0;
    while(!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            struct Node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        h++;
    }
    return h;
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

    cout << height(root);
    return 0;
}
