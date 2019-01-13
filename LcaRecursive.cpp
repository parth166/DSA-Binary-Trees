//Lowest common ancestor of two nodes with time complexity of O(n) and space complexity of O(h)

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

bool findLCA(Node *root, int &LCA, Node *X, Node *Y)
{
    if (root == NULL)
        return false;
    if (root->data == X->data || root->data == Y->data)
    {
        LCA = root->data;
        return true;
    }
    bool left = findLCA(root->left,LCA,X,Y);
    bool right = findLCA(root->right,LCA,X,Y);

    if (left && right)
        LCA = root->data;

    return left || right;
}

bool isPresent(Node *root, Node *temp)
{
    if (root == NULL)
        return false;
    if (root->data == temp->data)
        return true;
    return isPresent(root->left,temp) || isPresent(root->right,temp);
}

void getLCA(Node *root, int x, int y)
{
    int LCA = -1;
    Node *X = new Node(x);
    Node *Y = new Node(y);

    if (isPresent(root,Y) && isPresent(root,X))
    {
        bool a = findLCA(root,LCA,X,Y);
    }

    if (LCA != -1)
        cout << LCA << " ";
    else
        cout << "Elements do not exist";
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

    getLCA(root,7,5);
}
