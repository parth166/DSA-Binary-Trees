//expression tree
// Generating a tree from the postfix expression

#include <bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    struct node *left,*right;
};

struct node *newNode(char data)
{
    struct node *nn = new node;
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '%')
        return true;
    return false;
}

struct node *createTree(char array[])
{
    stack <struct node *> stk;
    struct node *t,*t1,*t2;
    for (int i = 0 ; i < strlen(array) ; i++)
    {
        if (!isOperator(array[i]))
        {
            t = newNode(array[i]);
            stk.push(t);
        }
        else
        {
            t = newNode(array[i]);
            t1 = stk.top();
            stk.pop();
            t2 = stk.top();
            stk.pop();
            t->left = t2;
            t->right = t1;
            stk.push(t);
        }
    }
    t = stk.top();
    stk.pop();
    return t;
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

int main()
{
    char postfix[] = "ab+ef*g*-";
    node *r = createTree(postfix);
    printf("infix expression is \n");
    inorder(r);
    return 0;
}
