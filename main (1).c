#include <stdio.h>
#include <stdlib.h>
#include "graf_orient.h"
#include "graf_orient.c"
#include <time.h>



int main() {

    printf("graful 1:\n");
    Graf *g=(Graf*)malloc(sizeof(Graf)*100);
    Initializare(g);

  
    Nod nod1 = {0};
    Nod nod2 = {1};
    Nod nod3 = {2};
    Nod nod4 = {3};
    Nod nod5 = {4};
    Nod nod6 = {5};
    
    InsertNod(g, nod1);
    InsertNod(g, nod2);
    InsertNod(g, nod3);
    InsertNod(g, nod4);
    InsertNod(g, nod5);
    InsertNod(g, nod6);
  
    Arc arc1 = {0, 2, 10}; 
    Arc arc2 = {1, 2, 60}; 
    Arc arc3 = {1, 0, 100};
    Arc arc4 = {0, 5, 10};
    Arc arc5 = {0, 3, 30};
    Arc arc6 = {4, 3, 10};
    Arc arc7 = {2, 3, 20};
    Arc arc8 = {1, 3, 30};
    Arc arc9 = {4, 1, 40};
    Arc arc10 = {5, 4, 10};
    InsertArc(g, arc1);
    InsertArc(g, arc2);
    InsertArc(g, arc3);
    InsertArc(g, arc4);
    InsertArc(g, arc5);
    InsertArc(g, arc6);
    InsertArc(g, arc7);
    InsertArc(g, arc8);
    InsertArc(g, arc9);
    InsertArc(g, arc10);
  
    printf("Matricea de adiacenta:\n");
    Afiseaza_Arce(g);

  
    

    //int x;
    
    /*printf("Traversare in adancime: \n");
    for(x=0; x<g->nr_noduri;x++)
    {
        if(g->marc[x]==0)
        {
            CautareInAdancime(g,x);
        }
    }
    printf("\n");

    */
    int costMin[MAX + 1];
    int origine, destinatie;
    printf("dati nodul de plecare pt graful 1:\n");
    scanf("%d", &origine);
    printf("dati nodul destinatie pt graful 1: \n");
    scanf("%d", &destinatie);
    Dijkstra(g, 0, costMin, destinatie);
    
    
    printf("\nGraful 2:\n");
    Graf *g2=(Graf*)malloc(sizeof(Graf)*100);
    Initializare(g2);

  
    Nod node1 = {0};
    Nod node2 = {1};
    Nod node3 = {2};
    Nod node4 = {3};
    Nod node5 = {4};
    
    
    InsertNod(g2, node1);
    InsertNod(g2, node2);
    InsertNod(g2, node3);
    InsertNod(g2, node4);
    InsertNod(g2, node5);
  
    Arc arce1 = {1, 0, 10}; 
    Arc arce2 = {1, 2, 10}; 
    Arc arce3 = {1, 3, 50};
    Arc arce4 = {2, 3, 40};
    Arc arce5 = {3, 0, 15};
    Arc arce6 = {4, 3, 20};
    Arc arce7 = {4, 2, 20};
    Arc arce8 = {0, 4, 25};
    
    InsertArc(g2, arce1);
    InsertArc(g2, arce2);
    InsertArc(g2, arce3);
    InsertArc(g2, arce4);
    InsertArc(g2, arce5);
    InsertArc(g2, arce6);
    InsertArc(g2, arce7);
    InsertArc(g2, arce8);
  
    printf("Matricea de adiacenta:\n");
    Afiseaza_Arce(g2);

  
    

    
    
    /*printf("Traversare in adancime: \n");
    for(x=0; x<g2->nr_noduri;x++)
    {
        if(g2->marc[x]==0)
        {
            CautareInAdancime(g2,x);
        }
    }
    printf("\n");
*/
    
    
    
    printf("dati nodul de plecare pt graful 2:\n");
    scanf("%d", &origine);
    printf("dati nodul destinatie pt graful 2: \n");
    scanf("%d", &destinatie);
    Dijkstra(g2, origine, costMin, destinatie);
    
    

    printf("\nGraful 3:\n");
    Graf *g3=(Graf*)malloc(sizeof(Graf)*100);
    Initializare(g3);

  
    Nod nodee1 = {0};
    Nod nodee2 = {1};
    Nod nodee3 = {2};
    Nod nodee4 = {3};
    Nod nodee5 = {4};
    Nod nodee6 = {5};
    Nod nodee7 = {6};

    InsertNod(g3, nodee1);
    InsertNod(g3, nodee2);
    InsertNod(g3, nodee3);
    InsertNod(g3, nodee4);
    InsertNod(g3, nodee5);
    InsertNod(g3, nodee6);
    InsertNod(g3, nodee7);
  
    Arc arcee1 = {0, 4, 20}; 
    Arc arcee2 = {0, 5, 30}; 
    Arc arcee3 = {1, 6, 20};
    Arc arcee4 = {2, 0, 10};
    Arc arcee5 = {2, 3, 10};
    Arc arcee6 = {2, 5, 40};
    Arc arcee7 = {3, 1, 10};
    Arc arcee8 = {3, 4, 50};
    Arc arcee9 = {4, 5, 10};
    Arc arcee10 = {5, 6, 80};
    

    
    InsertArc(g3, arcee1);
    InsertArc(g3, arcee2);
    InsertArc(g3, arcee3);
    InsertArc(g3, arcee4);
    InsertArc(g3, arcee5);
    InsertArc(g3, arcee6);
    InsertArc(g3, arcee7);
    InsertArc(g3, arcee8);
    InsertArc(g3, arcee9);
    InsertArc(g3, arcee10);
    
  
    printf("Matricea de adiacenta:\n");
    Afiseaza_Arce(g3);

  
    

    
    
    /*printf("Traversare in adancime: \n");
    for(x=0; x<g2->nr_noduri;x++)
    {
        if(g2->marc[x]==0)
        {
            CautareInAdancime(g2,x);
        }
    }
    printf("\n");
*/
    
    
    
    printf("dati nodul de plecare pt graful 3:\n");
    scanf("%d", &origine);
    printf("dati nodul destinatie pt graful 3: \n");
    scanf("%d", &destinatie);
    Dijkstra(g3, origine, costMin, destinatie);
    

  return 0;
}

