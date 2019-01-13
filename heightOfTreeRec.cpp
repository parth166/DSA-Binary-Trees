// height of a tree(recursive)

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
    if(root == NULL)
        return 0;
    return max(height(root->left),height(root->right)) + 1;

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
