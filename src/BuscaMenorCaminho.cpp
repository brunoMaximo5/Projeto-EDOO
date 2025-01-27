#include "buscaMenorCaminho.h"
#include <limits>

void BuscaMenorCaminho::encontrarCaminho(Grafo& grafo, int origem, int destino) {
    exibirIntroducao(); // Chamando método da classe base

    std::unordered_map<int, double> dist;
    std::unordered_map<int, int> anterior;

    // Inicializa as distâncias
    for (const auto& [id, _] : grafo.getNos()) {
        dist[id] = std::numeric_limits<double>::infinity();
    }
    dist[origem] = 0;

    auto cmp = [&dist](int left, int right) { return dist[left] > dist[right]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> fila(cmp);
    fila.push(origem);

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

    std::vector<int> caminho;
    for (int v = destino; v != origem; v = anterior[v]) {
        caminho.push_back(v);
    }
    caminho.push_back(origem);

    std::cout << "Menor caminho: ";
    for (auto it = caminho.rbegin(); it != caminho.rend(); ++it) {
        std::cout << *it;
        if (it != caminho.rend() - 1) std::cout << " -> ";
    }
    std::cout << std::endl;

    std::cout << "Custo total: " << dist[destino] << std::endl;
}
