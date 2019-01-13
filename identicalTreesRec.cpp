//check if two trees are identical (recursive)

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
    if (x->data != y->data)
        return 0;
    return isIdentical(x->left,y->left) && isIdentical(x->right,y->right);
}

int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->right->left  = newNode(4);
    root->left->right = newNode(5);

    struct node *root1 = newNode(1);
    root1->left        = newNode(2);
    root1->right       = newNode(3);
    root1->right->left  = newNode(4);
    root1->left->right = newNode(5);

    cout << isIdentical(root,root1);
}
