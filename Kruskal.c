#include <stdio.h>
#define MAX_M 100

typedef struct {
	int u, v;
	int w;
} Edge;

typedef struct {
	Edge edges[MAX_M];
	int n, m;
} Graph;

void init_Graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}

void add_edge(Graph *G, int u, int v, int w){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m++;
}

int parent[MAX_M];

int findRoot(int u){
	if(parent[u] == u) return u;
	return findRoot(parent[u]);
}

int Kruskal(Graph *G, Graph *T){
	
	int i, j, u, e;
	for(i = 0; i < G->m; i++)
		for(j = i + 1; j < G->m; j++)
			if(G->edges[j].w < G->edges[i].w){
				Edge temp = G->edges[i];
				G->edges[i] = G->edges[j];
				G->edges[j] = temp;
			}
		
	
	init_Graph(T, G->n);
	
	for(u = 1; u <= G->n; u++)
		parent[u] = u;
		
	int sum_w = 0;
	
	for(e = 0; e <= G->m; e++){
		
		int u = G->edges[e].u;
		int v = G->edges[e].v;
		int w = G->edges[e].w;
		
		int root_v = findRoot(v);
		int root_u = findRoot(u);
		
		if(root_u != root_v){
			
			add_edge(T, u, v, w);
			parent[root_v] = root_u;
			sum_w += w;
		}
	}
	return sum_w;
}

int main(){
	
	Graph G, T;
	int n, m, u, v, w, e;
	
	freopen("dt1.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	init_Graph(&G, n);
	
	int sum = 0;
	for(e = 1; e <= m; e++){
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
		sum += w;
	}
	
	int sum_w = Kruskal(&G, &T);
	
	printf("%d\n", sum - sum_w);
	
	return 0;
}
