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
