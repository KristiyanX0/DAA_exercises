// https://action.informatika.bg/problems/100
#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<stack>
#define N 10000
#define M 100000

int n,m;
int time_bus[N];
std::vector<std::pair<int,int>> gr[N];

int added_minutes(int x, int y) {
    int ans = y-x%y;
    return (x%y==0) ? 0 : ans;
}

void init() {
    scanf("%d %d",&n,&m);
    int t=0;
    for (int i=0;i<n;++i) {
        scanf("%d",&t);
        time_bus[i]=t;
    }
    int from,to,weight;
    for (int i=0;i<m;++i) {
        scanf("%d %d %d",&from,&to,&weight);
        gr[from - 1].push_back({to-1, weight});
    }
}

void modified_dijkstra(int src) {
    int dist[N]; 
    std::fill(dist,dist+n,INT_MAX);
    dist[src]=0;
    int parent[N]; parent[src]=-1;
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> nodes;
    nodes.push({0,src});
    while(!nodes.empty()) {
        int vertex=nodes.top().second;
        nodes.pop();
        for (int i=0; i<gr[vertex].size();++i) {
            int next_vertex=gr[vertex][i].first;
            int weight=gr[vertex][i].second;
            int newDist=dist[vertex]+weight;
            newDist += added_minutes(newDist,time_bus[i]);
            if (dist[next_vertex]>newDist) {
                dist[next_vertex]=newDist;
                parent[next_vertex]=vertex;
                nodes.push({dist[next_vertex],next_vertex});
            }
        }
    }
    if (dist[n-1]==INT_MAX)
        printf("%d\n",-1);
    else {
        printf("%d\n",dist[n-1]);
        std::stack<int> sorted;
        int x=n-1;
        while(x!=-1) {
            sorted.push(x);
            x=parent[x];
        }
        printf("%d\n", (int)sorted.size());
        while(!sorted.empty()) {
            printf("%d ",sorted.top() + 1);
            sorted.pop();
        }
    }
}

int main() {
    init();
    modified_dijkstra(0);
    return 0;
}