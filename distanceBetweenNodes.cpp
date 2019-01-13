//distance between two nodes

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

Node* findLCA(Node *root, Node *X, Node *Y)
{
    if (root == NULL)
        return NULL;

    if (root->data == X->data || root->data == Y->data)
        return root;

    Node *left = findLCA(root->left,X,Y);
    Node *right = findLCA(root->right,X,Y);

    if (left && right)
        return root;

    if (left)
        return left;

    if (right)
        return right;
}

bool isPresent(Node *root, Node *temp)
{
    if (root == NULL)
        return false;
    if (root->data == temp->data)
        return true;
    return isPresent(root->left,temp) || isPresent(root->right,temp);
}

int findLevel(Node *root, Node *t, int level)
{
    if (root == NULL)
        return INT_MIN;

    if (root->data == t->data)
        return level;

    int left = findLevel(root->left,t,level + 1);

    if (left != INT_MIN)
        return left;

    return findLevel(root->right,t,level + 1);
}

int getDistance(Node *root, int x, int y)
{
    Node *lca = NULL;
    Node *X = new Node(x);
    Node *Y = new Node(y);

    if (isPresent(root,X) && isPresent(root,Y))
        lca = findLCA(root,X,Y);
    else
        return -1;

    return findLevel(lca,X,0) + findLevel(lca,Y,0);
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

    cout << getDistance(root,7,4);
}
