//to check is a binary tree is complete or not
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

bool checkComplete1(struct Node *root)
{
    queue <Node *> q;
    q.push(root);
    bool flag = false;
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        if (flag && (cur->left || cur->right))
            return false;

        if (cur->left == NULL && cur->right)
            return false;

        if (cur->left)
            q.push(cur->left);
        else
            flag = true;

        if (cur->right)
            q.push(cur->right);
        else
            flag = true;
    }
    return true;
}

int findCount(struct Node *root)
{
    int n = 0;
    queue <Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        n++;
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
    return n;
}

void inorder(struct Node *root, vector <bool> &v , int i)
{
    if (!root)
        return;
    inorder(root->left,v,2*i+1);
    v[i] = true;
    inorder(root->right,v,2*i+2);
}

bool checkComplete2(struct Node *root,int n)
{
    vector <bool> v(n,false);
    int i;
    inorder(root,v,0);

    for (int i = 0 ; i < n ; i++)
        if (!v[i])
            return false;
    return true;
}

//most optimised approach with time complexity of O(n) and space as O(height)
bool checkComplete3(struct Node *root, int i , int n)
{
    if (!root)
        return true;

    if ((root->left && 2*i+1 >= n) || checkComplete3(root->left,2*i+1,n))
        return false;
    if ((root->right && 2*i+2 >= n) || checkComplete3(root->right,2*i+2,n))
        return false;

    return true;
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

    cout << checkComplete1(root) << endl;
    int n = findCount(root);
    cout << checkComplete2(root,n) << endl;
    cout << checkComplete3(root,0,n);
    return 0;
}
