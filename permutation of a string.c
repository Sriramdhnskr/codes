#include <stdio.h>
void permute(char s[],int k)
{
    static int A[26]={0};
    static char Res[10];
    if(s[k]=='\0')
        {
            Res[k]='\0';
            printf("%s ",Res);
        }
    else
    
{
    for(int i=0;s[i]!='\0';i++)
    {
        
        if(A[i]==0)
        {
            Res[k]=s[i];
            A[i]=1;
            permute(s,k+1);
            A[i]=0;
        }
    }
}
}
int main()
{
   char s[]="ABC";
   permute(s,0);
    return 0;
}
