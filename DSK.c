#include<stdio.h>

#define MAX_N 100
#define MAX_M 500

typedef struct {
	int data[MAX_N];
	int size;
} List;

typedef struct {
	List adj[MAX_N];
	int n, m;
} Graph;

void make_null(List* pL){
    pL->size = 1;
}

void push_back(List* pL, int x){
    pL->data[pL->size] = x;
    pL->size++;
} 

int element_at(List* pL, int p){
    return pL->data[p-1];
}

int size(List* pL){
    return pL->size;
}


void init_graph(Graph *pG, int n, int m){
	pG->n = n;
	pG->m = m;
	int i;
	for(i = 1; i <= n; i++){
		make_null(&pG->adj[i]);
	}
} 	

//1.4.7
/*void add_edge(Graph *pG, int x, int y){
	int i, count = 1;
	for(i = 1; i <= pG->adj[x].size; i++){
		if(pG->adj[x].data[i] == y) count = 0;
	}
	if(count){
		push_back(&pG->adj[x], y);
		push_back(&pG->adj[y], x);
	}
}*/

/*void add_edge(Graph *pG, int x, int y){
	push_back(&pG->adj[x], y);
	push_back(&pG->adj[y], x);
}*/

void add_edge(Graph *pG, int x, int y){
	push_back(&pG->adj[x], y);
}

int degree(Graph *pG, int x){
	return pG->adj[x].size;
}


int adjacent(Graph *pG, int x, int y){
	int i;
	for(i = 1; i <= pG->adj[x].size; i++){
		if(element_at(&pG->adj[x], i) == y) return 1;
	}
	return 0;
}

void neighbours(Graph *pG, int x){
   	int i;
	for (i = 1; i < pG->adj[x].size; i++){
        printf("%d ", pG->adj[x].data[i]);
    }
}

void printGraph(Graph *pG){
    int i,j;
    for(i = 1; i <= pG->n; i++){
    	printf("adj[%d]: ", i);
        for(j = 1; j < pG->adj[i].size; j++){
            printf("%d\t",  pG->adj[i].data[j]);
        }
        printf("\n\n");
    }
}


int main(){
	Graph g;
	init_graph(&g, 9, 9);
	add_edge(&g, 1, 3);
	add_edge(&g, 1, 5);
	add_edge(&g, 1, 6);
	add_edge(&g, 2, 5);
	add_edge(&g, 2, 6);
	add_edge(&g, 3, 5);
	add_edge(&g, 3, 4);
	add_edge(&g, 7, 8);
	add_edge(&g, 5, 6);
	add_edge(&g, 5, 5);
	
	//printGraph(&g);
	//printf("%d", degree(&g, 5));
	//printf("%d ", adjacent(&g, 6, 6));
	//neighbours(&g, 5);
	
	return 0;
}
