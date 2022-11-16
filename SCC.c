#include<stdio.h>

#define MAX_N 20
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
	G->A[x][y]++;
	G->A[y][x]++;
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
	int data[MAX_Element];
	int size;
} Stack;

void make_null_stack(Stack *stack){
	stack->size = 0;
}

void push(Stack *stack, int x){
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

int num[MAX_N], min[MAX_N];
int k = 1;;
Stack S;
int on_stack[MAX_N];

int Min(int u, int v){
	if(u > v) return v;
	return u;
}

void SCC(Graph *G, int u){
	num[u] = k;
	min[u] = k;
	k++;
	 
	push(&S, u);
	on_stack[u] = 1;
	
	int v;
	for(v = 1; v <= G->n; v++){
		if(adjacent(G, u, v)){
			if(num[v] < 0){
				SCC(G, v);
				min[u] = Min(min[u], min[v]);
			} else {
				min[u] = Min(min[u], num[v]);
			}
		}
	}
	
	if(num[u] == min [u]){
		printf("\nTim duoc BPLT manh, %d la dinh khop: ", u);
		int w;
		
		do {
			w = top(&S);
			printf("%d ", w);
			pop(&S);
			on_stack[w] = 0;
		} while (w != u);
	}
}

int main(){
	freopen("dt.txt", "r", stdin);
	
	Graph g;
	int n, m, e, u, v, i;
	scanf("%d%d", &n, &m); 
	init_Graph(&g, n);
	
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&g, u, v);
	}
	
	for(u = 1; u <= g.n; u++){
		num[u] = -1;
	}
	make_null_stack(&S);
	
	SCC(&g, 1);
//	for(u = 1; u <= g.n; u++){
//		if(num[u] == -1){
//			SCC(&g, u);
//		}
//	}
	
	return 0;
}

