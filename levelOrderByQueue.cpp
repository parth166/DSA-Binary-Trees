#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node ** createQueue(int *front1, int *rear)
{
    struct node **q = (struct node **)malloc(sizeof(struct node *)*500);
    *front1 = *rear = 0;
    return q;
}

void enqueue(struct node **q, int *rear, struct node *root)
{
    q[*rear] = root;
    (*rear)++;
}

struct node *dequeue(struct node **q, int *front1)
{
    (*front1)++;
    return q[*front1 - 1];
}

void print(struct node *root)
{
    int front1,rear;
    struct node **q = createQueue(&front1,&rear);
    struct node *temp = root;

    while (temp)
    {
        cout << temp->data << " ";

        if (temp->left)
            enqueue(q,&rear,temp->left);
        if (temp->right)
            enqueue(q,&rear,temp->right);

        temp = dequeue(q,&front1);
    }
}

struct node * newNode(int data)
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
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order Traversal of a binary Tree using a queue is : " << endl;
    print(root);

    return 0;
}
