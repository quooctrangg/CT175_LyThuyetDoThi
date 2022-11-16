#include<stdio.h>
#define MAX_N 100
#define MAX_M 500

typedef struct {
	int A[MAX_N][MAX_M];
	int m, n;
} Graph;

void init_graph(Graph *pG, int n, int m){
	int i, j;
	pG->m = m;
	pG->n = n;
	for(i = 1; i <= n; i++){
		for(j = 1; j < m; j++){
			pG->A[i][j] = 0;
		}
	}
}

//1.6.6
void add_edge(Graph* pG, int e, int x, int y){
        pG->A[x][e]++;
        pG->A[y][e]++; 
}

int degree(Graph *pG, int x){
	int i, deg = 0;
	for(i = 1; i <= pG->m; i++){
		if(pG->A[x][i] > 0) deg += pG->A[x][i];
	}
	return deg;
}

int adjacent(Graph *pG, int x, int y){
	int i;
	for(i = 1; i < pG->m; i++){
		if(pG->A[x][i] > 0 && pG->A[y][i] > 0) return 1;
	}
	return 0;
}

void neighbours(Graph* pG, int x){
    int i, j;
    for(i = 1; i <= pG->m; i++){
        for(j = 1; j <= pG->n ; j++){
            if(j != x){
                if(pG->A[j][i] == 1 && pG->A[x][i] == 1){
                    printf("%d ", j);
                } 
            }   
        }  
    }
}

void printGraph(Graph *pG){
    int i, j;
    printf("\t");
    for ( i = 1; i <= pG->m; i++){
        printf("e%d\t", i);
    }
    printf("\n\n");
    for ( i = 1; i <= pG->n; i++){
        printf("%d\t", i);
        for ( j = 1; j <= pG->m ; j++){
            printf("%d\t", pG->A[i][j]);
        }
        printf("\n\n");
    }
    
}

int main(){
	
	Graph g;
	
	init_graph(&g, 7, 9);
	
	add_edge(&g, 1, 1, 2);
	add_edge(&g, 2, 1, 3);
	add_edge(&g, 3, 3, 1);
	add_edge(&g, 4, 3, 6);
	add_edge(&g, 5, 1, 4);
	add_edge(&g, 6, 3, 4);
	add_edge(&g, 7, 5, 6);
	add_edge(&g, 8, 6, 5);
	add_edge(&g, 9, 4, 5);
	
	printGraph(&g);
	//printf("%d\n", degree(&g, 4));
	//printf("%d\n", adjacent(&g, 2, 1));
	//neighbours(&g, 4);
	
	return 0;
}









