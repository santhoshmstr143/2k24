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

int main()
{
    int a, b, c, q;
    node *head = NULL;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &a);
        if (a == 0)
        {
            scanf("%d %d", &b, &c);
            node *newnode = (node *)malloc(sizeof(node));
            newnode->data = c;
            newnode->next = NULL;
            node *temp = head;
            if (b == 0)
            {
                newnode->next = head;
                head = newnode;
            }
            else
            {
                while (temp->next != NULL)
                {
                    b--;
                    if (b == 0)
                    {
                        newnode->next = temp->next;
                        temp->next = newnode;
                        break;
                    }
                    temp = temp->next;
                }
                if (b != 0)
                    temp->next = newnode;
            }
        }
        else if (a == 1)
        {
            scanf("%d", &b);
            if (head == NULL)
                printf("\n");
            else if (b == 0)
            {
                node *lol = head;
                head = head->next;
                free(lol);
            }
            else
            {
                node *temp = head;
                while (temp != NULL && temp->next != NULL && b>1)
                {
                    b--;
                    temp = temp->next;
                }
                if (temp != NULL && temp->next != NULL)
                {
                    node *lol = temp->next;
                    temp->next = temp->next->next;
                    free(lol);
                }
            }
        }
        print(head);
    }
}