#include <stdio.h>

#define VERTICES 6
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
  //percorre o grafo gerado pela adiC'C#o das arestas
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
	{ {1, 3, 1}, {1, 4, 7}, {1, 5, 2}, {2, 3, 3}, {2, 4, 3}, {2, 5, 2}, {3, 5,0},{4, 5, 8} };

  //percorre arestas grafo, adicionando valores na matriz de adjacencia.
  for (int i = 0; i < ARESTAS; i++)
	{
	  AdicionaArestas (arestas[i][0], arestas[i][1], arestas[i][2]);
	}
  imprimirGrafo ();
}