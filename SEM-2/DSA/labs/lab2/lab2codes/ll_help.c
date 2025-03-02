#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *insert(node *head, int x)
{
    printf("%d\n", x);
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = head;
    return newnode;
}

node *insert_end(node *head, int x)
{
    printf("%d\n", x);
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    return head;
}

node *delete(node *head)
{
    if (head == NULL)
    {
        printf("-1\n");
        return head;
    }
    printf("%d\n", head->data);
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

node *delete_end(node *head)
{
    if (head == NULL)
    {
        printf("-1\n");
        return head;
    }

    if (head->next == NULL)
    {
        printf("%d\n", head->data);
        free(head);
        return NULL;
    }

    node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    printf("%d\n", ptr->next->data);
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

void length(node *head)
{
    int k = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        k++;
    }
    printf("%d\n", k);
}

int main()
{
    int q;
    scanf("%d", &q);
    node *head = NULL;
    for (int i = 0; i < q; i++)
    {
        int op, k;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &k);
            head = insert(head, k);
        }
        else if (op == 2)
        {
            scanf("%d", &k);
            head = insert_end(head, k);
        }
        else if (op == 3)
        {
            head = delete (head);
        }
        else if (op == 4)
        {
            head = delete_end(head);
        }
        else if (op == 5)
        {
            length(head);
        }
    }
    return 0;
}