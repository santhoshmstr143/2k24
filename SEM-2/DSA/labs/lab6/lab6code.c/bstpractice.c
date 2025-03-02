#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int count;
}node;

node *create(int val)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->count = 0;
    return newnode;
}

node *insert(node *root,int x)
{
    node *newnode = create(x);

    if(root == NULL) return newnode;

    if(root->data > x)
    {
        root->left=insert(root->left,x);
    }
    else if(root->data < x)
    {
        root->right=insert(root->right,x);
    }
    root->count++;
    return root;
}
node *find(node *root,int x)
{
    if(root->data == x)
    {
        return root;
    }
    if(root->data > x)
    {
        return find(root->left,x);
    }
    else
    {
        return find(root->right,x);
    }
}

int main()
{
    int n,q,x;
    node *root;
    scanf("%d %d",&n,&q);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        root = insert(root,x);
    }

    for(int i=0;i<q;i++)
    {
        int op;
        scanf("%d",&op);

        if(op==1)
        {
            scanf("%d",&x);
            root= insert(root,x);
        }
        else if(op==2)
        {
            scanf("%d",&x);
            node *temp = find(root,x);
            if(temp->left)
                printf("%d\n",temp->left->count);
            else
                printf("0");
        }
        else if(op == 3)
        {
            scanf("%d",&x);
            node *temp = find(root,x);
            if(temp->right)
                printf("%d\n",temp->right->count);
            else
                printf("0");
        }
    }
    return 0;
}