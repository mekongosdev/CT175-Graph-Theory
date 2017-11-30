/*
==== MA TRAN DINH DINH ====
*/

#include <stdio.h>
#define MAX_VERTICES 100

/*
////  CAU TRUC LIST  ////
*/
#include "..\List_Queue_Stack\List.c"

/*
////  CAU TRUC GRAPH VO HUONG ////
*/

typedef struct {
    int n;
    int A[MAX_VERTICES][MAX_VERTICES];
}
Graph;

void init_graph(Graph* G, int n) {
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph * G, int x, int y) {
    G->A[x][y] += 1;
    G->A[y][x] += 1;
}

int adjacent(Graph* G, int x, int y) {
    return G->A[x][y] != 0;
}

int degree(Graph* G, int x) {
    int y, deg = 0;
    for (y = 1; y <= G->n; y++)
        deg += G->A[x][y];
    return deg;
}

////  DANH SACH CAC DINH KE  ////
List neighbors(Graph* G, int x) {
    int y;
    List list;
    make_null_list( &list);
    for (y = 1; y <= G->n; y++) {
        if (adjacent(G, x, y))
            push_back( &list, y);
    }
    return list;
}

int main() {
    List list;
    make_null_list( &list);
    Graph G;
    int n, i, u, v, e, m;

    freopen("matranke_data.inp", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);

    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge( &G, u, v);
    }

    //IN RA BAC CUA DINH
    for (i = 1; i <= n; i++)
        printf("deg(%d) = %d\n", i, degree( &G, i));

    //IN RA CAC DINH KE
    for (v = 1; v <= n; v++) {
        List list = neighbors( &G, v);
        printf("Cac dinh ke cua %d: [ ", v);
        for (i = 1; i <= list.size; i++)
            printf("%d ", element_at( &list, i));
        printf("]\n");
    }

    return 0;
}
