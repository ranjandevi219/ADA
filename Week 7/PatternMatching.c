#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char text[20],pattern[20];
    int n,m,i,j=0;
    printf("Enter the given text:\n ");
    scanf("%s",text);
    printf("Enter the pattern:\n");
    scanf("%s",pattern);
    n=strlen(text);
    m=strlen(pattern);
    for( i=0;i<=n-m;i++)
    {
        while(j<m && text[i+j]==pattern[j])
        {
            j++;
        }
        if(j==m)
        {
            printf("Position of match=%d",i);
        exit(0);
    }
    }
    printf("Pattern not found");
}
