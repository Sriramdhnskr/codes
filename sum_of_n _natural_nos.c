#include <stdio.h>
int sum(int n)
{
    if(n==0)
        return 0;
    return n + sum(n-1);
}
int main()
{
    int m;
    printf("\nEnter the number:");
    scanf("%d",&m);
    printf("\nsum of %d natural no.s: %d",m,sum(m));
    return 0;
}
