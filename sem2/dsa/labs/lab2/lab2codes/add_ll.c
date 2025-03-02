#include <stdio.h>
#include <stdlib.h>

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

node *create(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

node *sum(node *l1, node *l2)
{
    node *head = NULL, *ptr;
    int c = 0, k;
    while (l1 != NULL || l2 != NULL)
    {
        int val1 = (l1 != NULL) ? l1->data : 0;
        int val2 = (l2 != NULL) ? l2->data : 0;

        k = val1 + val2 + c;
        c = k / 10;
        k = k % 10;
        node *newNode = create(k);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            ptr->next = newNode;
        }
        ptr = newNode;

        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }
    if (c > 0)
    {
        node *newNode = create(c);
        ptr->next = newNode;
    }
    return head;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        node *head[2] = {NULL, NULL};
        node *tail[2] = {NULL, NULL};

        while (1)
        {
            int m;
            scanf("%d", &m);
            if (m < 0)
                break;
            node *newnode = create(m);
            if (head[0] == NULL)
            {
                head[0] = newnode;
                tail[0] = newnode;
            }
            else
            {
                tail[0]->next = newnode;
                tail[0] = newnode;
            }
        }

        while (1)
        {
            int m;
            scanf("%d", &m);
            if (m < 0)
                break;
            node *newnode = create(m);
            if (head[1] == NULL)
            {
                head[1] = newnode;
                tail[1] = newnode;
            }
            else
            {
                tail[1]->next = newnode;
                tail[1] = newnode;
            }
        }

        node *ans = sum(head[0], head[1]);
        print(ans);
    }
    return 0;
}