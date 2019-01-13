//cousins of a node are the nodes in the same level of the tree which are not the siblings of the node

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

void findLevel(struct Node *root, int element , int index , int &level)
{
    if (root == NULL || level)
        return;

    if (root->data == element)
        level = index;

    findLevel(root->left,element,index+1,level);
    findLevel(root->right,element,index+1,level);
}

void printLevel(struct Node *root ,int element , int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    if ((root->left && root->left->data !=element) && (root->right && root->right->data != element))
    {
        printLevel(root->left,element,level-1);
        printLevel(root->right,element,level-1);
    }
}

void printCousins(struct Node *root , int element)
{
    int level = 0;
    findLevel(root,element,1,level);

    printLevel(root,element,level);
}

int main()
{

    /* Constructed binary tree is
               1
            /    \
          2        3
        /  \      /  \
      4    5     6     7
     / \  / \   / \   /  \
    8  9 10 11 12 13 14  15
    */

    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->right = new Node(11);
    root->left->right->left = new Node(10);

    printCousins(root,5);
    return 0;
}
