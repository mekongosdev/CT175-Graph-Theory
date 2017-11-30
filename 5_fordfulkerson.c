#include <stdio.h>
#define MAXN 100
#define NO_EDGE 0
#define INF 9999999
typedef struct {
    int C[MAXN][MAXN];
    int F[MAXN][MAXN];
    int n;
} Graph;

void init_graph(Graph *G, int n) {
    int i, j;
    G->n = n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G->C[i][j] = 0;
}

void add_edge(Graph* G, int x, int y,int w) {
    G->C[x][y] = w;
}

int min(int a,int b) {
    return a<b?a:b;
}

typedef struct {
    int dir;
    int pre;
    int sigma;
} Label;

Label labels[MAXN];

void init_flow(Graph *G) {
    int u,v;
    for(u=1; u<=G->n; u++)
        for(v=1; v<=G->n; v++)
            G->F[u][v] = 0;
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

void dequeue(Queue* Q) {
    if(!empty_queue(Q)) {
        Q->front++;
        if(Q->front>Q->rear) make_null_queue(Q);
    }
}

void enqueue(Queue *Q, int x) {
    int i;
    if(empty_queue(Q)) Q->front=0;
    if(Q->rear==MAX_ELEMENTS-1) {
        for(i=Q->front; i<=Q->rear; i++)
            Q->data[i-Q->front]=Q->data[i];
        Q->rear=MAX_ELEMENTS-1-Q->front;
        Q->front=0;
    }
    Q->rear=Q->rear+1;
    Q->data[Q->rear]=x;
}

int sum=1;
int FordFullkerson(Graph* G, int s, int t) {
    init_flow(G);
    Queue Q;
    int u,v,sum_flow=0;
    do {
        for (u = 1; u <= G->n; u++)
            labels[u].dir = 0;
        labels[s].dir = 1;
        labels[s].pre = s;
        labels[s].sigma = INF;
        make_null_queue(&Q);
        enqueue(&Q, s);
        int found = 0;
        while (!empty_queue(&Q)) {
            int x = top(&Q);
            dequeue(&Q);
            for (v = 1; v <= G->n; v++) {
                if (labels[v].dir==0 && G->C[x][v]!=NO_EDGE && G->F[x][v] < G->C[x][v]) {
                    labels[v].dir = 1;
                    labels[v].pre = x;
                    labels[v].sigma = min(labels[x].sigma,G->C[x][v] - G->F[x][v]);
                    enqueue(&Q, v);
                }
                if (labels[v].dir == 0 && G->C[v][x] != NO_EDGE && G->F[v][x] > 0) {
                    labels[v].dir = -1;
                    labels[v].pre = x;
                    labels[v].sigma = min(labels[x].sigma,G->F[v][x]);
                    enqueue(&Q, v);
                }
            }
            if (labels[t].dir != 0) {
                found = 1;
                break;
            }
            sum++;
            if(sum==50) break;
        }
        if (found == 1) {
            int x = t;
            int sigma = labels[t].sigma;
            sum_flow += sigma;
            while (x != s) {
                int u = labels[x].pre;
                if (labels[x].dir > 0)
                    G->F[u][x] += sigma;
                else
                    G->F[x][u] -= sigma;
                x = u;
            }
        } else break;
    } while(1);
    return sum_flow;
}

int main() {
    Graph G;
    int n, m, u, v, e, c;
    freopen ("5_fordfulkerson_data.inp", "r", stdin);
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (e = 0; e < m; e++) {
        scanf("%d%d%d", &u, &v, &c);
        G.C[u][v] = c;
    }
    int max_flow = FordFullkerson(&G, 1, n);
    printf("Max flow: %d\n", max_flow);
    return 0;
}
