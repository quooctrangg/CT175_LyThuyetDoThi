#include<stdio.h>

#define MAX_N 20
#define MAX_Length 20
#define MAX_Element 40

typedef struct {
	int A[MAX_N][MAX_N];
	int n;
} Graph;

void init_Graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			G->A[i][j] = 0;
		}
	}
}

void add_edge(Graph *G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}

int adjacent(Graph *G, int x, int y){
	return G->A[x][y] > 0;
}

int degree(Graph *G, int u){
	int i, deg = 0;
	for(i = 1; i <= G->n; i++){
		if(G->A[i][u] == 1) deg++;
	}
	return deg;
}

void print_Graph(Graph *g){
	int i, j;
	for(i = 1; i <= g->n; i++){
		for(j = 1; j <= g->n; j++){
			printf("%d ", g->A[i][j]);
		}
		printf("\n");
	}
}

typedef struct {
	int data[MAX_Length];
	int size;
} List;

void make_null(List *list){
	list->size = 0;
}

void push_back(List *list, int x){
	list->data[list->size] = x;
	list->size++;
}

int element_at(List *list, int i){
	return list->data[i-1];
}

List neighbors(Graph *G, int x){
	List L;
	make_null(&L);
	int i;
	for(i = 1; i <= G->n; i++){
		if(G->A[i][x] == 1){
			push_back(&L, i);
		}
	}
	return L;
}

typedef struct {
	int data[MAX_Element];
	int size;
} Stack;

void make_null_stack(Stack *stack){
	stack->size = 0;
}

void push_stack(Stack *stack, int x){
	stack->data[stack->size] = x;
	stack->size++;
}

int top(Stack *stack){
	return stack->data[stack->size - 1];
}

void pop(Stack *stack){
	stack->size--;
}

int empty(Stack *stack){
	return stack->size == 0;
}

void depth_first_search(Graph *G, int x){
	Stack S;
	make_null_stack(&S);
	push_stack(&S, x);
	int mark[MAX_N];
	int i, j;
	for(i = 1; i <= G->n; i++){
		mark[i] = 0;
	}
	while(!empty(&S)){
		int u = top(&S);
		pop(&S);
		if(mark[u] == 1){
			continue;
		}
		printf("Duyet: %d\n", u);
		mark[u] = 1;
		List list = neighbors(G, u);
		for(i = 1; i <= list.size; i++){
			int v = element_at(&list, i);
			if(mark[v]  == 0) push_stack(&S, v);
		}
	}
}

int main(){
	
	freopen("DFS1.txt", "r", stdin);
	
	Graph g;
	
	int n, m, e, u, v;
	
	scanf("%d%d", &n, &m); 
	init_Graph(&g, n);
	
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&g, u, v);
	}
	
	
	depth_first_search(&g, 1);

	
	return 0;
}
