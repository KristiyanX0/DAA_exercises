#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#define SIZE (int)1e5

int n,m;
std::vector<std::pair<int,int>> gr[SIZE];

void init() {
    int from,to,weight;
    scanf("%d %d",&n,&m);
    for (size_t i=0;i<m;++i) {
        scanf("%d %d %d",&from,&to,&weight);
        gr[from].push_back({to,weight});
        gr[to].push_back({from,weight});
    }
}

void dijkstra(int src) {
    int dist[SIZE];
    bool used[SIZE]={false};
    int parent[SIZE];
    std::fill(dist,dist+n,INT_MAX);
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> nodes;
    nodes.push({0,src}); // първото е нула защото трябва да се сортира по 0
    dist[src]=0;
    parent[src]=-1;
    while (!nodes.empty()) {
        int vertex=nodes.top().second;
        nodes.pop();
        if (used[vertex])
            continue;
        used[vertex]=true;
        for (auto x : gr[vertex]) {
            int next_vertex = x.first;
            int weight = x.second;
            int newDist = dist[vertex]+weight;
            if (dist[next_vertex]>newDist) {
                dist[next_vertex]=newDist;
                parent[next_vertex]=vertex;
                nodes.push({dist[next_vertex],next_vertex});

            }
        }
    }
    printf("Source: %d\tVertices\tPath\n",src);
    for (int i=0;i<n;++i) {
        printf("%d\t\t",i);
        if (dist[i] != INT_MAX) {
            printf("%d\t\t",dist[i]);
            int x=i;
            while(x!=-1){
                printf("%d <- ",x);
                x=parent[x];
            }
        }
        else
            printf("inf\t\t");
        printf("\n");
    }
}

int main() {
    init();
    dijkstra(5);
    return 0;
}