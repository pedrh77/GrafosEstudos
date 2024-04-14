#include <stdio.h>
#include <stdbool.h>

#define VERTICES 6 // Número de vértices no grafo

bool visitado[VERTICES] = {false}; // Array para rastrear os vértices visitados durante a busca em profundidade (DFS)

// Função de busca em profundidade (DFS) recursiva
bool dfs(int grafo[VERTICES][VERTICES], int vertice)
{
    printf("%d ", vertice + 1); // Imprime o vértice atual (adiciona 1 porque os vértices são indexados a partir de 0)
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

// Função de busca em largura (BFS)
void bfs(int grafo[VERTICES][VERTICES], int verticeInicial)
{
    bool visitado[VERTICES] = {false}; // Array para rastrear os vértices visitados durante a busca em largura (BFS)
    int fila[VERTICES]; // Fila para armazenar os vértices a serem visitados
    int frente = 0, traseira = 0; // Índices para o início e o fim da fila

    visitado[verticeInicial] = true; // Marca o vértice inicial como visitado
    fila[traseira++] = verticeInicial; // Adiciona o vértice inicial à fila

    printf("Largura (BFS): \n");

    while (frente != traseira)
    {
        int verticeAtual = fila[frente++]; // Remove o vértice do início da fila
        printf("%d ", verticeAtual + 1); // Imprime o vértice atual (adiciona 1 porque os vértices são indexados a partir de 0)

        // Percorre todos os vértices adjacentes ao vértice atual
        for (int i = 0; i < VERTICES; i++)
        {
            // Verifica se há uma aresta entre o vértice atual e o vértice i e se o vértice i não foi visitado
            if (grafo[verticeAtual][i] && !visitado[i])
            {
                visitado[i] = true; // Marca o vértice como visitado
                fila[traseira++] = i; // Adiciona o vértice à fila
            }
        }
    }
}

int main()
{
    int grafo[VERTICES][VERTICES] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    printf("Profundidade (DFS): ");
    for (int i = 0; i < VERTICES; i++)
    {
        // Verifica se o vértice i não foi visitado, para garantir que todos os componentes conectados sejam visitados
        if (!visitado[i])
        {
            dfs(grafo, i); // Inicia a busca em profundidade (DFS) a partir do vértice i não visitado
        }
    }
    printf("\n");

    bfs(grafo, 0); // Inicia a busca em largura (BFS) a partir do vértice 0

    return 0;
}
