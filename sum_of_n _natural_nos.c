#include <stdio.h>
int main()
{
    int m;
    printf("\nEnter the number:");
    scanf("%d",&m);
    int sum = 0;
    for(int i=1;i<=m;i++)
    {
        sum += i;
    }
    printf("\nsum of %d natural no.s: %d",m,sum);
    return 0;
}
