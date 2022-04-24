#include <iostream>
#include <vector>
#include <queue>
#define SIZE 10

void addEdge(int x, int y, std::vector<int> (&graph)[SIZE]) {
    graph[x].push_back(y);
};

void BFS(int x, std::vector<int> (&graph)[SIZE]) {
    bool visited[SIZE] = {false};
    std::queue<int> qu;

    visited[x] = true;
    qu.push(x);

    while (!qu.empty()) {
        x = qu.front();
        qu.pop();
        std::cout << x << " ";
        int size = graph[x].size();
        for (size_t i = 0; i < size; ++i) {
            if (!visited[graph[x][i]]) {
                visited[graph[x][i]] = true;
                qu.push(graph[x][i]);
            }
        }
    }
}

int main() {
    std::vector<int> graph[SIZE];
    addEdge(0, 1, graph);
    addEdge(0, 2, graph);
    addEdge(1, 2, graph);
    addEdge(2, 0, graph);
    addEdge(2, 3, graph);
    addEdge(3, 3, graph);
    BFS(1, graph);
    return 0;
}