#include <stdio.h>
#define MAX_ELEMENTS 100
#define white 0
#define black 1
#define gray 2
#define MAX_VERTICES 100
int color[MAX_VERTICES];
int cycle;
typedef int Element_Type;

typedef struct {
    Element_Type data[MAX_ELEMENTS];
    int size;
} List;

void make_null_list(List *L) {
    L->size=0;
}

void push_back(List *L, Element_Type x) {
    L->data[L->size]=x;
    L->size++;
}

Element_Type element_at(List *L, int i) {
    return L->data[i-1];
}

int count_list(List *L) {
    return L->size;
}

typedef struct {
    int n;
    List adj[MAX_VERTICES];
} Graph;

void init_graph(Graph *G, int n) {
    G->n=n;
    int i;
    for(i=1; i<=n; i++)
        make_null_list(&G->adj[i]);
}

void add_edge(Graph *G, int x, int y) {
    push_back(&G->adj[x], y);
    push_back(&G->adj[y], x);
}

int adjacent(Graph *G, int x, int y) {
    int i;
    for(i=1; i<=G->adj[x].size; i++)
        if(element_at(&G->adj[x],i) == y)
            return 1;
    return 0;
}

int degree(Graph *G, int x) {
    return G->adj[x].size;
}
List neighbors(Graph *G, int x) {
    List L;
    make_null_list(&L);
    int y;
    for(y=1 ; y<=G->n; y++)
        if(adjacent(G,x,y) ) push_back(&L, y);
    return L;

}

void dfs(Graph* G, int x, int parent) {
    color[x] = gray;
    int j;
    List list = neighbors(G, x);
    for (j = 1; j <= list.size; j++) {
        int y = element_at(&list, j);
        if (y == parent) continue;
        if (color[y] == gray) {
            cycle = 1;
            return;
        }
        if (color[y] == white)
            dfs(G, y, x);
    }
    color[x] = black;
}

int contains_cycle(Graph* G) {
    int j;
    for (j = 1; j <= G->n; j++) {
        color[j] = white;
    }
    cycle = 0;
    for (j = 1; j <= G->n; j++) {
        if (color[j] == white)
            dfs(G, j, 0);
    }
    return cycle;
}

int main() {
    Graph G;
    int n,u,v,y,m,e;
    freopen("2_dothivohuong_ktrachutrinh.inp","r", stdin);
    scanf("%d%d",&n, &m);
    init_graph(&G,n);

    for (e = 0; e < m; e++) {
        scanf("%d%d",&u,&v);
        add_edge(&G,u,v);
    }

    for (v = 1; v <= n; v++) {
        List list = neighbors(&G, v);
        printf("Cac dinh ke cua %d: [ ", v);
        for (y = 1; y <= list.size; y++)
            printf("%d ", element_at(&list, y));
        printf("]\n");
    }

    if(contains_cycle(&G)) {
        printf("\nDo thi co chua chu trinh!");
    }
    else {
        printf("\nDo thi khong chua chu trinh!\n");
    }

}
