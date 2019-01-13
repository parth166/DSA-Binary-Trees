// maximum sum from root to leaf in a binary tree

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

int maxSumUtil(Node *root)
{
    if (root == NULL)
        return 0;
    int left = maxSumUtil(root->left);
    int right = maxSumUtil(root->right);

    return max(left,right)+root->data;
}

int maxSum(Node *root)
{
    int sum = 0;
    int temp = root->data;
    return maxSumUtil(root);
}

bool maxSumPath(Node *root, int sum , stack <int> &stk)
{
    if (sum == 0)
        return true;

    if (root == NULL)
        return false;

    bool left = maxSumPath(root->left,sum - root->data,stk);
    bool right = maxSumPath(root->right,sum - root->data,stk);

    if (left || right)
        stk.push(root->data);
    return left || right;
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(8);
    root->left->right = new Node(4);
    root->left->right->left = new Node(10);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(9);
    root->right->right->right = new Node(5);

    int sum = maxSum(root);
    cout << "Maximum sum is : " << sum << endl;
    cout << "Maximum sum path is : ";
    stack <int> stk;
    maxSumPath(root,sum,stk);
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}
