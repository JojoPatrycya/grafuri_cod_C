#include <stdio.h>
#include <stdlib.h>
#include "grafuri_pond.h"
#include <limits.h>
#include <stdbool.h>

#define MAX 100



void Initializare(Graf *g) {
  g->nr_noduri = 0;
}

void InsertNod(Graf *g, Nod n) {
  // Adaugă nodul n în graf (primul nod este pe poziția 0)
  int index_nod = g->nr_noduri;
  g->Noduri[index_nod] = n;
  g->nr_noduri++;

  // Se inițializează matricea de adiacență pentru noul nod
  int i;
  for (i = 0; i < g->nr_noduri; i++) {
    g->Arce[index_nod][i] = g->Arce[i][index_nod] = 0;
  }
}

void InsertArc(Graf *g, Arc a) {
  // Adaugă arcul a in graf
  g->Arce[a.idx_nod_1][a.idx_nod_2] = a.pondere;
  g->Arce[a.idx_nod_2][a.idx_nod_1] = a.pondere;
}

void SuprimaNod(Graf *g, int index_nod) {
  // Nodul indicat este înlocuit cu ultimul nod
  int index_ultim = g->nr_noduri - 1;
  g->Noduri[index_nod] = g->Noduri[index_ultim];
  int i;
  for (i = 0; i < g->nr_noduri; i++) {
    g->Arce[i][index_nod] = g->Arce[i][index_ultim];
    g->Arce[index_nod][i] = g->Arce[index_ultim][i];
  }
  g->nr_noduri--;
}

void SuprimaArc(Graf *g, Arc a) {
  // Elimină arcul a din graf
  g->Arce[a.idx_nod_1][a.idx_nod_2] = 0;
  g->Arce[a.idx_nod_2][a.idx_nod_1] = 0;
}

void Afiseaza_Arce(Graf *g) {
  int i, j;
  for (i = 0; i < g->nr_noduri; i++) {
    for (j = 0; j < g->nr_noduri; j++) {
      printf("%d ", g->Arce[i][j]);
    }
    printf("\n");
  }
}


int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void primMST(Graf* g, int n, int index) {
    int parent[MAX_NR_NODURI]; // Arcele incluse în MST
    int key[MAX_NR_NODURI]; // Cheile minime folosite pentru a alege arcele în MST
    bool mstSet[MAX_NR_NODURI]; // Afișează nodurile incluse în MST

    // Inițializează toate cheile ca Infinite și mstSet[] ca false
    for (int i = 0; i < g->nr_noduri; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[index] = 0; // Setează cheia de la primul nod la 0, așa că acesta va fi primul ales
    parent[index] = -1; // Primul nod nu are părinte

     

    for (int count = 0; count < g->nr_noduri; count++) {// Contor pentru numărul de noduri incluse în MST
        int u = minKey(key, mstSet,n);
        mstSet[u] = true; // Adaugă nodul în MST


        // Actualizează cheile și părinții nodurilor adiacente ale nodului selectat
        for (int v = 0; v < g->nr_noduri; v++) {
            if (g->Arce[u][v] && mstSet[v] == false && g->Arce[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->Arce[u][v];
            }
        }

        // Dacă numărul de noduri incluse în MST este mai mic decât numărul total de noduri,
        // iar nu s-au găsit noduri noi pentru a fi adăugate în MST, atunci putem presupune
        // că există componente conexe și trebuie să alegem un alt nod ca punct de plecare
        if (count < g->nr_noduri && u == minKey(key, mstSet, n))
        {
            for (int i = 0; i < g->nr_noduri; i++)
                if (!mstSet[i]) {
                    index = i;
                    break;
                }
        }
    }

    // Afiseaza rezultatul
    printf("Path \tCost\n");
    for (int i = 0; i < g->nr_noduri; i++) {
        if (parent[i] != -1) // Excludem nodurile fără părinte (nodurile izolate)
            printf("%d - %d \t%d \n", parent[i], i, g->Arce[i][parent[i]]);
    }
}

void sortare(Arc* arc, int nr_arc) {
    for (int i = 0; i < nr_arc - 1; i++)
        for (int j = i + 1; j < nr_arc; j++)
            if (arc[i].pondere > arc[j].pondere)
            {
                Arc aux = arc[i];
                arc[i] = arc[j];
                arc[j] = aux;
            }
}

void kruskal(Arc* arc, int nr_arc, int nr_nod) {
    int a[MAX+1];
    int result[MAX];

    sortare(arc, nr_arc);
    
    for (int i = 1; i <= nr_nod; i++) {
        a[i] = i;
    }
    
    int cost = 0, k = 0;
    for (int i = 0; i < nr_arc && k < nr_nod - 1; i++)
        if (a[arc[i].idx_nod_1] != a[arc[i].idx_nod_2])
        {
            result[i] = 1;
            cost= cost+ arc[i].pondere;
            int ai = a[arc[i].idx_nod_1], aj = a[arc[i].idx_nod_2];
            for (int j = 1; j <= nr_nod; ++j)
                if (a[j] == aj)
                    a[j] = ai;
            k++;
        }

    printf("Costul minim este: %d\n", cost);
    printf("Path \tCost\n");
    for (int i = 0; i < nr_arc; ++i) {
        if (result[i] == 1) {
            printf("%d - %d \t%d \n", arc[i].idx_nod_1, arc[i].idx_nod_2, arc[i].pondere);
        } 
    }
    printf("\n");
}