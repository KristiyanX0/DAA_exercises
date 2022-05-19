#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#define SIZE 100000

int n,m;
int lenght[SIZE];
std::vector<std::pair<int,int>> gr[SIZE];

void init() {
    scanf("%d %d",&n,&m);
    int from,to,price;
    for(int i=0;i<n;++i) {
        scanf("%d %d %d %d",&from,&to,&price,&(lenght[i]));
        gr[from].push_back({to,price});
    }
}

void dijkstra(int src) {
    int dist[SIZE];
    std::fill(dist,dist+n,INT_MAX);
    dist[src]=0;
    std::priority_queue<std::pair<int,int>,
                        std::vector<std::pair<int,int>>,
                        std::greater<std::pair<int,int>>> nodes;
    nodes.push({0,src});
    
}

int main() {
    init();
    dijkstra(0);
    return 0;
}