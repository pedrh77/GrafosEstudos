#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// MST - Minimum Spanning Tree (Arvore Geradora Minima)

#define V 6 // Define a quantidade de arestas presentes no grafo

// Função que encontra chave de menor caminho
// e que não foi colocada no MST ainda.

int chaveMinima(int chave[], bool conjuntoMST[])
{
    int minimo = INT_MAX, indiceMinimo;

    for (int v = 0; v < V; v++)
        if (conjuntoMST[v] == false && chave[v] < minimo) // Percorre as chaves para encontrar menor caminho
            minimo = chave[v], indiceMinimo = v;

    return indiceMinimo;
}

// Imprime o MST armazenado da seguinte forma:
// Conexão   Custo
//  0 - 1    2
void imprimeMST(int pai[], int grafo[V][V])
{
    printf("Conexão \tCusto\n");
    int custoTotal = 0;
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d \n", pai[i], i, grafo[i][pai[i]]);
        custoTotal += grafo[i][pai[i]];
    }
    printf("Custo total: %d\n", custoTotal);
}

// Constroi e imprime MST para um grafo representado usando matriz de adjacência
void primMST(int grafo[V][V])
{
    // Inicio Criação e configuração inicial dos dados
    int pai[V];
    int chave[V];
    bool conjuntoMST[V];

    for (int i = 0; i < V; i++)
        chave[i] = INT_MAX, conjuntoMST[i] = false;

    chave[0] = 0;
    pai[0] = -1;

    for (int contador = 0; contador < V - 1; contador++)
    {
        // retorna indice da chave se for minima e se o caminho ainda não foi inserido no MST
        int u = chaveMinima(chave, conjuntoMST);
        conjuntoMST[u] = true; // Passa o dado como inserido no MST

        // Atualiza os valores chave e os pais dos vértices adjacentes
        for (int v = 0; v < V; v++)
            // grafo[u][v] é não zero só para vértices adjacentes de u
            // grafo[v] é falso para vértices não incluídos na MST
            // Atualiza a chave só se grafo[u][v] for menor que chave[v]
            if (grafo[u][v] && conjuntoMST[v] == false && grafo[u][v] < chave[v])
                pai[v] = u, chave[v] = grafo[u][v];
    }

    imprimeMST(pai, grafo);
}

int main()
{
    int grafo[V][V] = {
        {0, 3, 0, 0, 6, 5},
        {3, 0, 1, 0, 0, 4},
        {0, 1, 0, 6, 0, 4},
        {0, 0, 6, 0, 8, 5},
        {6, 0, 0, 8, 0, 2},
        {5, 4, 4, 5, 2, 0}};

    primMST(grafo);

    return 0;
}