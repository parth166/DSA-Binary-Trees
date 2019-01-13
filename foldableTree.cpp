// to check if the given tree is foldable

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

int isFoldableAns(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
        return 1;
    if (a == NULL || b == NULL)
        return 0;
    return isFoldableAns(a->left,b->right) && isFoldableAns(a->right,b->left);
}

int isFoldable(struct node *root)
{
    // we will recursively check whether the tree is foldable or not
    if (!root)
        return 1;
    return isFoldableAns(root->left,root->right);
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

int main()
{
    /* The constructed binary tree is
         1
       /   \
      2     3
      \    /
       4  5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->right->left  = newNode(4);
  root->left->right = newNode(5);

  if(isFoldable(root) == 1)
      cout << "yes";
  else
      cout << "no";

    return 0;
}
