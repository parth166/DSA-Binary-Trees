// print diagonal sum

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

void printDiagonalSumUtil(Node *root , map <int , int> &m , int dist)
{
    if (root == NULL)
        return;

    m[dist] += root->data;

    printDiagonalSumUtil(root->left,m,dist-1);
    printDiagonalSumUtil(root->right,m,dist);
}

void printDiagonalSum(Node *root)
{
    map <int , int> m;
    int dist = 0;
    int level = 0;
    printDiagonalSumUtil(root,m,dist);

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
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    printDiagonalSum(root);
    return 0;
}
