#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char word[1000];
    struct node *next;
    struct node *prev;
} node;

int main()
{
    char str[1001001];
    scanf("%s", str);

    int len = strlen(str);
    node *head;
    head = NULL;
    node *tail = NULL;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '/')
            continue;

        if (str[i] == '.')
        {
            if (i + 1 == len || str[i + 1] == '/')
                continue;
        }
        if (str[i] == '.' && i + 1 < len && str[i + 1] == '.' && (i + 2 == len || str[i + 2] == '/'))
        {
            if (tail != NULL)
            {
                node *temp = tail;
                tail = tail->prev;
                if (tail != NULL)
                {
                    tail->next = NULL;
                }
                else
                {
                    head = NULL;
                }
                free(temp);
            }

            i++;
            continue;
        }

        int j = 0;
        node *newnode = (node *)malloc(sizeof(node));
        while (i < len && str[i] != '/')
        {
            newnode->word[j++] = str[i++];
        }
        newnode->word[j] = '\0';
        newnode->next = NULL;
        newnode->prev = tail;

        if (tail == NULL)
        {
            head = newnode;
        }
        else
        {
            tail->next = newnode;
        }
        tail = newnode;
    }

    if (head == NULL)
    {
        printf("/\n");
        return 0;
    }

    node *lol = head;
    while (lol != NULL)
    {
        printf("/%s", lol->word);
        lol = lol->next;
    }
    printf("\n");

    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
