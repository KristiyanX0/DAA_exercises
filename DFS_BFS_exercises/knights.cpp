#include <iostream>
#define SIZE 2000
int N, M, K;

std::pair<int,int> validMovements[] = {{-1,-2},{-2,-1},{-2,+1},{-1,+2},
                                       {+1,+2},{+2,+1},{+2,-1},{+1,-2}};

bool isValidPos(const std::pair<int,int> &node) {
    return node.first>=0 && node.first<N && node.second>=0 && node.second<N;
}

int main() {
    int eflandia[SIZE][SIZE]={0};
    std::pair<int,int> knights[SIZE];
    std::pair<int,int> princess;
    scanf("%d %d %d",&N,&M,&K);
    int x,y;
    for (size_t i=0;i<N;++i) {
        scanf("%d %d",&x,&y);
        eflandia[x][y] = {-1};
    }
    for (size_t i=0;i<M;++i) {
        scanf("%d %d",&x,&y);
        princess.first=x;
        princess.second=y;
    }
    scanf("%d %d",&x,&y);
    princess.first=x;
    princess.second=y;
    
    return 0;
}