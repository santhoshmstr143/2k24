#include <stdio.h>
#include <string.h>
int isValid(char *s)
{
    int n = strlen(s);
    char a[n];
    int top = -1,brac=0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            top++;
            a[top] = s[i];
            brac = 1;
        }
        else if (s[i] == ')'  || s[i] == '}' || s[i] == ']' )
        {
            if (top == -1)
                return 0;
            if ((s[i] == ')' && a[top] == '(') ||
                (s[i] == '}' && a[top] == '{') ||
                (s[i] == ']' && a[top] == '['))
            {
                top--;
            }
            brac = 1;
        }
    }
    if (top == -1 && brac == 1)
        return 1;
    else
        return 0;
}
int palin(char *s)
{
    int n = strlen(s);
    for(int i =0;i<n/2;i++)
    {
        if(s[i] != s[n-i-1])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int q;
    scanf("%d", &q);
    for (int j = 0; j < q; j++)
    {
        char s[10001];
        scanf("%s", s);
        int balanced = 0;
        int palindrome = 0;
        balanced = isValid(s);
        palindrome = palin(s);
        if (balanced == 1 && palindrome == 1)
        {
            printf("Balanced and Palindromic\n");
        }
        else if (balanced == 1)
        {
            printf("Balanced\n");
        }
        else if (palindrome == 1)
        {
            printf("Palindromic\n");
        }
        else
        {
            printf("-1\n");
        }
    }
}