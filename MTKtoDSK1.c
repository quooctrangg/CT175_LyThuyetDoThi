#include <stdio.h>
#define MAX_N 100

typedef struct {
	int n, m;
	int A[MAX_N][MAX_N];
} Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
	int u,v;
	for (u = 1; u <= n; u++) {
        for (v = 1; v <= n; v++)
           	pG->A[u][v] = 0;
    }
}

void add_edge(Graph *pG, int u, int v){
	if (u != v){
		pG->A[u][v]++;
		pG->A[v][u]++;
		pG->m++;
	} else 	{
		pG->A[u][u]++;
		pG->m++;	
	
	}	
}

void MTKtoDSK(Graph *pG){
    int u, v; 
   for ( u = 1; u <= pG->n; u++){
       for ( v = 1; v <= pG->n; v++){
           if (pG->A[u][v] != 0){
               while (pG->A[u][v] != 0){
                    printf("%d ", v);
                    pG->A[u][v]--;
               }
           } 
       }
       printf("%d ", 0); 
       printf("\n");
   }
}

int main() {
    Graph G;
    int n;
    
    scanf("%d", &n);
    init_graph(&G, n);

    int e ,k;
    for (e = 1; e <= n; e++){
        for (k = 1; k <= n; k++){
                int tmp = 0;
				scanf("%d", &tmp);
				G.A[e][k] = tmp;
		}
    }
    
    MTKtoDSK(&G);
    	
    return 0;
}
