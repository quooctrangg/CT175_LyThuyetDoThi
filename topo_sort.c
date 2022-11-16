#include <stdio.h>
#define MAX_N 100
#define MAX_Element 100
#define MAX_Length 500
#define oo 999999

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
}

typedef struct {
	int data[MAX_Element];
	int front, rear;
} Queue;

void make_null_queue(Queue *Q){
	Q->front = 0;
	Q->rear = -1;
}

void enqueue(Queue *Q, int x){
	Q->rear++;
	Q->data[Q->rear] = x;
}

int empty_queue(Queue *Q){
	return Q->front > Q->rear;
}

int front(Queue *Q){
	return Q->data[Q->front];
}

void dequeue(Queue *Q){
	Q->front++;	
}

typedef struct {
	int data[MAX_Length];
	int size;
} List;

void make_null_list(List *list){
	list->size = 0;
}

void push_back(List *list, int x){
	list->data[list->size] = x;
	list->size++;
}

int element_at(List *list, int i){
	return list->data[i-1];
}

void topo_sort(Graph *G, List *L){
	int d[MAX_N], u;

	for(u = 1; u <= G->n; u++){
		d[u] = 0;
		int x;
		for(x = 1; x <= G->n; x++){
			if(G->A[x][u]  != 0)
				d[u]++;
		}
	}
	
	Queue Q;
	make_null_queue(&Q);
	
	for(u = 1; u <= G->n; u++){
		if(d[u] == 0) 
			enqueue(&Q, u);
	}
	
	make_null_list(L);
	
	while(!empty_queue(&Q)){
		
		u = front(&Q);
		dequeue(&Q);
		push_back(L, u);
		
		int v;
		for(v = 1; v <= G->n; v++){
			if(G->A[u][v] != 0){
				d[v]--;
				if(d[v] == 0)
					enqueue(&Q, v);
			}
		}
	}
}

int max(int x, int y){
	if(x > y) return x;
	return y;
}

int min(int x, int y){
	if(x < y) return x;
	return y;
}

int d[MAX_N];

int main(){
	
	freopen("dt1.txt", "r", stdin);
	
	Graph G;
	
	int n, u, v, x ,j;
	scanf("%d", &n);
	init_Graph(&G, n + 2);
	
	int alpha = n + 1, beta = n + 2;
	
	d[alpha] = 0;

	for(u = 1; u <= n; u++){
		scanf("%d", &d[u]);
		do{
			scanf("%d", &x);
			
			if(x > 0)
				add_edge(&G, x ,u);
				
		} while(x > 0);
	}
	
	for(u = 1; u <= n; u++){
		int deg_neg = 0;
		
		for(x = 1; x <= n; x++)
			if(G.A[x][u] > 0)
				deg_neg++;
		
		if(deg_neg == 0)
			add_edge(&G, alpha, u);
	}
	
	for(u = 1; u <= n; u++){
		int deg_pos = 0;
		
		for(v = 1; v <= n; v++)
			if(G.A[u][v] > 0)
				deg_pos++;
		
		if(deg_pos == 0)
			add_edge(&G, u, beta);
	}
	
	List L;
	topo_sort(&G, &L);
	
	int t[MAX_N];
	t[alpha] = 0;
	
	for(j = 2; j <= L.size; j++){
		
		u = element_at(&L, j);
		t[u] = -oo;
		
		for(x = 1; x <= G.n; x++)
			if(G.A[x][u] > 0)
				t[u] = max(t[u], t[x] + d[x]);
	}
	
	int T[MAX_N];
	T[beta] = t[beta];
	
	for(j = L.size - 1; j >= 1; j--){
		
		u = element_at(&L, j);
		T[u] = +oo;
		
		for(v = 1; v <= G.n; v++)
			if(G.A[u][v] > 0)
				T[u] = min(T[u], T[v] - d[u]);
	}
	
	for(j = 1; j <= G.n; j++){
		if(T[j] == t[j]) 
			printf("%d\n", j);
	}

	return 0;
}

