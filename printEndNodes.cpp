// print end nodes of a level

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

void printCornerNode(Node *root)
{
    queue <Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        int i = 0;
        while (i < n)
        {
            Node *cur = q.front();
            q.pop();
            if (i == 0 || i == n-1)
            {
                cout << cur->data << " ";
            }
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            i++;
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(4);
    root->right->right = new Node(2);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(7);
    root->right->right->right = new Node(3);

    printCornerNode(root);
}
