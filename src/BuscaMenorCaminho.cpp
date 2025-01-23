#include "BuscaMenorCaminho.h"
#include <limits>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

void BuscaMenorCaminho::encontrarMenorCaminho(Grafo& grafo, int origem, int destino) {
    std::unordered_map<int, double> dist;
    std::unordered_map<int, int> anterior;

    // Inicializando distâncias como infinito, exceto a origem
    for (const auto& [id, _] : grafo.getNos()) {
        dist[id] = std::numeric_limits<double>::infinity();
    }
    dist[origem] = 0;

    // Fila de prioridade para explorar os nós mais próximos
    auto cmp = [&dist](int left, int right) { return dist[left] > dist[right]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> fila(cmp);
    fila.push(origem);

    // Algoritmo de Dijkstra
    while (!fila.empty()) {
        int atual = fila.top();
        fila.pop();

        if (atual == destino) break;

        for (const auto& [vizinho, peso] : grafo.obterNo(atual)->getAdjacentes()) {
            double novaDist = dist[atual] + peso;
            if (novaDist < dist[vizinho]) {
                dist[vizinho] = novaDist;
                anterior[vizinho] = atual;
                fila.push(vizinho);
            }
        }
    }

    // Construção do caminho
    std::vector<int> caminho;
    for (int v = destino; v != origem; v = anterior[v]) {
        caminho.push_back(v);
    }
    caminho.push_back(origem);

    // Exibição do caminho encontrado
    std::cout << "Menor caminho de " << grafo.obterNo(origem)->getNome()
              << " para " << grafo.obterNo(destino)->getNome() << ": ";
    for (auto it = caminho.rbegin(); it != caminho.rend(); ++it) {
        std::cout << grafo.obterNo(*it)->getNome();
        if (it != caminho.rend() - 1) std::cout << " -> ";
    }
    std::cout << std::endl;

    // Exibição do custo total
    std::cout << "Custo total: " << dist[destino] << std::endl;
}
