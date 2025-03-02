#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int x)
{
    if (root == NULL)
        return create(x);

    node *c = root;
    while (1)
    {
        if (x < c->data)
        {
            if (c->left == NULL)
            {
                c->left = create(x);
                break;
            }
            else
            {
                c = c->left;
            }
        }
        else
        {
            if (c->right == NULL)
            {
                c->right = create(x);
                break;
            }
            else
            {
                c = c->right;
            }
        }
    }
    return root;
}

void zigzagPrint(node *root)
{
    if (root == NULL)
        return;

    node *lol1[100], *lol2[100];
    int top1 = -1, top2 = -1;
    lol1[++top1] = root;

    while (top1 >= 0 || top2 >= 0)
    {
        while (top1 >= 0)
        {
            node *temp = lol1[top1--];
            printf("%d ", temp->data);
            if (temp->left)
                lol2[++top2] = temp->left;
            if (temp->right)
                lol2[++top2] = temp->right;
        }
        while (top2 >= 0)
        {
            node *temp = lol2[top2--];
            printf("%d ", temp->data);
            if (temp->right)
                lol1[++top1] = temp->right;
            if (temp->left)
                lol1[++top1] = temp->left;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    zigzagPrint(root);

    return 0;
}
