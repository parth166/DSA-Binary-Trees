//continous tree

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

struct node *newNode(int data)
{
    struct node *nn = new node;
    nn->data = data;
    nn->left = nn->right = NULL;
}

bool treeContinuous(struct node *root)
{
    bool flag = true;

    queue <struct node *> q;
    q.push(root);
    while (!q.empty() && flag)
    {
        struct node *temp = q.front();
        q.pop();

        if (temp->left)
        {
            if (abs(temp->left->data - temp->data)!= 1)
            {
                flag = false;
            }
        }
        if (temp->right)
        {
            if (abs(temp->right->data - temp->data)!= 1)
            {
                flag = false;
            }
        }
    }

    return flag;
}

int main()
{
    struct node *root = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(4);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(5);
    treeContinuous(root)?  cout << "Yes" : cout << "No";
    return 0;
}
