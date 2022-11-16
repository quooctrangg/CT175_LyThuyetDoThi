#include <stdio.h>
#define MAX_N 100
#define NO_EDGE 0
#define oo 99999

typedef struct {
	int C[MAX_N][MAX_N];
	int F[MAX_N][MAX_N];
	int n;
} Graph;

void init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			G->C[i][j] = 0;
}

void add_edge(Graph *G, int x, int y, int c, int f){
	G->C[x][y] = c;
	G->F[x][y] = f;
}

void init_flow(Graph *G){
	int i, j;
	for(i = 1; i <= G->n; i++)
		for(j = 1; j <= G->n; j++)
			G->F[i][j] = 0;
}

typedef struct {
	int dir, p, sigma;
} Label;

Label labels[MAX_N];

typedef struct {
	int data[MAX_N];
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

int front(Queue *Q){
	return Q->data[Q->front];
}

void dequeue(Queue *Q){
	Q->front++;
}

int empty_queue(Queue *Q){
	return Q->front > Q->rear;
}

int min(int x, int y){
	return x > y ? y : x;
}

int FordFulkerson(Graph *G, int s, int t){
	
	//init_flow(G);
	int max_flow = 0;
	
	Queue Q;
	
	do {
		int u;
		for(u = 1; u <= G->n; u++)
			labels[u].dir = 0;
				
		labels[s].dir = +1;
		labels[s].p = s;
		labels[s].sigma = oo;
			
		make_null_queue(&Q);
		enqueue(&Q, s);
		
		int found = 0;
		while (!empty_queue(&Q)){
			
			int v, x; 
			u = front(&Q);
			dequeue(&Q);
			
			for(v = 1; v <= G->n; v++){
				if(G->C[u][v] != NO_EDGE && labels[v].dir == 0 && G->F[u][v] < G->C[u][v]){
					labels[v].dir = +1;
					labels[v].p = u;
					labels[v].sigma = min(labels[u].sigma, G->C[u][v] - G->F[u][v]);
					enqueue(&Q, v);
				}
			}
			
			for(x = 1; x <= G->n; x++){
				if(G->C[x][u] != NO_EDGE && labels[x].dir == 0 && G->F[x][u] > 0){
					labels[x].dir = -1;
					labels[x].p = u;
					labels[x].sigma = min(labels[u].sigma, G->F[x][u]);
					enqueue(&Q, x);
				}
			}
			
			if(labels[t].dir != 0){
				found = 1;
				break;
			}
		}
		
		if(found == 1){
			int sigma = labels[t].sigma;
				
			int u = t;
			while(u != s){
				int p = labels[u].p;
				if(labels[u].dir > 0)
					G->F[p][u] += sigma;
				else 
					G->F[u][p] -=sigma;
				u = p;
			}
			
			max_flow += sigma;		
		} else 
			break;
	} while (1);
	
	return max_flow;
}

int main(){
	Graph G;
	int n, m, v, e, c, u, f, j, i;
	freopen("dt.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	init_flow(&G);
	int test = 0;
	for(e = 0; e < m; e++){
		scanf("%d%d%d%d", &u, &v, &c, &f);
		add_edge(&G, u, v, c, f);
		if(c < f) test++;
	}
	
	int sum_t = 0;
	for(e = 1; e <= n; e++){
		int temp = 0;
		for(j = 1; j <= n; j++)
			if(G.C[e][j] != 0)
				temp++;
	
		if(temp == 0) i = e;
	}
	
	//printf("%d", i);
	
	for(j = 1; j <= n; j++)
		sum_t += G.F[j][i];
	
	int sum_s = 0;
	for(j = 1; j <= n; j++)
		sum_s += G.F[1][j]; 

	if(sum_t == sum_s && test == 0) printf("YES");
	else printf("NO");
	
	return 0;
}
