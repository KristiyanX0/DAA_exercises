#include<iostream>
#include<vector>
#include<algorithm>
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
std::vector<std::pair<int,int>> mst[SIZE];

void init() {
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;++i) {
        scanf("%d %d %d",&edges[i].from,&edges[i].to,&edges[i].weight);
        sumD+=edges[i].weight;
    }
    for (int i=0;i<N;++i) {
        dsuParent[i]=i;
    }
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
    Kruskal();
    printf("%d\n",sum);
    return 0;
}