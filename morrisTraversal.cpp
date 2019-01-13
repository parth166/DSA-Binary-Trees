//Morris Traversal (inorder without recursion or using stacks)

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

void MorrisTraversal(struct node *root)
{
    struct node *current,*prev;
    current = root;

    if (root == NULL)
        return;

    while (current)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            prev = current->left;
            while (prev->right != NULL && prev->right != current)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = current;
                current = current->left;
            }
            else
            {
                prev->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
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
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    MorrisTraversal(root);

    return 0;
}
