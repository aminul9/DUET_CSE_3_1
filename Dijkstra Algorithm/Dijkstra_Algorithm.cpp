

#include <bits/stdc++.h>
using namespace std;
#define INF 9999

int cost_matrix[50][50];
int dist[50];

void intialize(int node,int edge)
{
    for(int i=1;i<=node;i++)
        for(int j=1;j<=node;j++)
                cost_matrix[i][j]=INF;

                cout<<"u v w"<<endl;
    for(int i=1;i<=edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        cout<<u<<" "<<v<<" "<<w<<" "<<endl;
        cost_matrix[u][v]=w;
    }

}

void dijkstra(int v,int n)
{
    bool  s[50];

    for(int i=1;i<=n;i++)
    {
        s[i]=false;
        dist[i] =cost_matrix[v][i];
    }

    s[v]=true;dist[v]=0;


    for(int i=2;i<=n;i++)
    {
        int u=i,maximum=INF;
        for(int j=1;j<=n;j++)
        {
            if(dist[j] <maximum and s[j]==false)
               {
                  maximum=dist[j];
                  u=j;
               }
        }
        s[u]=true;

        for(int w=1;w<=n;w++)
            {
                 if(cost_matrix[u][w]!=INF )
                 {
                     if(dist[w] > dist[u]+ cost_matrix[u][w])
                        dist[w]=dist[u]+ cost_matrix[u][w];
                 }
             }

    }

}

int main()
{
   freopen("in.txt","r",stdin);


    int node,edge,src;
    cin>>node>>edge>>src;
    cout<<"Node="<<node<<"   "<<"Edge="<<edge<<"  Source ="<<src<<endl;
    intialize(node,edge);





    dijkstra(src,node);

     for(int i=1;i<=node;i++)
        cout<<src<<"---->"<<i<<" Distance is "<<dist[i]<<endl;


    return 0;

}
