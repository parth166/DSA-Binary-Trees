//Given a binary tree and a key, insert the key into the binary tree at first position available in level order.

//approach : we do level order traversal and then find the first position where the key can be inserted

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

struct node *newNode(int);

void insert(struct node *root,int val)
{
    queue <struct node *>q;
    q.push(root);

    while (!q.empty())
    {
        struct node *temp = q.front();
        q.pop();

        if (!temp->left)
        {
            temp->left = newNode(val);
            break;
        }
        else
            q.push(temp->left);

        if (!temp->right)
        {
            temp->right = newNode(val);
            break;
        }
        else
            q.push(temp->right);
    }
}

void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

struct node *newNode(int data)
{
    struct node *nn = new node;
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

int main()
{
    struct node *root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    cout << "Before insertion : " << endl;
    inorder(root);
    cout << "\nAfter insertion : " << endl;
    insert(root,12);
    inorder(root);
    return 0;
}
