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
	return G->A[x][y] != 0;
}

int degree(Graph *G, int u){
	int i, deg = 0;
	for(i = 1; i <= G->n; i++){
		if(G->A[i][u] == 1) deg++;
	}
	return deg;
}

#define NO_COLOR 0
#define BLUE 1
#define RED 2

int color[MAX_N], conflict;

void colorize(Graph *G, int u, int c){
	
	color[u] = c;
	
	int v;
	for(v = 1; v <= G->n; v++){
		if(adjacent(G, u, v)){
			if(color[v] == NO_COLOR){
				colorize(G, v, 3 - c);
			} else if(color[v] == color[u]){
				conflict = 1;
			}
		}	
	}
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
	
	for(e = 1; e <= n; e++){
		color[e] = NO_COLOR;
	}
	
	conflict = 0;
	
	colorize(&g, 1, BLUE);
	
	if(!conflict){
		for(e = 1; e <= n; e++){
			if(color[e] == BLUE) printf("%d ", e);
		}
		printf("\n");	
		for(e = 1; e <= n; e++){
			if(color[e] == RED) printf("%d ", e);
		}					
	} else {
		printf("IMPOSSIBLE");
	}

	return 0;
}

