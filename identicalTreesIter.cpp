//check if two trees are identical (iterative)

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
    return nn;
}

int isIdentical(struct node *x, struct node *y)
{
    if (x == NULL && y == NULL)
        return 1;
    if (x == NULL || y == NULL)
        return 0;
    else
    {
        stack <node *> stk1;
        stack <node *> stk2;
        stk1.push(x);
        stk2.push(y);
        while (!stk1.empty() && !stk2.empty())
        {
            node *x = stk1.top();
            node *y = stk2.top();
            stk1.pop();
            stk2.pop();
            if (x->data != y->data)
                return 0;
            if (x->left && y->left)
            {
                stk1.push(x->left);
                stk2.push(y->left);
            }
            else if (x->left || y->left)
                return 0;
            if (x->right && y->right)
            {
                stk1.push(x->right);
                stk2.push(y->right);
            }
            else if (x->right || y->right)
                return 0;
        }
        return 1;
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->left->right = newNode(5);

    struct node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->right->left = newNode(4);
    root1->left->right = newNode(5);

    cout << isIdentical(root,root1);
}

