//recursive deletion of the entire tree because of a single node is not possible

using namespace std;
#include <bits/stdc++.h>

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

void deletion(struct node *root)
{
   if (!root)
        return;
   deletion(root->left);
   deletion(root->right);

   delete(root);
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

    deletion(root);

    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);

    return 0;
}
