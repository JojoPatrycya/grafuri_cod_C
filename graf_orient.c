#include <stdio.h>
#include <stdlib.h>
#include "graf_orient.h"
#include <limits.h>
#include <stdbool.h>

#define MAX 100

void Initializare(Graf *g) {
    g->nr_noduri = 0;
}

void InsertNod(Graf *g, Nod n) {
    int index_nod = g->nr_noduri;
    g->Noduri[index_nod] = n;
    g->nr_noduri++;
    for (int i = 0; i < g->nr_noduri; i++) {
        g->Arce[index_nod][i] = 0;
        g->Arce[i][index_nod] = 0;
    }
}

void InsertArc(Graf *g, Arc a) {
    g->Arce[a.idx_nod_1][a.idx_nod_2] = a.pondere;
}

void SuprimaNod(Graf *g, int index_nod) {
    int index_ultim = g->nr_noduri - 1;
    g->Noduri[index_nod] = g->Noduri[index_ultim];
    for (int i = 0; i < g->nr_noduri; i++) {
        g->Arce[i][index_nod] = g->Arce[i][index_ultim];
        g->Arce[index_nod][i] = g->Arce[index_ultim][i];
    }
    g->nr_noduri--;
}

void SuprimaArc(Graf *g, Arc a) {
    g->Arce[a.idx_nod_1][a.idx_nod_2] = 0;
}

void Afiseaza_Arce(Graf *g) {
    for (int i = 0; i < g->nr_noduri; i++) {
        for (int j = 0; j < g->nr_noduri; j++) {
            printf("%d ", g->Arce[i][j]);
        }
        printf("\n");
    }
}

void InitializareMarcari(Graf *g) {
    for (int i = 0; i < g->nr_noduri; i++) {
        g->marc[i] = 0;
    }
}

void Prelucrare(Nod n) {
    printf("%d ", n.cheie);
}

void CautareInAdancime(Graf *g, int x) {
    g->marc[x] = 1;
    Prelucrare(g->Noduri[x]);
    for (int k = 0; k < g->nr_noduri; k++) {
        if (g->Arce[x][k] != 0 && g->marc[k] == 0) {
            CautareInAdancime(g, k);
        }
    }
}


void afiseazaDrumuri(int dest, int origine, int predecesori[MAX][MAX], int nrPredecesori[], int drum[MAX], int lungime, int count) {
    if (dest == origine) {//ajunge la inceputul drumului
        printf("varianta %d:\n", count);
        for (int i = lungime - 1; i >= 0; i--) {
            printf("%d ", drum[i]);
        }
        printf("\n");
        return;
    }
    
    count++;
    for (int i = 0; i < nrPredecesori[dest]; i++) {
        drum[lungime] = predecesori[dest][i];
        afiseazaDrumuri(predecesori[dest][i], origine, predecesori, nrPredecesori, drum, lungime + 1, count);
    }
}

void Dijkstra(Graf *g, int origine, int cost_min[], int destinatie) {
    int predecesori[MAX][MAX], nrPredecesori[MAX];
    int vizitat[MAX] = {0};

    for (int i = 0; i < g->nr_noduri; i++) {
        cost_min[i] = INT_MAX;
        nrPredecesori[i] = 0;
    }

    cost_min[origine] = 0;
    predecesori[origine][nrPredecesori[origine]++] = -1; 

    // caut dumul minim
    for (int k = 0; k < g->nr_noduri; k++) {
        int min = INT_MAX, nodMin = -1;
        for (int i = 0; i < g->nr_noduri; i++) {
            if (!vizitat[i] && cost_min[i] < min) {
                min = cost_min[i];
                nodMin = i;
            }
        }

        if (nodMin == -1) break;
        vizitat[nodMin] = 1;

        //actualizez costurile
        for (int i = 0; i < g->nr_noduri; i++) {
            if (g->Arce[nodMin][i] != 0) {
                int newCost = cost_min[nodMin] + g->Arce[nodMin][i];
                if (newCost < cost_min[i]) {
                    cost_min[i] = newCost;
                    nrPredecesori[i] = 0;
                    predecesori[i][nrPredecesori[i]++] = nodMin;
                } else if (newCost == cost_min[i]) {
                    predecesori[i][nrPredecesori[i]++] = nodMin;
                }
            }
        }
    }

    
    if (cost_min[origine] == INT_MAX || destinatie == origine) {
        printf("Nu exista drum de la nodul %d la nodul %d\n", origine, destinatie);
    } else {
        printf("Drumul minim de la nodul %d la nodul %d: \n", origine, destinatie);
        int drum[MAX];
        drum[0] = destinatie;
        afiseazaDrumuri(destinatie, origine, predecesori, nrPredecesori, drum, 1, 0);
        printf("Costul minim: %d\n", cost_min[destinatie]);
    }
}

