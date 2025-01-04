#include <stdio.h>
#include <stdlib.h>
#include "grafuri_pond.h"
#include "grafuri_pond.c"
#include <time.h>

int main()
{
    
    int n=8;
    Graf *graf1=(Graf*)malloc(sizeof(Graf)*(n+1));
    Initializare(graf1);
    Nod noduri1[n];
    Arc arce1[11]={{0,1,6},{0,3,2},{0,5,9},{6,7,3},{6,5,1},{3,1,1},{2,3,6},{1,6,2},{7,3,8},{5,2,1},{7,4,9}};

    Graf *graf2=(Graf*)malloc(sizeof(Graf)*(n+1));
    Initializare(graf2);
    Arc arce2[11]={{0,1,7},{2,1,9},{2,0,1},{4,3,6},{3,7,2},{6,4,9},{5,0,1},{1,7,1},{4,5,6},{6,2,8},{1,3,3}};
    Nod noduri2[n];
    
    Graf *graf3= (Graf*)malloc(sizeof(Graf)*(n+1));
    Initializare(graf3);
    Arc arce3[8]={{2,1,1},{1,0,7},{3,2,9},{6,5,2},{5,7,6},{5,4,3},{2,5,1},{4,1,8}};
    Nod noduri3[n];

    for(int i=0;i<8;i++)
    {
        InsertNod(graf1,noduri1[i]);
        InsertNod(graf2,noduri2[i]);
        InsertNod(graf3,noduri3[i]);
        InsertArc(graf3,arce3[i]);

    }

    for(int i=0;i<11;i++)
    {
        InsertArc(graf1,arce1[i]);
        InsertArc(graf2,arce2[i]);

    }
    //primMST(graf1,8,2);
    //primMST(graf2,8,3);



    clock_t start, end; //calculul timpului pt 2 functii
	double cpu_time_used;


    start = clock();
    printf("prim1:\n");
	primMST(graf1,8,1);
	end = clock();

	cpu_time_used = ((double)(end - start)) *1000/ CLOCKS_PER_SEC;

	printf("Timp de executie  1 prim: %.2f\n", cpu_time_used);


    start = clock();
    printf("prim2:\n");
	primMST(graf2,8,1);
	end = clock();

	cpu_time_used = ((double)(end - start)) *1000/ CLOCKS_PER_SEC;

	printf("Timp de executie  2 prim: %.2f\n", cpu_time_used);

	start = clock();
    printf("prim3:\n");
	primMST(graf3,8,1);
	end = clock();

	cpu_time_used = ((double)(end - start)) *1000/ CLOCKS_PER_SEC;

	printf("Timp de executie  3 prim: %.2f\n", cpu_time_used);

    

	start = clock();
	printf("Kruskal 1:\n ");
    kruskal(arce1,11,n);
	end = clock();

	cpu_time_used = ((double)(end - start)) *1000/ CLOCKS_PER_SEC;

	printf("Timp de executie  kruskal 1: %.2f\n", cpu_time_used);


    start = clock();
	printf("Kruskal 2:\n ");
    kruskal(arce2,11,n);
	end = clock();

	cpu_time_used = ((double)(end - start)) *1000/ CLOCKS_PER_SEC;

	printf("Timp de executie  kruskal 2: %.2f\n", cpu_time_used);



    start = clock();
	printf("Kruskal 3:\n ");
    kruskal(arce3,8,n);
	end = clock();

	cpu_time_used = ((double)(end - start)) *1000/ CLOCKS_PER_SEC;

	printf("Timp de executie  kruskal 3: %.2f\n", cpu_time_used);
    return 0;
}