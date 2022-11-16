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

//1.3.4
/*void add_edge(Graph *pG, int x, int y){
	pG->A[x][y] = 1;
	pG->A[y][x] = 1;
	pG->m++;
}*/

//1.3.5
void add_edge(Graph *pG, int x, int y){
	if(x != y){
		pG->A[x][y]++;
		pG->A[y][x]++;
	} 
	else { 
		pG->A[x][x]++; 
	}
	pG->m++;
}

//1.3.6
/*void add_edge(Graph *pG, int x, int y){
	pG->A[x][y]++;
	pG->m++;
}*/

//1.3.7
/*void add_edge(Graph *pG, int x, int y){
	if(pG->A[x][y] == 0 && pG->A[y][x] == 0){
		pG->A[x][y] = 1;
		pG->A[y][x] = 1;
		pG->m++;
	}
}*/

//1.3.11
void printGraph(Graph *pG){
    int i, j;
    printf("\t");
    for (i = 1; i <= pG->n; i++){
        printf("%d\t", i);
    }
    printf("\n\n");
    for( i = 1; i <= pG->n; i++){
        printf("%d\t", i);
        for( j = 1; j <= pG->n; j++){
            printf("%d\t", pG->A[i][j]);
        }
        printf("\n\n");
    } 
}

//1.3.17
int degree(Graph *pG, int x){
	int i, deg = 0;
	for(i = 1; i <= pG->n; i++){
		deg += pG->A[i][x]; 
	}
	deg += pG->A[x][x];
	return deg;
}

//1.3.18
/*int degree(Graph *pG, int x){
	int i, deg = 0;
	for(i = 1; i <= pG->n; i++){
		deg += pG->A[x][i] + pG->A[i][x];
	}
	return deg;
}*/

//1.3.19
int indegree(Graph *pG, int x){
	int i, deg = 0;
	for(i = 1; i <= pG->n; i++){
		deg += pG->A[i][x];
	}
	return deg;
}

//1.3.20
int outdegree(Graph *pG, int x){
	int i, deg = 0;
	for(i = 1; i <= pG->n; i++){
		deg += pG->A[x][i];
	}
	return deg;
}

//1.3.22
void neighbours(Graph *pG, int x){
	int i;
	for(i = 1; i <= pG->n; i++){
		if(pG->A[x][i] > 0 || pG->A[i][x] > 0) printf("%d ", i);
	}
}

//1.3.23
/*void neighbours(Graph *pG, int x){
	int i;
	for(i = 1; i <= pG->n; i++){
		if(pG->A[x][i] > 0) printf("%d ", i);
	}
}*/

int adjacent(Graph *pG, int x, int y){
	if(pG->A[x][y] >0) return 1;
	return 0;
}

int main(){
    Graph g;
    init_graph(&g , 9);
    add_edge(&g, 1, 3);
    add_edge(&g, 1, 5);
    add_edge(&g, 1, 6);
    add_edge(&g, 2, 5);
    add_edge(&g, 2, 6);
    add_edge(&g, 3, 4);
    add_edge(&g, 3, 5);
    add_edge(&g, 5, 6);
    add_edge(&g, 7, 8);

    //printGraph(&g);
   	//printf("%d" , degree(&g, 7));
    //printf("%d" , indegree(&g, 3));
    //printf("%d" , outdegree(&g, 1));
   	//printf("\n%d", adjacent(&g, 3,5));
	neighbours(&g, 5);
    return 0;
}

