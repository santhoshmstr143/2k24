#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        char str1[x + 1], str2[y + 1];
        scanf("%s %s", str1, str2);

        char stac1[x + 1], stac2[y + 1];
        int top1 = -1, top2 = -1;

        for (int j = 0; j < x; j++)
        {
            if (str1[j] >= 'A' && str1[j] <= 'Z')
            {
                stac1[++top1] = str1[j];
            }
            else if (str1[j] == 'x' && top1 >= 0)
            {
                top1--;
            }
        }
        stac1[++top1] = '\0'; 

        for (int j = 0; j < y; j++)
        {
            if (str2[j] >= 'A' && str2[j] <= 'Z')
            {
                stac2[++top2] = str2[j];
            }
            else if (str2[j] == 'd' && top2 >= 0)
            {
                top2--;
            }
        }
        stac2[++top2] = '\0';

        // printf("%s\n", stac1);
        // printf("%s\n", stac2);
        int c = strcmp(stac1,stac2);
        if (c == 0)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
