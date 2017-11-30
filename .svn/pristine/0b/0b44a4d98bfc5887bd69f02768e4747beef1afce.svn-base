#include <stdio.h>
#define MAX_ELEMENTS 100
#define MAX_VERTICLES 100
#define MAX_EDGES 400
typedef int ElementType;
typedef struct {
    ElementType data[MAX_ELEMENTS];
    int size;
}List; //create empty list
void make_null(List * L) {
        L->size = 0;
    } //add element in the last List
void push_back(List * L, ElementType x) {
        L->data[L->size] = x;
        L->size++;
    } //get value of element at i position
ElementType element_at(List * L, int i) {
        return L->data[i - 1];
    } //Count number of element in the List
int count_element(List * L) {
    return L->size;
} /* === GRAPH === */
typedef struct {
    int n, m; // n: so dinh, m: so cung
    int A[MAX_VERTICLES][MAX_EDGES];
}
Graph;
void init_graph(Graph * G, int n, int m) {
    G->n = n;
    G->m = m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            G->A[i][j] = 0;
        }
    }
}
void add_edge(Graph * G, int e, int x, int y) {
    G->A[x][e] += 1;
    G->A[y][e] += 1;
}
List neighbors(Graph * G, int x) {
    List L;
    make_null( & L);
    for (int i = 1; i <= G->n; ++i) {
        if (i == x) {
            continue;
        }
        for (int j = 1; j <= G->m; ++j) {
            if ((G->A[x][j] == 1) && (G->A[i][j] == 1)) {
                push_back( & L, i);
                break;
            }
        }
    }
    return L;
}
int mark[MAX_VERTICLES];
void traversal(Graph * G, int x) {
    if (mark[x] == 1) {
        return;
    }
    mark[x] = 1;
    List list = neighbors(G, x);
    for (int i = 1; i <= list.size; ++i) {
        int temp = element_at( & list, i);
        traversal(G, temp);
    }
}
int isHarvestPossible(Graph * G) {
    for (int i = 1; i <= G->n; ++i) {
        mark[i] = 0;
    }
    traversal(G, 1);
    for (int j = 1; j <= G->n; ++j) {
        if (mark[j] == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    Graph G;
    int n, m, u, v, e;
    freopen("2_traversal_data.inp", "r", stdin);
    scanf("%d%d", & n, & m);
    init_graph( & G, n, m);
    for (e = 1; e <= m; e++) {
        scanf("%d%d", & u, & v);
        add_edge( & G, e, u, v);
    }
    if (isHarvestPossible( & G)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
