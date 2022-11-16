#include <stdio.h>

#define MAX_N 100
#define NO_EDGE 0
#define oo 999999

typedef struct {
	int n, m;
	int W[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
	int i, j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			pG->W[i][j] = NO_EDGE;
}

void add_edge(Graph *pG, int x, int y, int w){
	pG->W[x][y] = w;
	pG->W[y][x] = w;
	pG->m++;
}

int mark[MAX_N];
int pi[MAX_N];
int p[MAX_N];

void MooreDijkstra(Graph *G, int s){
	int u, v, it;
	for(u = 1; u <= G->n; u++){
		pi[u] = oo;
		mark[u] = 0;	
	}
	
	pi[s] = 0;
	p[s] = -1;
	
	for(it = 1; it < G->n; it++){
		int j, min_pi = oo;
		for(j = 1; j <= G->n; j++)
			if(mark[j] == 0 && pi[j] < min_pi){
				min_pi = pi[j];
				u = j;
			}
		
		mark[u] = 1;
		
		for(v = 1; v <= G->n; v++)
			if(G->W[u][v] != NO_EDGE && mark[v] == 0)
				if(pi[u] + G->W[u][v] < pi[v]){
					pi[v] = pi[u] + G->W[u][v];
					p[v] = u;
				}
	}
}

void printGraph(Graph *G){
	int i, j;
	for(i = 1; i <= G->n; i++){
		for(j = 1; j <= G->n; j++){
			printf("%d\t", G->W[i][j]);
		}
		printf("\n\n");
	}
}

int main(){
	
 	freopen("dt1.txt", "r", stdin);
    Graph G;
    int n, m, u, v, w, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for (e = 0; e < m; e++) {
        scanf("%d%d%d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }
    
    //printGraph(&G);
	
	MooreDijkstra(&G, 1);
	
	for(u = 1; u <= G.n; u++){
		printf("pi[%d] = %d, p[%d] = %d\n", u, pi[u], u, p[u]);
	}
	
	
	
	return 0;
}
