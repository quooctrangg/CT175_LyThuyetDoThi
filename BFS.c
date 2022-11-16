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
	int front, rear;
} Queue;

void make_null_Queue(Queue *Q){
	Q->front = 0;
	Q->rear = -1;
}

void push_Queue(Queue *Q, int x){
	Q->rear++;
	Q->data[Q->rear] = x;
}

int empty_Queue(Queue *Q){
	return Q->front > Q->rear;
}

int top(Queue *Q){
	return Q->data[Q->front];
}

void pop(Queue *Q){
	Q->front++;	
}

void breath_first_search(Graph *G){
	Queue Q;
	make_null_Queue(&Q);
	int mark[MAX_N];
	int i;
	for(i = 1; i <= G->n; i++){
		mark[i] = 0;
	}
	push_Queue(&Q, 1);
	while(!empty_Queue(&Q)){
		int u = top(&Q);
		pop(&Q);
		if(mark[u] == 1) continue;
		printf("Duyet: %d\n", u);
		mark[u] = 1;
		List L;
		make_null(&L);
		L = neighbors(G, u);
		int v;
		for(i = 1; i <= L.size; i++){
			v = element_at(&L, i);
			if(mark[v] == 0) push_Queue(&Q, v);
		}
	}
}

int main(){
	
	freopen("BFS1.txt", "r", stdin);
	
	Graph g;
	
	int n, m, e, u, v, i;
	
	scanf("%d%d", &n, &m); 
	init_Graph(&g, n);
	
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&g, u, v);
	}
	
	breath_first_search(&g);
	
	return 0;
}

