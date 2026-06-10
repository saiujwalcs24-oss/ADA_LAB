#include<stdio.h>
#define INF 9999
#define MAX 20
void dijkstra(int n,int cost[MAX][MAX],int source){
    int dist[MAX],visited[MAX];
    for(int i=0;i<n;i++){
        dist[i]=cost[source][i];
        visited[i]=0;
}
dist[source]=0;
visited[source]=1;
for(int count=1;count<n;count++){
    int min=INF;
    int u=-1;
    for (int i=0;i<n;i++){
        if(visited[i]==0 && dist[i]<min){
            min=dist[i];
            u=i;
        }
    }
    visited[u]=1;
    for (int v=0;v<n;v++){
        if(visited[v]==0 && cost[u][v]!=INF){
            if(dist[u]+cost[u][v]<dist[v]){
                    dist[v]=cost[u][v]+dist[u];
            }
        }
    }
}
for(int i=0;i<n;i++){
    printf("Distance from %d to %d= %d\n", source,i,dist[i]);
}
}
int main(){
    int source,n,cost[MAX][MAX];
    printf("Enter number of vertices");
    scanf("%d",&n);
    printf("Enter cost matrix( use 9999 for no edge:\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",& cost[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d",&source);
    dijkstra(n,cost,source);
    return 0;

 }

