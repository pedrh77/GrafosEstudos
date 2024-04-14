#include <stdio.h>

#define VERTICES 5
#define ARESTAS 8

int grafo[VERTICES][ARESTAS] = { 0 };

void
AdicionaArestas (int v1, int v2, int peso)
{
  grafo[v1 - 1][v2 - 1] = peso;
  grafo[v2 - 1][v1 - 1] = peso;
}

void
imprimirGrafo ()
{
  //percorre o grafo gerado pela adição das arestas
  for (int i = 0; i < VERTICES; i++)
	{
	  for (int j = 0; j < VERTICES; j++)
		{
		  printf ("%d", grafo[i][j]);
		}
	  printf ("\n");
	}
}


int
main ()
{
  //define as arestas do grafo.
  int arestas[ARESTAS][3] =
	{{1,5,1},{1,4,4},{1,3,2},{2,5,5},{2,4,7},{2,3,3},{3,5,6},{3,2,3},{3,1,2},{4,5,8},{4,5,8},{4,2,7},{4,1,4},{5,4,8},{5,3,6},{5,2,5},{5,1,1}};

  //percorre arestas grafo, adicionando valores na matriz de adjacencia.
  for (int i = 0; i < ARESTAS; i++)
	{
	  AdicionaArestas (arestas[i][0], arestas[i][1], arestas[i][2]);
	}
  imprimirGrafo ();
}