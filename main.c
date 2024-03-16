/*ANDREI anca-Teodora - 313 CC*/
#include <stdio.h>
#include <string.h>

#include "Graph.h"
#include "Heap.h"

#define MAX 100

char *places[MAX];
int size = 0;


int crescator(const void *a, const void *b) {
    int vala = *(int *)a;
    int valb = *(int *)b;

    return vala - valb;
}

int readGraph(FILE *input, TGraphL *g, int n, int m, int tip) {
    for (int k = 0; k < m; k++) {
        char loc[MAX];

        fscanf(input, "%s", loc);

        int sursa = 0;
        int gasit = 0;
        for (int i = 0; i < size && !gasit; i++) {
            if (strcmp(loc, places[i]) == 0) {
                gasit = 1;
            }
            sursa = i;
        }
        if (!gasit) {
            places[size] = strdup(loc);
            sursa = size;
            size++;
        }

        fscanf(input, "%s", loc);
        int dest = 0;
        gasit = 0;
        for (int i = 0; i < size && !gasit; i++) {
            if (strcmp(loc, places[i]) == 0) {
                gasit = 1;
            }
            dest = i;
        }

        if (!gasit) {
            places[size] = strdup(loc);
            dest = size;
            size++;
        }

        int cost = 0;
        fscanf(input, "%d", &cost);
        insert_edge_list(g, sursa, dest, cost, tip);
    }
}

int* readDephts(FILE *input, int n) {
    char nume[MAX];

    int *depths = malloc(n * sizeof(int));
    memset(depths, 0, n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        fscanf(input, "%s", nume);
        int nod = 0;
        int gasit = 0;
        for (int i = 0; i < size && !gasit; i++) {
            nod = i;
            if (strcmp(nume, places[nod]) == 0) {
                gasit = 1;
            }
        }
        
        fscanf(input, "%d", &depths[nod]);
    }
    return depths;
}

int main(int argc, char *argv[]) {
    int noduri = 0, muchii = 0;
    FILE *input = fopen("tema3.in", "r");
    FILE *output = fopen("tema3.out", "w");

    fscanf(input, "%d", &noduri);
    fscanf(input, "%d", &muchii);

    TGraphL G;
    alloc_list(&G, noduri);

    if (argv[1][0] == '1') {
        readGraph(input, &G, noduri, muchii, 0);


        int *visited = malloc(noduri * sizeof(int));
        memset(visited, 0, noduri * sizeof(int));

        int *min = malloc(noduri * sizeof(int));
        memset(min, 0, noduri * sizeof(int));

        int componente = 0;
        for (int i = 0; i < noduri; ++i) {
            if (visited[i] == 0)
                min[componente++] = Prim(G, i, visited);
        }

        qsort(min, componente, sizeof(int), crescator);

        fprintf(output, "%d\n", componente);

        for (int i = 0; i < componente; ++i) {
            fprintf(output, "%d\n", min[i]);
        }

        free(min);
        free(visited);
    } 
    else if (argv[1][0] == '2') {
        readGraph(input, &G, noduri, muchii, 1);
        int *depths = readDephts(input, noduri);

        int sursa = 0;
        int dest = 0;

        int gasit = 0;
        for (int i = 0; i < size && !gasit; i++) {
            sursa = i;
            if (strcmp(places[i], "Corabie") == 0)
                gasit = 1;
        }

        gasit = 0;
        for (int i = 0; i < size && !gasit; i++) {
            dest = i;
            if (strcmp(places[i], "Insula") == 0)
                gasit = 1;
        }

        int *p = calloc(noduri, sizeof(int));
        memset(p, -1, noduri * sizeof(int));

        int *dist = calloc(noduri, sizeof(int));
        dijkstra(G, sursa, depths, dist, p);

        if (dist[dest] != INT_MAX) {
            memset(p, -1, noduri * sizeof(int));
            dijkstra(G, dest, depths, dist, p);

            if (dist[sursa] != INT_MAX) {
                int *path = malloc(noduri * sizeof(int));
                memset(path, 0, noduri * sizeof(int));

                int weight = 0;
                fscanf(input, "%d", &weight);

                int lungime_path = 0;

                int copie_sursa = sursa;
                int minim = INT_MAX;

                while (sursa != -1) {
                    path[lungime_path] = sursa;
                    sursa = p[sursa];
                    lungime_path++;
                }

                sursa = copie_sursa;

                for (int i = 0; i < lungime_path; i++)
                    if (depths[path[i]] < minim && path[i] != sursa && path[i] != dest)
                        minim = depths[path[i]];

                for (int i = lungime_path - 1; i >= 0; --i)
                    fprintf(output, "%s ", places[path[i]]);
                fprintf(output, "\n");

                fprintf(output, "%d\n", dist[sursa]);
                fprintf(output, "%d\n", minim);
                fprintf(output, "%d\n", weight / minim);

                free(path);
            } else fprintf(output, "Echipajul nu poate transporta comoara inapoi la corabie\n");
        } else fprintf(output, "Echipajul nu poate ajunge la insula\n");

        free(depths);
        free(dist);
        free(p);
    }

    free_list(&G);
    for (int i = 0; i < noduri; ++i) 
        free(places[i]);
    fclose(input);
    fclose(output);
    return 0;
}