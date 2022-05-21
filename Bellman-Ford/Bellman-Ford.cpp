#include<iostream>
#include<vector>
#include<limits.h>
#define SIZE 10000

int N,M;
struct Edge{
    int from, to, weight;

    bool operator<(const Edge &target) const {
        return this->weight < target.weight;
    }
} edges[SIZE];

void Bellman_Ford(int src) {
    int dist[SIZE];

    for (int i = 0; i < N; i++)
        dist[i] = INT32_MAX;
    dist[src] = 0;

    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < M; j++) {
            int begin = edges[j].from;
            int end = edges[j].to;
            int weight = edges[j].weight;
            if (dist[begin] != INT_MAX
                && dist[begin] + weight < dist[end])
                dist[end] = dist[begin] + weight;
        }
    }
}

void init() {
    scanf("%d %d",&N,&M);
    int from,to,weight;
    for (int i=0;i<M;++i)
        scanf("%d %d %d",edges[i].from,edges[i].to,edges[i].weight);
    
}

int main() {
    return 0;
}