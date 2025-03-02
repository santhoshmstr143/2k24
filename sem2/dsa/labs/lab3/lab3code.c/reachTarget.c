#include <stdio.h>
#include <limits.h>
int main()
{
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i]==m)
        {
            printf("Yes\n");
            return 0;
        }
        if (a[i] < m)
        {
            int dif = m - a[i];
            if (dif % x == 0)
            {
                printf("Yes\n");
                return 0;
            }
            else
            {
                while (a[i] < m)
                {
                    a[i] = a[i] * y;
                }
                if (a[i] == m)
                {
                    printf("Yes\n");
                    return 0;
                }
            }
        }
    }
    printf("No\n");
    return 0;
}