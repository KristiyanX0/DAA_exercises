#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define SIZE 10000

int sum=0;
int sumD=0;
int N,M;
int dsuParent[SIZE];

struct Edge {
    int from,to,weight;
    bool operator<(const Edge &other) const {
        return this->weight < other.weight;
    }
} edges[SIZE];
std::vector<int> graph[SIZE];

bool From[SIZE]={false};
bool To[SIZE]={false};

void BFS(int x) {
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

void init() {
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;++i) {
        scanf("%d %d %d",&edges[i].from,&edges[i].to,&edges[i].weight);
        graph[edges[i].from].push_back(edges[i].to);
        graph[edges[i].to].push_back(edges[i].from);
        sumD+=edges[i].weight;
    }
    for (int i=0;i<N;++i) {
        dsuParent[i]=i;
    }
}

bool areAllAvaliable() {
    for(int i=0;i<N;++i)
        if (!From[i] || !To[i])
            return false;
    return true;
}

int getRoot(int node) {
    if (node==dsuParent[node])
        return node;
    return dsuParent[node]=getRoot(dsuParent[node]);
}

void mstUnite(int root1, int root2) {
    dsuParent[root1]=root2;
}

void Kruskal() {
    std::sort(edges,edges+M);
    for (int i=0;i<M;++i) {
        int root1=getRoot(edges[i].from);
        int root2=getRoot(edges[i].to);
        if (root1==root2)
            continue;
        sum+=edges[i].weight;
        mstUnite(root1,root2);
    }
}

int main() {
    init();
    if (!areAllAvaliable()) {
        printf("%d",-1);
        return 0;
    }
    Kruskal();
    printf("%d",sumD-sum);
    return 0;
}