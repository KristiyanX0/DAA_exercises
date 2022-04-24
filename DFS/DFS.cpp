#include<iostream>
#include<queue>
#include<vector>
#define SIZE 10

void addEdge(int x, int y, std::vector<int> (&graph)[SIZE]) {
    graph[x].push_back(y);
}

bool visited[SIZE]={false};

void DFS(int x, std::vector<int> (&graph)[SIZE]) {
    visited[x]=true;
    std::cout<<x<<" ";
    int size = graph[x].size();
    for (size_t i=0;i<size;++i)
        if (!visited[graph[x][i]])
            DFS(graph[x][i],graph);
}

int main() {
    std::vector<int> graph[SIZE];
    addEdge(0, 1, graph);
    addEdge(0, 2, graph);
    addEdge(1, 2, graph);
    addEdge(2, 0, graph);
    addEdge(2, 3, graph);
    addEdge(3, 3, graph);
    DFS(3, graph);
    return 0;
}