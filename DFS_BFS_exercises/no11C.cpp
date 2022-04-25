// https://judge.openfmi.net/practice/get_problem_description?contest_id=178&problem_id=554
//UNFINISHED

#include<iostream>
#include<vector>
#include<queue>
#define SIZE 1009
#define Qsize 10009

std::vector<int> path[SIZE];
bool connections[SIZE][SIZE]={false};
int curr = -1;

void BFS(int x) {
    bool visited[SIZE] = {false};
    std::queue<int> qu;

    visited[x] = true;
    qu.push(x);
    while (!qu.empty()) {
        x = qu.front();
        connections[curr][x]=true;
        qu.pop();
        int size = path[x].size();
        for (size_t i = 0; i < size; ++i) {
            if (!visited[path[x][i]]) {
                visited[path[x][i]] = true;
                qu.push(path[x][i]);
            }
        }
    }
}


int main() {
    int N,M,Q;
    scanf("%d %d",&N,&M);
    int x,y;
    for (size_t i=0;i<M;++i) {
        scanf("%d %d",&x,&y);
        path[x].push_back(y);
        path[y].push_back(x);
    }
    for (size_t i=1;i<=N;++i) {
        if (!path[i].empty()) {
            curr=i;
            BFS(i);
        }
    }
    scanf("%d",&Q);
    std::vector<bool> QQ(Qsize);
    for (size_t i=0;i<Q;++i) {
        scanf("%d %d",&x,&y);
        QQ[i]=connections[x][y];
    }
    for (size_t i=0;i<Q;++i)
        printf("%d",(int)QQ[i]);
    printf("\n");
    return 0;
}