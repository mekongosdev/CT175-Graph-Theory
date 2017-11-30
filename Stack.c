#define MAX_ELEMENTS 100
typedef struct {
    ElementType data[MAX_ELEMENTS];
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
