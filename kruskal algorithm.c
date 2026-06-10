#include <stdio.h>

#define MAX 100

struct Edge
{
    int src;
    int dest;
    int weight;
};

int parent[MAX];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int u, int v)
{
    parent[u] = v;
}

int main()
{
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Edge edges[m];

    printf("Enter source destination weight:\n");
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    // Step 1: Initialize parent array
    for(int i = 0; i < n; i++)
        parent[i] = i;

    int mincost = 0;
    int edges_selected = 0;

    printf("\nEdges in MST:\n");

    // Step 2: Pick smallest edge each time (like pseudocode)
    while(edges_selected < n-1)
    {
        int min = 9999;
        int u = -1, v = -1;
        int index = -1;

        // Find minimum edge
        for(int i = 0; i < m; i++)
        {
            if(edges[i].weight < min)
            {
                min = edges[i].weight;
                u = edges[i].src;
                v = edges[i].dest;
                index = i;
            }
        }

        int set_u = find(u);
        int set_v = find(v);

        if(set_u != set_v)
        {
            printf("%d - %d : %d\n", u, v, min);
            mincost += min;
            union_set(set_u, set_v);
            edges_selected++;
        }

        // Mark edge as used
        edges[index].weight = 9999;
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}
