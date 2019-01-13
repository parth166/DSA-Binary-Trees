// vertical sum in a binary tree

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

void printVerticalSumUtil(Node *root , map <int , int> &m , int dist)
{
    if (root == NULL)
        return;

    m[dist] += root->data;

    printVerticalSumUtil(root->left,m,dist-1);
    printVerticalSumUtil(root->right,m,dist+1);
}

void printVerticalSum(Node *root)
{
    map <int , int> m;
    int dist = 0;
    printVerticalSumUtil(root,m,dist);

    map <int , int> :: iterator itr;

    for (itr = m.begin(); itr != m.end() ; itr++)
    {
        cout << itr->second << " ";
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    printVerticalSum(root);
    return 0;
}
