#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node*left,*right;
};

struct node* newNode(int data)
{
    struct node *nn = new node;
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

bool isSymmetricAns(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
        return false;
    if (a->data != b->data)
        return false;
    return isSymmetricAns(a->left,b->right) && isSymmetricAns(a->right,b->left);
}

bool isSymmetric(struct node *root)
{
    if (!root)
        return true;
    return isSymmetricAns(root->left,root->right);
}

int main()
{
    // Let us construct the Tree shown in the above figure
    node *root        = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(4);
    root->right->left  = newNode(4);
    root->right->right = newNode(3);

    cout << isSymmetric(root);
    return 0;
}
