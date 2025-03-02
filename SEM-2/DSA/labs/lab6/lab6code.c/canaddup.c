#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int tar;
    scanf("%d",&tar);
    merge(a, n, 0, n - 1);

    int l = 0, r= n-1;
    while(l<r)
    {
        int sum = a[l]+a[r];
        if(sum==tar)
        {
            printf("1\n");
            return 0;
        }
        else if(sum<tar)
        {
            l++;
        }
        else{
            r--;
        }
    }
    printf("0\n");
    return 0;
}