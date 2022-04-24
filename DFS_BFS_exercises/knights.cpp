#include <iostream>
#include <queue>
#define SIZE 200
#define VISITED 1

int N, M, K;
bool visited[SIZE][SIZE]={false};
int dist[SIZE][SIZE]={0};

std::pair<int,int> validMovements[] = {{-1,-2},{-2,-1},{-2,+1},{-1,+2},
                                       {+1,+2},{+2,+1},{+2,-1},{+1,-2}};

bool isValidPos(const std::pair<int,int> &node) {
    return node.first>=0 && node.first<N && node.second>=0 && node.second<N;
}

void BFS(std::pair<int,int> x) {
    visited[x.first][x.second] = true;
    std::queue<std::pair<int,int>> qu;
    qu.push(x);
    while(!qu.empty()) {
        std::pair<int,int> curr = qu.front();
        qu.pop();
        for (int i=0;i<8;++i) {
            std::pair<int,int> neighbour = {curr.first + validMovements[i].first,
                                            curr.second + validMovements[i].second};
            if (isValidPos(neighbour) && !visited[neighbour.first][neighbour.second]) {
                qu.push(neighbour);
                dist[neighbour.first][neighbour.second] = dist[curr.first][curr.second] + 1;
                visited[neighbour.first][neighbour.second] = true;
            }
        }
    }
}

int main() {
    std::pair<int,int> knights[SIZE];
    std::pair<int,int> princess;
    scanf("%d %d %d",&N,&M,&K);
    int x,y;
    for (size_t i=0;i<M;++i) {
        scanf("%d %d",&x,&y);
        visited[x][y] = VISITED;
    }
    for (size_t i=0;i<K;++i) {
        scanf("%d %d",&x,&y);
        knights[i].first;
        knights[i].second;
    }
    scanf("%d %d",&x,&y);
    princess.first=x;
    princess.second=y;
    BFS(princess);
    int maxSteps = 0;
    int countOfKnights = 0;
    for (size_t i = 0; i < K; ++i) {
        if (visited[knights[i].first][knights[i].second]) {
            ++countOfKnights;
            maxSteps=std::max(maxSteps,dist[knights[i].first][knights[i].second]);
        }
    }
    std::cout << countOfKnights  << " " << maxSteps;
    return 0;
}