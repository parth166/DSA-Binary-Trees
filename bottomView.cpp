//bottom view of a tree

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

void bottomViewUtil(struct Node *root, int dist, int level, map <int, int> &m1 , map <int, int> &m2)
{
    if (root == NULL)
        return;
    if (m1.find(dist) == m1.end() || level > m2[m1[dist]])
    {
        m1[dist] = root->data;
        m2[root->data] = level;
    }

    bottomViewUtil(root->left,dist-1,level+1,m1,m2);
    bottomViewUtil(root->right,dist+1,level+1,m1,m2);
}

void bottomView(struct Node *root)
{
    map <int , int> m1;
    map <int , int> m2;
    bottomViewUtil(root,0,0,m1,m2);

    map <int , int> :: iterator itr;
    for (itr = m1.begin(); itr != m1.end() ; itr++)
    {
        cout << itr->second << " ";
    }
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
               \
                8
    */

    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->right->right = new Node(8);

    bottomView(root);
    return 0;
}
