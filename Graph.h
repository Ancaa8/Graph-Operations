/*ANDREI anca-Teodora - 313 CC*/
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "Heap.h"

#define MAX 100

typedef int TCost;

typedef struct node
{
    int tip;
	int v;
	TCost c;
	struct node *next;
} TNode, *ATNode;

typedef struct
{
	int nn;
	ATNode *adl;
}	TGraphL;


void alloc_list(TGraphL * G, int n);
void free_list(TGraphL *G);
void insert_edge_list(TGraphL *G, int v1, int v2, int c, int tip);
int Prim(TGraphL G, int start, int *visited);
void dijkstra(TGraphL G, int s, int *depths, int *dist, int *parinti);

#endif