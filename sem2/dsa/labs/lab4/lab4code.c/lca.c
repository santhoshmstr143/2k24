#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node
{
   int data;
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

int main()
{
   int n;
   scanf("%d", &n);

   int a, b;
   scanf("%d %d", &a, &b);
   int parent[n + 1];
   node *nodes[n + 1];
   for (int i = 1; i <= n; i++)
   {
      scanf("%d", &parent[i]);
      nodes[i] = create(i);
   }
   node *root = NULL;
   for (int i = 1; i <= n; i++)
   {
      if (parent[i] == -1)
      {
         root = nodes[i];
      }
      else
      {
         node *parentnode = nodes[parent[i]];
         if (parentnode->left == NULL)
         {
            parentnode->left = nodes[i];
         }
         else
         {
            parentnode->right = nodes[i];
         }
      }
   }
   int lca = findlca(parent, n, a, b);
   printf("%d\n",lca);
   return 0;
}