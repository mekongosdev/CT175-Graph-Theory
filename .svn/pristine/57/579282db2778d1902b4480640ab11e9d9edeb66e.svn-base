#include <stdio.h>
#define MAXN 100
int parent[MAXN];
typedef struct {
    int u, v;
    int w;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAXN];
} Graph;

void init_graph(Graph* G, int n,int m) {
    G->n = n;
    G->m = 0;
}

void add_edge(Graph* G, int u, int v, int w) {
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].w = w;
    G->m++;
}

int findRoot(int u) {
    if (parent[u] = u)
        return u;
    return findRoot(parent[u]);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Kruskal(Graph* G, Graph* T) {
    int e, f, u, v, w, root_u, root_v, sum_w = 0;
    for (e = 0; e < G->m-1; e++)
        for (f = e + 1; f < G->m; f++)
            if(G->edges[e].w > G->edges[f].w) {
                swap(&G->edges[e].w, &G->edges[f].w);
                swap(&G->edges[e].u, &G->edges[f].u);
                swap(&G->edges[e].v, &G->edges[f].v);
            }
    init_graph(T, G->n, G->m);
    for (u = 0; u < G->n; u++)
        parent[u] = u;
    int num_e_of_T = 0;
    for (e = 0; e < G->m; e++) {
        u = G->edges[e].u;
        v = G->edges[e].v;
        w = G->edges[e].w;
        root_u = findRoot(u);
        root_v = findRoot(v);
        if (root_u != root_v) {
            add_edge(T, u, v, w);
            parent[root_v] = root_u;
            sum_w += w;
            num_e_of_T++;
        }
        if(num_e_of_T==G->n-1) break;
    }
    return sum_w;
}

int main() {
    Graph G, T;
    int n, m, u, v, w, e;
    freopen("5_kruskal_data.inp", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (e = 0; e < m; e++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    printf("%d\n", Kruskal(&G, &T));
    for (e = 0; e < T.m; e++) {
        if(T.edges[e].u<T.edges[e].v) {
            printf("%d %d %d\n", T.edges[e].u, T.edges[e].v, T.edges[e].w);
        }
        else if(T.edges[e].u>T.edges[e].v) {
            printf("%d %d %d\n", T.edges[e].v, T.edges[e].u, T.edges[e].w);
        }
    }

    return 0;
}
