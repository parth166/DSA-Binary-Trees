//diameter of a tree

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

int getDiameter(Node *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int leftHeight = getDiameter(root->left,diameter);
    int rightHeight = getDiameter(root->right,diameter);

    int maxDiameter = leftHeight + rightHeight + 1;

    diameter = max(diameter , maxDiameter);

    return (max(leftHeight,rightHeight) + 1);
}

int getDiameter(Node *root)
{
    int diameter = 0;
    getDiameter(root,diameter);

    return diameter;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    int diameter = 0;
    Node *temp = root;
    cout << getDiameter(root);
}
