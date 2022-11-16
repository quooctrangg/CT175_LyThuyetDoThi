#define MAX_M 100

typedef struct {
	int u, v;
	int w;
} Edge;

typedef struct {
	int n, m;
	Edge edges[MAX_M];
} Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
}

void add_edge(Graph *pG, int x, int y, int w){
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->edges[pG->m].w = w;
	pG->m++;
}

#define oo 9999

int pi[MAX_M], p[MAX_M];
int negative_cycle;

void BellmanFord(Graph *G, int s){
	int u, v, w, it, k;
	
	for(u = 1; u <= G->n; u++){
		pi[u] = oo;
	}
	
	pi[s] = 0;
	p[s] = -1;
	
	for(it = 1; it <= G->n; it++){
		for(k = 0; k <= G->m; k++){
			u = G->edges[k].u;
			v = G->edges[k].v;
			w = G->edges[k].w;
			if(pi[u]== oo) continue;
			if(pi[u] + w < pi[v]){
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
	
	for(k = 0; k < G->m; k++){
		u = G->edges[k].u;
		v = G->edges[k].v;
		w = G->edges[k].w; 
		if(pi[u] + w < pi[v]){
			negative_cycle = 1;
			break;	
		}
	}
}

int main(){
	
	
	
	return 0;
}
