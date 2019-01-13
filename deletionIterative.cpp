// Given a binary tree, delete a node from it by making sure that tree shrinks from the bottom
// (i.e. the deleted node is replaced by bottom most and rightmost node).

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

void deletion(struct node *root, int val)
{
    queue <struct node*> q;
    struct node *keyNode = NULL;
    struct node *temp = root;

    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == val)
            keyNode = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    int x = temp->data;
    keyNode->data = x;
    delete(temp);
}

void inorder(struct node* temp)
{
    if (temp)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

int main()
{
    struct node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    cout << "Inorder traversal before deletion : ";
    inorder(root);

    int key = 11;
    deletion(root, key);

    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);

    return 0;
}
