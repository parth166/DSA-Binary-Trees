#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftH = height(root->left);
        int rightH = height(root->right);

        if (leftH > rightH)
            return leftH + 1;
        else
            return rightH + 1;
    }
}

void printGivenLevel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if(level > 1)
    {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}

void print(struct node *root)
{
    int h = height(root);
    for (int i = 1 ; i <= h ; i++)
    {
        printGivenLevel(root,i);
    }
}

struct node* newNode(int data)
{
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    cout << "Level order traversal is :" << endl;
    print(root);

    return 0;
}
