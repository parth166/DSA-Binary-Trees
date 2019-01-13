//Lowest common ancestor of two nodes with time complexity of O(n) and space complexity of O(n)

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

void preOrder(Node *root, vector <Node *> &v1, vector <Node *> &v2, int x, int y, bool &flag1, bool &flag2)
{
    if (root == NULL)
        return;
    if (flag1 == false)
        v1.push_back(root);
    if (flag2 == false)
        v2.push_back(root);
    if (root->data == x)
        flag1 = true;
    if (root->data == y)
        flag2 = true;

    preOrder(root->left,v1,v2,x,y,flag1,flag2);
    preOrder(root->right,v1,v2,x,y,flag1,flag2);

    if (flag1 == false)
        v1.pop_back();
    if (flag2 == false)
        v2.pop_back();
}

int getLCA(Node *root, int x, int y)
{
    vector <Node *> v1;
    vector <Node *> v2;
    int ans;
    bool flag1 = false;
    bool flag2 = false;
    preOrder(root,v1,v2,x,y,flag1,flag2);
    int i;
    for (i = 0 ; i < v1.size() ; i++)
    {
        if (v1[i] != v2[i])
            break;
    }
    return v1[i-1]->data;
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

    cout << getLCA(root,7,5);
}
