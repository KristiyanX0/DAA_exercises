#include<iostream>
#include<vector>
#define SIZE 100

int n,m;
int graph[SIZE][SIZE] = { { 0, 5, INT32_MAX, 10 },
                          { INT32_MAX, 0, 3, INT32_MAX },
                          { INT32_MAX, INT32_MAX, 0, 1 },
                          { INT32_MAX, INT32_MAX, INT32_MAX, 0 } };
    

void init() {
    int from,to,weight;
    scanf("%d %d",&n,&m);
    for (size_t i=0;i<m;++i) {
        scanf("%d %d %d",&from,&to,&weight);
        graph[from][to];
    }
}

void FloydWarshall() {
    int dist[SIZE][SIZE];
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            dist[i][j]=graph[i][j];
    
     for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INT32_MAX
                    && dist[i][k] != INT32_MAX))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT32_MAX)
                printf("INF\t");
            else
                printf("%d\t",dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[SIZE][SIZE] = { { 0, 5, INT32_MAX, 10 },
                            { INT32_MAX, 0, 3, INT32_MAX },
                            { INT32_MAX, INT32_MAX, 0, 1 },
                            { INT32_MAX, INT32_MAX, INT32_MAX, 0 } };
    return 0;
}