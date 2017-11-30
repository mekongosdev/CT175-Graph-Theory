#include <stdio.h>
#define MAX_ELEMENTS 100
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
    Element_Type data[MAX_ELEMENTS];
    int size;
} Stack;

void make_null_stack(Stack *S) {
    S->size=0;
}

int empty_stack(Stack *S) {
    return S->size==0;
}

Element_Type top(Stack *S) {
    return S->data[S->size -1];
}

void pop(Stack *S) {
    S->size--;
}

void push(Stack *S, Element_Type x) {
    S->data[S->size] =x;
    S->size++;
}

#define MAX_VERTICES 100
typedef struct {
    int n;
    List adj[MAX_VERTICES];
} Graph;

void init_graph(Graph *G, int n) {
    G->n = n;
    int i;
    for(i=1; i<=n; i++)
        make_null_list(&G->adj[i]);
}

void add_edge(Graph *G, int x, int y) {
    push_back(&G->adj[x], y);
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

int min(int a,int b) {
    return a<b?a:b;
}

int num[MAX_VERTICES];
int min_num[MAX_VERTICES];
int on_stack[MAX_VERTICES];
void strong_connect(Graph* G, int x, int idx, Stack S) {
    int j;
    num[x] = min_num[x] = idx;
    idx++;
    push(&S, x); /* �ua x v�o stack */
    on_stack[x] = 1; /* x dang ? tr�n stack */
    /* L?y c�c d?nh k? v� duy?t n� */
    List list = neighbors(G, x);
    for (j = list.size; j > 0; j--) {
        int y = element_at(&list, j);
        if (num[y] == -1) {
            strong_connect(G, y, idx, S);
            min_num [x] = min(min_num[x], min_num[y]);
        } else if (on_stack[y]) {
            min_num[x] = min(min_num[x], num[y]);
        }
    }
//	printf("min_num[%d] = %d || ", x, min_num[x]);
//	printf("num[%d] = %d\n", x, num[x]);
    if (num[x] == min_num[x]) {
        printf("%d la dinh khop.\n", x);
        int w;
        do {
            w = top(&S);
            pop(&S);
            on_stack[w] = 0;
        } while (w != x);
    }

}
int main() {
    Graph G;
    int n,i, u,v;
    freopen("2_tarjan_data.inp","r", stdin);
    scanf("%d",&n);
    init_graph(&G,n);
    for(i = 0; i < G.n; i++){
        scanf("%d%d",&u,&v);
        add_edge(&G,u,v);
    }
    for (v = 1; v <= n; v++) {
        num[v] = -1;
        on_stack[v] = 0;
    }
    Stack S;
    int idx = 1;
    make_null_stack(&S);
    for (v = 1; v <= n; v++) {
        if (num[v] == -1)
            strong_connect(&G, v, idx, S);
    }
    return 0;
}
