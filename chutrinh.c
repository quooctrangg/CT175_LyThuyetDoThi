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
	//G->A[y][x]++;
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

#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[MAX_N], has_circle;

void DFS(Graph *G, int u){
	color[u] = GRAY;
	int v;
	for(v = 1; v <= G->n; v++){
		if(adjacent(G, u, v)){
			if(color[v] == WHITE)
				DFS(G, v);
			else if(color[v] == GRAY)
				has_circle = 1;
		}
	}
	color[u] = BLACK;
}

int main(){
	freopen("dt1.txt", "r", stdin);
	
	Graph g;
	int n, m, e, u, v;
	scanf("%d%d", &n, &m); 
	init_Graph(&g, n);
	
	for(e = 1; e <= m; e++){
		scanf("%d%d", &u, &v);
		add_edge(&g, u, v);
	}
	
	for(e = 1; e <= m; e++){
		color[e] = WHITE;
	}
	
	has_circle = 0;
	
	for(e = 1; e <= m; e++){
		if(color[e] == WHITE){
			DFS(&g, e);
		}
	}
	
	if(has_circle){
		printf("NO");
	} else {
		printf("YES");
	}

	return 0;
}

