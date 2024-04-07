#include <stdio.h>
#include <stdbool.h>

#define VERTICES 6
#define INFINITO 9999

void Dijkstra(int grafo[VERTICES][VERTICES], int origem)
{
    // Inicializa arrays para armazenar distâncias mínimas e se os vértices foram visitados
    int distancia[VERTICES];
    bool visitado[VERTICES];

    // Define valores iniciais para as distâncias e marca todos os vértices como não visitados
    for (int i = 0; i < VERTICES; i++)
    {
        distancia[i] = INFINITO; // Define a distância de todos os vértices como infinito
        visitado[i] = false;     // Marca todos os vértices como não visitados
    }

    // A distância da origem para si mesma é 0
    distancia[origem] = 0;

    // Loop principal para calcular as distâncias mínimas
    for (int count = 0; count < VERTICES - 1; count++)
    {
        int u, min_distancia = INFINITO;

        // Encontra o vértice não visitado com a menor distância mínima
        for (int v = 0; v < VERTICES; v++)
        {
            if (visitado[v] == false && distancia[v] <= min_distancia)
            {
                min_distancia = distancia[v];
                u = v; // Atualiza o vértice atual (u) para o vértice com a menor distância mínima
            }
        }

        // Marca o vértice atual como visitado
        visitado[u] = true;

        // Atualiza as distâncias mínimas dos vértices adjacentes ao vértice atual (u)
        for (int v = 0; v < VERTICES; v++)
        {
            // Se o vértice não foi visitado, há uma aresta entre u e v, e o caminho através de u é mais curto,
            // então atualiza a distância mínima de v
            if (!visitado[v] && grafo[u][v] && distancia[u] != INFINITO && distancia[u] + grafo[u][v] < distancia[v])
            {
                distancia[v] = distancia[u] + grafo[u][v];
            }
        }
    }
    // imprime a distancia minima de cada vertice até a origem
    printf("Caminho minimo\n");
    for (int i = 0; i < VERTICES; i++) // Correção aqui: de > para <
    {
        printf("Vertice: %d: %d\n", i + 1, distancia[i]);
    }
}

int main()
{
    int grafo[VERTICES][VERTICES] = {
        {0, 0, 2, 4, 1, 0},
        {0, 0, 3, 7, 5, 0},
        {2, 3, 0, 0, 6, 0},
        {4, 7, 0, 0, 8, 0},
        {1, 5, 6, 8, 0, 0},
        {0, 0, 0, 0, 0, 0}};

    int origem = 0;
    printf("Vertice de Origem (1-%d) ", VERTICES);
    scanf("%d", &origem);
    Dijkstra(grafo, origem - 1);
}
