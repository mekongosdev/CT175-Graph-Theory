#include <stdio.h>
#define MAX_VERTICES 100

typedef struct {
    int n;
    int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

void init_graph(Graph* G, int n) {
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

//THEM CUNG TRONG TRUONG HOP DO THI CO HUONG TU X DEN Y
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

#define MAX_ELEMENTS 100
typedef struct {
    int data[MAX_ELEMENTS];
    int front,rear;
} Queue;

void make_null_queue(Queue *Q) {
    Q->front=0;
    Q->rear=-1;
}

void push(Queue *Q, int x) {
    Q->rear++;
    Q->data[Q->rear]=x;
}

int top(Queue *Q) {
    return Q->data[Q->front];
}

void pop(Queue *Q) {
    Q->front++;
}

int empty_queue(Queue *Q) {
    return Q->rear < Q->front;
}

void topo_sort(Graph *G,List *L) {
    make_null_list(L);
    Queue Q;
    make_null_queue(&Q);
    int d[MAX_VERTICES];
    int x, u;
    for (u = 1; u <= G->n; u++)
        d[u] = 0;
    for (x = 1; x <= G->n; x++)
        for (u = 1; u <= G->n; u++)
            if (G->A[x][u] != 0) d[u]++;
    for (u = 1; u <= G->n; u++)
        if (d[u] == 0) push(&Q,u);
    while(!empty_queue(&Q)) {
        u=top(&Q);
        pop(&Q);
        push_back(L,u);
        for (x = 1; x <= G->n; x++)
            if(adjacent(G,u,x)) {
                d[x]--;
                if(d[x]==0) push(&Q,x);
            }
    }
}

int main() {
    int m,n,e,u,v;
    Graph G;
    List L;
    freopen("4_xephangtopo_data.inp", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 1; e <= m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    topo_sort(&G,&L);
    printf("Thu tu topo la: ");
    for(e=1; e<=L.size; e++)
        printf("%d ",element_at(&L,e));
    return 0;
}
