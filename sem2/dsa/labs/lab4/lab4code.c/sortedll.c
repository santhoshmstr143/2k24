#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void print(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void merge(int a[], int n, int start, int end)
{
    if (start == end)
    {
        return;
    }
    int mid = (start + end) / 2;
    merge(a, n, start, mid);
    merge(a, n, mid + 1, end);

    int l = start, r = mid + 1, i = 0;
    int temp[end - start + 1];

    while (l <= mid || r <= end)
    {
        int left = INT_MAX;
        int right = INT_MAX;
        if (l <= mid)
            left = a[l];
        if (r <= end)
            right = a[r];
        if (left < right)
        {
            temp[i] = left;
            i++;
            l++;
        }
        else
        {
            temp[i] = right;
            i++;
            r++;
        }
    }
    for (int j = 0; j < end - start + 1; j++)
    {
        a[j + start] = temp[j];
    }
}

node *insert(node *head, int val)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    new->next = NULL;
    if (head == NULL || head->data > val)
    {
        new->next = head;
        return new;
    }
    node *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->next->data > val)
            break;
        ptr = ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
    return head;
}
node *delete(node *head, int val)
{
    if (head == NULL)
        return NULL;

    if (head->data == val)
    {
        
        head = head->next;
        return head;
    }
    node *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->next->data == val)
        {
            ptr->next = ptr->next->next;
            break;
        }
        ptr=ptr->next;
    }
    return head;
}
int main()
{
    int n;
    scanf("%d", &n);
    node *head = NULL;
    node *ptr = NULL;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    merge(a, n,0,n-1);
    for (int i = 0; i < n; i++)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = a[i];
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->next = newnode;
            ptr = newnode;
        }
    }
    //print(head);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int va;
            scanf("%d", &va);
            head = insert(head, va);
        }
        else if (op == 2)
        {
            int vax;
            scanf("%d", &vax);
            head = delete (head, vax);
        }
        else if (op == 3)
        {
            print(head);
        }
        //printf("77\n");
    }
}