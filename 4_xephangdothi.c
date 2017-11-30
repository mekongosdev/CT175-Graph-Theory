#include <stdio.h>
#define MAX_VERTICES 100

typedef struct {
    int n;
    int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_Graph(Graph* G, int n) {
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph* G, int x, int y) {
    G->A[x][y] = 1;
}

int adjacent(Graph* G, int x, int y) {
    return G->A[x][y] != 0;
}

int degree(Graph* G, int x) {
    int y, deg = 0;
    for (y = 1; y <= G->n; y++)
        if (G->A[x][y] > 0)
            deg++;
    return deg;
}

#define MAX 100
typedef int ElementType;

typedef struct {
    ElementType data[MAX];
    int size;
} List;

void make_null_list(List *L) {
    L->size=0;
}

void push_back(List *L, ElementType X) {
    L->data[L->size]=X;
    L->size++;
}

ElementType element_at(List *L,int i) {
    return L->data[i-1];
}

int countlist(List *L) {
    return L->size;
}

void copylist(List *S1,List *S2) {
    int i=0;
    make_null_list(S1);
    for(i=1; i<=S2->size; i++)
        push_back(S1, element_at(S2,i));
}


int rank[MAX_VERTICES];
void ranking(Graph* G) {
    int d[MAX_VERTICES];
    int x, u;
    for (u = 1; u <= G->n; u++)
        d[u] = 0;
    for (x = 1; x <= G->n; x++)
        for (u = 1; u <= G->n; u++)
            if (G->A[x][u] != 0) d[u]++;
    List S1, S2;
    make_null_list(&S1);
    for (u = 1; u <= G->n; u++)
        if (d[u] == 0) push_back(&S1, u);
    int k = 1, i;
    while (S1.size > 0) {
        make_null_list(&S2);
        for (i = 1; i <= S1.size; i++) {
            int u = element_at(&S1, i);
            rank[u] = k;
            int v;
            for (v = 1; v <= G->n; v++)
                if (G->A[u][v] != 0) {
                    d[v]--;
                    if (d[v] == 0) push_back(&S2, v);
                }
        }
        copylist(&S1, &S2);
        k++;
    }
}

int main() {
    int m,n,e,u,v,i;
    Graph G;
    freopen("4_xephangdothi_data.inp", "r", stdin);
    scanf("%d%d", &n, &m);
    init_Graph(&G, n);
    for (e = 1; e <= m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    ranking(&G);
    for(e=1; e<=G.n; e++)
        printf("rank[%d]: %d\n", e, rank[e]);
    return 0;
}
