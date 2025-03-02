#include <stdio.h>
#include <limits.h>
int main()
{
    int q;
    scanf("%d", &q);
    for (int j = 0; j < q; j++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int max = INT_MIN, k = 0, l[n];
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] >= max)
            {
                l[k++] = a[i];
                max = a[i];
            }
        }
        for (int i = k - 1; i >= 0; i--)
        {
            printf("%d ", l[i]);
        }
        printf("\n");
    }
    return 0;
}