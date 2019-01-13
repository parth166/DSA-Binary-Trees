//right view of a tree

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

//iterative left view O(n) with auxilary space of o(n)
/*
void rightView(struct Node *root)
{
    queue <Node *> q;
    Node *cur = root;
    q.push(cur);
    while (!q.empty())
    {
        int i = 0;
        int n = q.size();
        while (i < n)
        {
            cur = q.front();
            q.pop();
            if (i==n-1)
                cout << cur->data << " ";
            if (cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
            i++;
        }
    }
}


// recursive left view - nlog(n) solution with auxilary space of O(n);
void rightViewUtil(struct Node *root,int level,map <int , int> &m)
{
    if (root == NULL)
        return;
    if (m.find(level) == m.end())
        m[level] = root->data;

    rightViewUtil(root->right,level+1,m);
    rightViewUtil(root->left,level+1,m);
}

void rightView(struct Node *root)
{
    map <int , int> m;
    int level = 0;

    rightViewUtil(root,1,m);

    map <int,int> :: iterator itr;
    for (itr = m.begin(); itr != m.end() ; itr++)
        cout << itr->second << " ";
}
*/
// most optimised solution with o(n) time and o(h) auxilary space with "h" being the height

void rightViewUtil(struct Node *root, int level , int &lastLevel)
{
    if (!root)
        return;

    if (lastLevel < level)
    {
        cout << root->data << " ";
        lastLevel = level;
    }

    rightViewUtil(root->right,level+1,lastLevel);
    rightViewUtil(root->left,level+1,lastLevel);
}

void rightView(struct Node *root)
{
    if (root == NULL)
        return;
    int lastLevel = 0;
    rightViewUtil(root,1,lastLevel);
}


int main()
{

    /* Constructed binary tree is
            1
           / \
          2   3
         / \
        4   5
           / \
          6   7
    */

    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    rightView(root);
    return 0;
}
