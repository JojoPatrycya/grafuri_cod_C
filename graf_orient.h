#ifndef GRAF_ORIENT
#define GRAF_ORIENT

#define MAX_NR_NODURI 100
#define MAX 100

typedef struct TipNod {
  //Ambele sunt doar niste atribute ale nodului
  //Nu influenteaza implementarea functiilor
  int cheie;
  int info;
} Nod;

typedef struct TipArc {
    int idx_nod_1, idx_nod_2;
    int pondere;
} Arc;

typedef struct Graf {
  int nr_noduri;
  int nr_muchii;
  Nod Noduri[MAX_NR_NODURI];
  int Arce[MAX_NR_NODURI][MAX_NR_NODURI];//matricea de adiacenta
  int marc[MAX_NR_NODURI];

} Graf;

typedef struct Subset {  
    int parent, rank;  
} Subset;  
  

void Initializare(Graf *g);
void InsertNod(Graf *g, Nod n);
void InsertArc(Graf *g, Arc a);
void SuprimaNod(Graf *g, int index_nod);
void SuprimaArc(Graf *g, Arc a);
void Afiseaza_Arce(Graf *g);
void InitializareMarcari(Graf *g);
void Prelucrare(Nod n);
void CautareInAdancime(Graf *g, int x);
int MIN(int a, int b);
void dijkstra(Graf *g, int p, int costMin[], int destinatie);
void afiseazaDrumuri(int dest, int origine, int predecesori[MAX][MAX], int nrPredecesori[], int drum[MAX], int lungime, int count);

#endif