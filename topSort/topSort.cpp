#include<iostream>
#include<queue>
#include<vector>
#define SIZE 100

int n,m,edgesCount[SIZE];
std::vector<int> graph[SIZE];

void topSort() {
    std::queue<int> ready;
    std::vector<int> sorted;

    for (int i=0;i<n;++i) {
        if (edgesCount[i]==0)
            ready.push(i);
    }

    while(!ready.empty()) {
        int curr=ready.front();
        ready.pop();
        sorted.push_back(curr);
        for (int neigbour : graph[curr]) {
            edgesCount[neigbour]--;
            if (edgesCount[neigbour]==0)
                ready.push(neigbour);
        }
    }
    if (sorted.size() != n)
        printf("There is a cycle!\n");
    else {
        for (int x : sorted) {
            printf("%d ",x);
        }
        printf("\n");
    }
}

int main() {
    int x,y;
    scanf("%d %d",&n,&m);
    for (size_t i=0;i<m;++i) {
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        edgesCount[y]++;
    }
    topSort();
    return 0;
}