//https://judge.openfmi.net/practice/get_problem_description?contest_id=178&problem_id=551

//LEFT HANGING
#include<stdio.h>
#include<vector>
#define SIZE 500

void addEdge(int x, int y, std::vector<int> (&students)[SIZE]) {
    students[x].push_back(y);
}

void BFS(int x, std::vector<int> (&students)[SIZE]) {

}

int main() {
    int N;
    scanf("%d",&N);
    std::vector<int> students[SIZE];
    int x, y;
    while (scanf("%d %d",&x,&y) != EOF) {
        addEdge(x,y,students);
    }
    BFS(0,students);
    return 0;
}