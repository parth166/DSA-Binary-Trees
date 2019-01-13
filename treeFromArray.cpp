// Binary tree from an array

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

struct node *newNode(int data)
{
    struct node *nn = new node;
    nn->data = data;
    nn->left = nn->right = NULL;
}

void inorder(struct node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// BFS is used to create the tree
// the complexity of the algorithm is o(n) with auxilarySpace o(n^2);

struct node *createTree(int *parent,int n)
{
    vector < vector <int> > v(n);
    int root;
    for (int i = 0 ; i < n ; i++)
    {
        int temp = parent[i];
        if (temp != -1)
        {
            v[temp].push_back(i);
        }
        else
            root = i;
    }

    struct node *nn = newNode(root);

    queue <struct node *> q;
    q.push(nn);
    while (!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
        int d = temp->data;
        for (int i = 0; i < v[d].size() ; i++)
        {
            if (!temp->left)
            {
                temp->left = newNode(v[d][i]);
                q.push(temp->left);
            }
            else
            {
                temp->right = newNode(v[d][i]);
                q.push(temp->right);
            }
        }
    }
    return nn;
}

int main()
{
    int parent[] = {-1,0,0,1,1,3,5};
    int n = sizeof(parent)/sizeof(parent[0]);
    node *root = createTree(parent,n);
    cout << "Inorder traversal of tree is : ";
    inorder(root);
    cout << "\n";
}
