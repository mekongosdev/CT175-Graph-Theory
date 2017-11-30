#include <stdio.h>
#define MAX_VERTICES 100
#define NO_EDGE 0

typedef struct {
    int n, m;
    int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph* G, int n, int m) {
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            G->A[i][j] = NO_EDGE;
}

void add_edge(Graph* G, int x, int y, int w) {
    G->A[x][y] = w;
    G->A[y][x] = w;
}

int mark[MAX_VERTICES];
#define MAX 100
#define INF 900000
typedef int ElementType;

typedef struct {
    ElementType Data[MAX];
    int Size;
} List;

void make_null_list(List *L) {
    L->Size=0;
}

void push_back(List *L, ElementType X) {
    L->Data[L->Size]=X;
    L->Size++;
}

ElementType element_at(List *L,int i) {
    return L->Data[i-1];
}


int distanceFrom(int u, List* S, Graph* G) {
    int min_dist = INF;
    int min_v = - 1;
    int i;
    for (i = 1; i <= S->Size; i++) {
        int v = element_at(S, i);
        if (G->A[u][v] != 0 && min_dist > G->A[u][v]) {
            min_dist = G->A[u][v];
            min_v = v;
        }
    }
    return min_v;
}

int Prim(Graph* G, Graph* T) {
    init_graph(T, G->n, G->m);
    List S;
    make_null_list(&S);
    int i, u;
    for (i = 1; i <= G->n; i++)
        mark[i] = 0;
    push_back(&S, 1);
    mark[1] = 1;
    int sum_w = 0;
    for (i = 1; i < G->n; i++) {
        int min_dist = INF, min_u, min_v;
        for (u = 1; u <= G->n; u++)
            if (mark[u] == 0) {
                int v = distanceFrom(u, &S, G);
                if (v != -1 && G->A[u][v] < min_dist) {
                    min_dist = G->A[u][v];
                    min_u = u;
                    min_v = v;
                }
            }
        push_back(&S, min_u);
        mark[min_u] = 1;
        add_edge(T, min_u, min_v, min_dist);
        sum_w += min_dist;
    }
    return sum_w;
}

int main() {
    Graph G, T;
    int n, m, u, v, w, e, i, j;
    freopen("5_kruskal_data.inp", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (e = 0; e < m; e++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    int sum = Prim(&G,&T);
    printf("%d\n",sum);
    for (e = 1; e <= T.n; e++) {
        for (v = 1; v <= T.n; v++)
            if(T.A[e][v]>0&&e<v)
                printf("%d %d %d\n",e, v, T.A[e][v]);
    }

    return 0;
}
