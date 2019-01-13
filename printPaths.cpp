// print all the paths from leaf to root recursively

//approach is to do a pre-order traversal

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left,*right;
    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};

void printPathsUtil(Node *root, vector <int> &v)
{
    if (root == NULL)
        return;

    v.push_back(root->data);

    if (root->left == NULL && root->right == NULL)
    {
        for (int i = v.size()-1 ; i>=0 ; i--)
        {
            cout << v[i];
            if (i != 0)
                cout << " -> ";
        }
        cout << endl;
    }
    printPathsUtil(root->left,v);
    printPathsUtil(root->right,v);

    v.pop_back();
}

void printPaths(Node *root)
{
    vector <int> v;
    printPathsUtil(root,v);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);

    printPaths(root);
}
