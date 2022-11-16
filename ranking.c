#include <stdio.h>
#define MAX_N 100
#define MAX_Length 500
#define MAX_VERTICES 100

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

void copy_list(List *S1, List *S2){
	int i;
	make_null_list(S1);
	for(i = 0; i < S2->size; i++){	
		push_back(S1, S2->data[i]);
	}
}

int rank[MAX_VERTICES];

void ranking(Graph *G){
	
	int d[MAX_VERTICES];
	
	int x, u;
	for(u = 1; u <= G->n; u++){
		d[u] = 0;
	}
		
	for(x = 1; x <= G->n; x++){
		for(u = 1; u <= G->n; u++){
			if(G->A[x][u] > 0){
				d[u]++;
			}
		}	
	}
		
				
	List S1, S2;
	make_null_list(&S1);
	
	for(u = 1; u <= G->n; u++){
		if(d[u] == 0){
			push_back(&S1, u);
		}
	}
			
	int k = 0, i;
	while(S1.size > 0){
		
		make_null_list(&S2);
		
		for(i = 1; i <= S1.size; i++){
			
			u = element_at(&S1, i);
			rank[u] = k;
			
			int v;
			for(v = 1; v <= G->n; v++)
				if(G->A[u][v] != 0){
					d[v]--;
					if(d[v] == 0){
						push_back(&S2, v);
					}	
				}
		}
		
		copy_list(&S1, &S2);
		k++;
		
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
		rank[e] = 0;
	}
	
	ranking(&g);
	for(e = 1; e <= n; e++){
		printf("%d ", rank[e]);
	};

	
	return 0;
}

