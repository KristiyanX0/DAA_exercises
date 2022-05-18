#include<iostream>
#include<vector>
#include<queue>
#define SIZE 200

int N, edgesCount[SIZE]={0};
std::pair<int,std::vector<int>> graph[SIZE];

void print() {
    printf("\n");
    for (int i=0;i<N;++i) {
        printf("%d: ",i);
        for (int j=0;j<graph[i].second.size();++j) {
            printf("%d ", graph[i].second[j]);
        }
        printf("\n");
    }
}

void topSort() {
    std::queue<int> ready;
    std::vector<int> sorted;

    for (int i=0;i<N;++i) {
        if (edgesCount[i]==0)
            ready.push(i);
    }
}

void init() {
    int t,m,vertex;
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {   
        scanf("%d %d",&graph[i].first,&m);
        for (int j = 0; j < m; ++j) {
            edgesCount[i]++;
            scanf("%d", &vertex);
            graph[i].second.push_back(vertex);
        }
    }
}

int main() {
    init();
    print();
    return 0;
}