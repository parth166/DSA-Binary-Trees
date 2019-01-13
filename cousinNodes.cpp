// to check if the two nodes are cousins of each other

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

struct node *newNode(int data)
{
    struct node *nn = new node;
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

bool checkCousins(struct node *root, int a , int b)
{
    queue <node *> q;
    int level = 0;

    node *parent1 = NULL;
    node *parent2 = NULL;
    int levelParent1,levelParent2;

    q.push(root);
    if (root->data == a)
    {
        parent1 = root;
        levelParent1 = 0;
    }
    if (root->data == b)
    {
        parent2 = root;
        levelParent2 = 0;
    }
    while (!q.empty())
    {
        int s = q.size();
        level++;
        while (s--)
        {
            node *cur = q.front();
            q.pop();
            if (cur->left)
            {
                q.push(cur->left);
                if (cur->left->data == a)
                {
                    parent1 = cur;
                    levelParent1 = level;
                }
                if (cur->left->data == b)
                {
                    parent2 = cur;
                    levelParent2 = level;
                }
            }
            if (cur->right)
            {
                q.push(cur->right);
                if (cur->right->data == a)
                {
                    parent1 = cur;
                    levelParent1 = level;
                }
                if (cur->right->data == b)
                {
                    parent2 = cur;
                    levelParent2 = level;
                }
            }
        }
    }
    if (parent1 != parent2 && levelParent1 == levelParent2)
        return true;
    return false;
}

int main()
{

    /* Constructed binary tree is
              1
            /   \
          2       3
         / \     /  \
        4   5   6    7
    */

    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << checkCousins(root,1,3);
    return 0;
}
