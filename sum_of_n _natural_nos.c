#include <stdio.h>
int main()
{
    int n;
    printf("\nEnter the number:");
    scanf("%d",&n);
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("\nsum of %d natural no.s: %d",n,sum);
    return 0;
}
