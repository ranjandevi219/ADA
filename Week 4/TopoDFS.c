#include <stdio.h>
int a[20][20],n,res[20],visited[20],j=0;
void DFS(int v)
{
    visited[v]=1;
    for(int i=0;i<n;i++)
    {
        if(a[i][v]==1 && visited[i]==0)
            DFS(i);
    }

    res[j++]=v;
}
void main()
{
    int i,j,v;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=0;i<n;i++)
        visited[i]=0;
    for(v=0;v<n-1;v++)
    {
        if(visited[v]==0)
            DFS(v);
    }
    for(i=0;i<n;i++)
        printf("%d\t",res[i]);
}
