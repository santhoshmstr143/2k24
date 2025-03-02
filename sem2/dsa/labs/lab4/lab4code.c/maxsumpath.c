#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    long long int data;
    struct node *left;
    struct node *right;
} node;

node *create(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(node *root)
{
   if (root == NULL)
      return 0;
   int lh = height(root->left);
   int rh = height(root->right);
   if (lh > rh)
   {
      return lh + 1;
   }
   else
   {
      return rh + 1;
   }
}


int diameter(node *root)
{
   if (root == NULL)
      return 0;
   int lh = height(root->left);
   int rh = height(root->right);
   int ld = diameter(root->left);
   int rd = diameter(root->right);
   int d = lh + rh;
   if (ld > d)
   {
      d = ld;
   }
   if (rd > d)
   {
      d = rd;
   }
   return d;
}

int findlca(int parent[], int n, int a, int b)
{
    int ancestors[n + 1];
    for (int i = 0; i <= n; i++)
        ancestors[i] = 0;
    while (a != -1)
    {
        ancestors[a] = 1;
        a = parent[a];
    }
    while (b != -1)
    {
        if (ancestors[b] == 1)
            return b;
        b = parent[b];
    }
    return -1;
}

void maxsum(node *root, long long int curr, long long int *max)
{
    if (root == NULL)
        return;
    curr += root->data;
    if (curr > *max)
        *max = curr;
    maxsum(root->left, curr, max);
    maxsum(root->right, curr, max);
}

int main()
{
    long long int q;
    scanf("%lld", &q);
    for (long long int j = 0; j < q; j++)
    {
        long long int n;
        scanf("%lld", &n);
        long long int parent[n + 1];
        node *nodes[n + 1];

        for (long long int i = 1; i <= n; i++)
        {
            scanf("%lld", &parent[i]);
            nodes[i] = create(i);
        }

        for (long long int i = 1; i <= n; i++)
        {
            scanf("%lld", &nodes[i]->data);
        }

        node *root = NULL;
        for (long long int i = 1; i <= n; i++)
        {
            if (parent[i] == -1)
                root = nodes[i];
            else
            {
                node *pnode = nodes[parent[i]];
                if (pnode->left == NULL)
                    pnode->left = nodes[i];
                else
                    pnode->right = nodes[i];
            }
        }

        long long int l = INT_MIN;
        maxsum(root, 0, &l);
        printf("%lld\n", l);
    }
    return 0;
}