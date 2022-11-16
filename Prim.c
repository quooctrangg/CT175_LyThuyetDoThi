#include<stdio.h>
#define MAX_N 100
#define oo 99999
#define NO_EDGE 0
typedef struct {
	int W[MAX_N][MAX_N];
	int n;
} Graph;

void init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			G->W[i][j] = 0; 
	
}

void add_edge(Graph *G, int x, int y, int w){
	G->W[x][y] = w;
	G->W[y][x] = w;
}

int pi[MAX_N], p[MAX_N], mark[MAX_N];

int Prim(Graph *G, Graph *T, int s){
	int i, u, v, x;
	for(u = 1; u <= G->n; u++){
		pi[u] = oo;
		p[u] = -1;
		mark[u] = 0;
	}
	
	pi[s] = 0;

	for(i = 1; i < G->n; i++){
		
		int min_dist = oo;
		for(x = 1; x <= G->n; x++)
			if(mark[x] == 0 && pi[x] < min_dist){
				min_dist = pi[x];
				u = x;
			}
		
		mark[u] = 1;
	
		for(v = 1; v <= G->n; v++)
			if(G->W[u][v] != NO_EDGE)
				if(mark[v] == 0 && pi[v] > G->W[u][v]){
					pi[v] = G->W[u][v];
					p[v] = u;
				}
	}
	
	init_graph(T, G->n);
	int sum = 0;
	
	for(u = 1; u <= G->n; u++)
		if(p[u] != -1){
			int w = G->W[p[u]][u];
			add_edge(T, p[u], u, w);
			sum += (G->W[p[u]][u]);
		}
	return sum;
}

int main(){
	Graph G, T;
	
	freopen("dt1.txt", "r", stdin);
	
	int m, n, i, u, v, w;
	
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for(i = 1; i <= m; i++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);

	}
	
	int sum_w = Prim(&G, &T, 1);
	
	printf("%d", sum_w);
	
	return 0;
}

