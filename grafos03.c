#include <stdio.h>
#include <stdbool.h>

#define VERTICES 6 // Número de vértices no grafo

bool visitado[VERTICES] = {false}; // Array para rastrear os vértices visitados durante a busca em profundidade (DFS)

// Função de busca em profundidade (DFS) recursiva
bool dfs(int grafo[VERTICES][VERTICES], int vertice)
{
    printf("%d", vertice + 1); // Imprime o vértice atual (adiciona 1 porque os vértices são indexados a partir de 0)
    visitado[vertice] = true; // Marca o vértice como visitado

    for (int i = 0; i < VERTICES; i++)
    {
        // Verifica se há uma aresta entre o vértice atual e o vértice i e se o vértice i não foi visitado
        if (grafo[vertice][i] && !visitado[i])
        {
            dfs(grafo, i); // Chama recursivamente dfs() para visitar o vértice i
        }
    }
}

int main()
{
    int grafo[VERTICES][VERTICES] = {

    };

    printf("Profundidade (DFS): \n");
    for (int i = 0; i < VERTICES; i++)
    {
        // Verifica se o vértice i não foi visitado, para garantir que todos os componentes conectados sejam visitados
        if (!visitado[i])
        {
            dfs(grafo, i); // Inicia a busca em profundidade (DFS) a partir do vértice i não visitado
        }
    }
    return 0;
}
