#include <stdio.h>
#define MAX_VERTICES 50
#define MAX_EDGES 50
#define NO_EDGE -1
typedef struct {
    int n, m;
    int A[MAX_VERTICES][MAX_EDGES];
} Graph;


void init_graph(Graph* G, int n, int m) {
    int i, j;
    G->n = n;
    G->m = m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            G->A[i][j] = NO_EDGE;
}


void add_edge(Graph* G, int x, int y, int w) {
    G->A[x][y] = w;
}

//VO HUONG
/*

void add_edge(Graph* G, int x, int y, int w) {
    G->A[x][y] = w;
    G->A[y][x] = w;
}

 */

#define INFINITY 9999999
int mark[MAX_VERTICES];
int pi[MAX_VERTICES];
int p[MAX_VERTICES];

void Dijkstra(Graph* G, int s) {
    int i, j, it;
    for (i = 1; i <= G->n; i++) {
        pi[i] = INFINITY;
        mark[i] = 0;
    }
    pi[s] = 0;
    p[s] = -1;
    for (it = 1; it < G->n; it++) {
        int min_pi = INFINITY;
        for (j = 1; j <= G->n; j++)
            if (mark[j] == 0 && pi[j] < min_pi) {
                min_pi = pi[j];
                i = j;
            }
        mark[i] = 1;

        for (j = 1; j <= G->n; j++)
            if (G->A[i][j] != NO_EDGE && mark[j] == 0) {
                if (pi[i] + G->A[i][j] < pi[j]) {
                    pi[j] = pi[i] + G->A[i][j];
                    p[j] = i;
                }
            }
    }
}

int main() {
    Graph G;
    int n, m, u, v, e, w, i;
    freopen("3_dijkstra_cohuong_data.inp", "r", stdin); //nop bai bo dong nay di
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (e = 1; e <= m; e++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G,u,v,w);
    }

    Dijkstra(&G, 1);
    if(pi[n]>0) {
        printf("%d\n", pi[n]);
    }
    else printf("-1");
    for (i = 1; i <= G.n; i++)
        printf("pi[%d] = %d, p[%d] = %d\n", i, pi[i], i, p[i]);

    return 0;
}
