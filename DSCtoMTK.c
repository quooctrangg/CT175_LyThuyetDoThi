#include <stdio.h>

#define MAX_N 100

typedef struct {
	int A[MAX_N][MAX_N];
	int n, m;
} Graph;

void init_graph(Graph *pG, int n){
	pG->n = n;
	pG->m = 0;
	int i, j;
	for(i = 1; i <= pG->n; i++){
		for(j = 1; j <= pG->n; j++){
			pG->A[i][j] =0;
		}
	}
}

void add_edge(Graph *pG, int x, int y){
	if(x != y){
		pG->A[x][y]++;
		//pG->A[y][x]++;
	} else {
		pG->A[x][x]++;
	}
}

void printGraph(Graph *pG){
    int i, j;
    for( i = 1; i <= pG->n; i++){
        for( j = 1; j <= pG->n; j++){
            printf("%d ", pG->A[i][j]);
        }
        printf("\n");
    } 
}

int main(){
	freopen("dt1.txt", "r", stdin);
	int n, i;
	scanf("%d",&n);
	Graph g;
	init_graph(&g, n);
	for(i = 1; i <= n; i++){
		int j;
		do {
			scanf("%d", &j);
			add_edge(&g, i, j);
		} while(j != 0);
	}
	
	printGraph(&g);
	
    return 0;
}

