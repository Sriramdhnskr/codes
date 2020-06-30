#include <stdio.h>
int sum(int n)
{
    int sum = 0;
    for(int i=1;i<=m;i++)
    {
        sum += i;
    }
    return sum;
}
int main()
{
    int m;
    printf("\nEnter the number:");
    scanf("%d",&m);
    printf("\nsum of %d natural no.s: %d",m,sum(m));
    return 0;
}
