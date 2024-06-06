#include <stdio.h>
void topologicalSort(int a[20][20],int n)
{
    int i,j,k;
    int sum,top=-1,indegree[20],s[20],u,v,T[20];
    for(j=0;j<n;j++)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+a[i][j];
        }
        indegree[j]=sum;
    }
    for(i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            top=top+1;
            s[top]=i;
        }
    }
    k=0;
    while(top!=-1)
    {
        u=s[top];
        top=top-1;
        T[k++]=u;
        for(i=0;i<n;i++)
        {
            if(a[u][i])
            {
                v=i;
                indegree[v]-=1;
            }
            if(indegree[v]==0)
            {
                top=top+1;
                s[top]=v;
            }
        }
    }
    printf("Topological Order:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",T[i]);
    }
}

void main()
{
    int a[20][20],n;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    topologicalSort(a,n);
}
