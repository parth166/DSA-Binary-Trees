// to check if a binary tree can bee coverted to another tree by doing any number of swaps of their left and right child

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public :
    int data;
    Node *left,*right;
    Node (int k)
    {
        data = k;
        left = right = NULL;
    }
};

bool check(Node *x, Node *y)
{
    if (x == y)
        return true;
    return (x && y) && (x->data == y->data) && ( (check(x->left,y->left)) && (check(x->right,y->right) ) || (check(x->left,y->right) && check(x->right,y->left)));
}

int main()
{
    Node *root1 = new Node(6);
    root1->left = new Node(3);
    root1->left->left = new Node(1);
    root1->left->right = new Node(7);
    root1->right = new Node(8);
    root1->right->left = new Node(4);
    root1->right->left->left = new Node(7);
    root1->right->left->right = new Node(1);
    root1->right->right = new Node(2);
    root1->right->right->right = new Node(3);

    Node *root2 = new Node(6);
    root2->left = new Node(8);
    root2->left->left = new Node(4);
    root2->left->left->left = new Node(7);
    root2->left->left->right = new Node(1);
    root2->left->right = new Node(2);
    root2->left->right->right = new Node(3);
    root2->right = new Node(3);
    root2->right->left = new Node(7);
    root2->right->right = new Node(1);

    cout << check(root1,root2);
    return 0;
}
