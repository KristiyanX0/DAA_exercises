#include<cstdio>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int n, m;
int parent[int(1e5)];
// int pathsCount[int(1e5)];
vector<pair<int, int>> gr[int(1e5)];

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
    
    int dist[int(1e5)];
    bool used[int(1e5)];
    std::fill(dist,dist+n,INT_MAX);
    std::priority_queue<std::pair<int,int>/*{node,weight}*/, 
                        std::vector<std::pair<int,int>>, 
                        std::greater<std::pair<int,int>>> nodes;
    nodes.push({0,src});
    dist[src]=0;
    parent[src]=-1;
    while(!nodes.empty()) {
        int vertex = nodes.top().second;
        nodes.pop();
        if (used[vertex])
            continue;
        used[vertex]=true;

        for (auto x : gr[vertex]) {
            int v = x.first;
            int weight = x.second;
            int newDist = dist[vertex] + weight;
            if (dist[v] > newDist) {
                parent[v]=vertex;
                dist[v] = newDist;
                nodes.push({dist[v],v});
            }
        }
    }
    printf("\nThe source is %d\nVertices:\tDistance:\tPath:\n",src);
    for (int i=0;i<n;++i) {
        printf("%d\t\t%d\t\t",i,dist[i]);
        int x=i;
        while(x!=-1){
            printf("%d <- ",x);
            x=parent[x];
        }
        printf("\n");
    }
}

int main(){
    init();
    dijkstra(0);
    return 0;
}