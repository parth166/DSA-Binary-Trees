#include <bits/stdc++.h>
using namespace std;

struct Node
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

void inorder(Node *root ,vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

void postorder(Node *root ,vector <int> &v)
{
    if (root != NULL)
    {
        postorder(root->left,v);
        postorder(root->right,v);
        v.push_back(root->data);
    }
}

bool checkSubtree(Node *root , Node *nroot)
{
    if (root == nroot)
        return true;

    if (root == NULL)
        return false;

    vector <int> v1,v2;
    inorder(root,v1);
    inorder(nroot,v2);

    if (search(v1.begin(), v1.end(), v2.begin(), v2.end()) == v1.end())
        return false;

    v1.erase(v1.begin(), v1.end());
    v2.erase(v2.begin(), v2.end());

    postorder(root,v1);
    postorder(nroot,v2);

    if (search(v1.begin(), v1.end(), v2.begin(), v2.end()) == v1.end())
        return false;

    return true;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    struct Node *nroot = new Node(3);
    nroot->left = new Node(6);
    nroot->right = new Node(7);

    cout << checkSubtree(root,nroot);
}
