#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
void merge(long long int a[], long long int n, long long int start,long long  int end)
{
    if (start == end)
    {
        return;
    }
    int mid = (start + end) / 2;
    merge(a, n, start, mid);
    merge(a, n, mid + 1, end);

    long long int l = start, r = mid + 1, i = 0;
    long long int temp[end - start + 1];

    while (l <= mid || r <= end)
    {
        long long int left = INT_MAX;
        long long int right = INT_MAX;
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
    for (long long int j = 0; j < end - start + 1; j++)
    {
        a[j + start] = temp[j];
    }
}
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int a[n],b[n];
    long long int ans[n];
    long long int sum = 0;
    for(long long int i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i],&b[i]);
        ans[i]=a[i]-b[i];
        sum += (b[i]*n) - a[i];
    }
    merge(ans,n,0,n-1);
    for(long long int i=0;i<n;i++)
    {
        sum += (n-i)*ans[i];
    }
    printf("%lld\n",sum);

    return 0;
}