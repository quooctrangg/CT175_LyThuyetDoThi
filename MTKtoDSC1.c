#include<stdio.h>
#define MAX_M 500

typedef struct {
	int u, v;
} Edge;

typedef struct {
	Edge edges[MAX_M];
	int m, n;
} Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int x, int y){
	if(x != y){
		int i, count = 1;; 
		for(i = 0; i < pG->m; i++){
			if(pG->edges[i].u == y && pG->edges[i].v == x){
				count = 0;
			}
		}
 		if(count){
 			pG->edges[pG->m].u = x;
 			pG->edges[pG->m].v = y;
 			pG->m++;
		}
	} else {
		pG->edges[pG->m].u = x;
 		pG->edges[pG->m].v = y;
 		pG->m++;
	}
}

int main(){
	Graph g;
	
	//freopen("test.txt", "r", stdin);
	int n, j, i, e;
	scanf("%d", &n);
	init_graph(&g, n);
	int a[n][n];
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(a[i][j] > 0){
				for(e = 0; e < a[i][j]; e++){
					add_edge(&g, i, j);	
				} 	
			}
		}
	}
	
	for(e = 0; e < g.m; e++){
		printf("%d %d\n", g.edges[e].u, g.edges[e].v);
	}
	
	return 0;
}

