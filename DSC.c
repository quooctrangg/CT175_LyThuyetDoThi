#include <stdio.h>

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

//1.2.5
void add_edge(Graph *pG, int x, int y){
 	pG->edges[pG->m].u = x;
 	pG->edges[pG->m].v = y;
 	pG->m++;
}

//1.2.6
/*void add_edge(Graph *pG, int x, int y){
	if(x > 0 && y > 0 && x < pG->n && y < pG->n){
		pG->edges[pG->m].u = x;
 		pG->edges[pG->m].v = y;
 		pG->m++;
	}
}*/

//1.2.7
/*void add_edge(Graph *pG, int x, int y){
	int i, count = 1;
	for(i = 0; i < pG->m; i++){
		if(x == pG->edges[i].u && y == pG->edges[i].v) count = 0;
	}
	if(count){
		pG->edges[pG->m].u = x;
 		pG->edges[pG->m].v = y;
 		pG->m++;
	}
}*/

//1.2.8
/*void add_edge(Graph *pG, int x, int y){
	int i, count = 1;
	for(i = 0; i < pG->m; i++){
		if(x == pG->edges[i].u && y == pG->edges[i].v) count = 0;
		if(x == pG->edges[i].v && y == pG->edges[i].u) count = 0;
	}
	if(count){
		pG->edges[pG->m].u = x;
 		pG->edges[pG->m].v = y;
 		pG->m++;
	}
}*/

//1.2.10
int degree(Graph *pG, int x){
	int i, deg = 0;
	for(i = 0; i < pG->m; i++){
		if(pG->edges[i].u == x) deg++;
		if(pG->edges[i].v == x) deg++;
	}
	return deg;
}

//1.2.11
/*int degree(Graph *pG, int x){
	int i, deg = 0;
	for(i = 0; i < pG->m; i++){
		if(pG->edges[i].u == x) deg++;
	}
	return deg;
}*/

//1.2.19
void neighbours(Graph* pG, int x){
    int i;
    for (i = 0;i < pG->m; i++){
        if (pG->edges[i].u == x){
            printf("%d ",  pG->edges[i].v);
        }
        if(pG->edges[i].v == x){
        	printf("%d ",  pG->edges[i].u);
		}
    }
}

//1.2.20
/*void neighbours(Graph* pG, int x){
    int i;
    for (i = 0;i < pG->m; i++){
        if (pG->edges[i].u == x){
            printf("%d ",  pG->edges[i].v);
        }
    }
}*/


int adjacent(Graph *pG, int x, int y){
	int i;
	for(i = 0; i < pG->m; i++){
		if(pG->edges[i].u == x && pG->edges[i].v == y || pG->edges[i].u == y && pG->edges[i].v == x) return 1;
	}
	return 0;
}


int main(){
	
	Graph g;
    init_graph(&g, 9);

    add_edge(&g, 1, 3);
    add_edge(&g,3,4);
    add_edge(&g,3,5);
    add_edge(&g,1,5);
    add_edge(&g,1,6);
    add_edge(&g,5,6);
    add_edge(&g,2,5);
    add_edge(&g,2,6);

    //printf("\n%d", degree(&g, 5));
    
    //printf("\n%d\n", adjacent(&g, 5,5));
    
    //neighbours(&g, 2);

	//printf("%d", g.m);
	
	return 0;
}


