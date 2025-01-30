#include "buscaMenorCaminho.h"
#include <limits>

void BuscaMenorCaminho::encontrarCaminho(Grafo& grafo, int origem, int destino) {
    exibirIntroducao(); // Chamando método da classe base para exibir a introdução

    // Mapas para armazenar as distâncias mínimas e os predecessores no caminho
    std::unordered_map<int, double> dist;
    std::unordered_map<int, int> anterior;

    // Inicializa as distâncias com infinito, exceto para a origem
    for (const auto& [id, _] : grafo.getNos()) {
        dist[id] = std::numeric_limits<double>::infinity();
    }
    dist[origem] = 0; // A distância da origem para ela mesma é 0

    // Fila de prioridade que processa os nós pela menor distância
    auto cmp = [&dist](int left, int right) { return dist[left] > dist[right]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> fila(cmp);
    fila.push(origem);

    // Algoritmo de Dijkstra
    while (!fila.empty()) {
        int atual = fila.top(); // Obtém o nó com a menor distância
        fila.pop();

        if (atual == destino) break; // Se o destino foi encontrado, encerra a busca

        // Percorre os vizinhos do nó atual
        for (const auto& [vizinho, peso] : grafo.obterNo(atual)->getAdjacentes()) {
            double novaDist = dist[atual] + peso; // Calcula a nova distância
            if (novaDist < dist[vizinho]) { // Se encontrou um caminho melhor, atualiza
                dist[vizinho] = novaDist;
                anterior[vizinho] = atual; // Registra o nó anterior no caminho
                fila.push(vizinho); // Adiciona o vizinho à fila para processamento
            }
        }
    }

    // Reconstrução do caminho a partir do destino até a origem
    std::vector<int> caminho;
    for (int v = destino; v != origem; v = anterior[v]) {
        caminho.push_back(v);
    }
    caminho.push_back(origem);

    // Exibindo o caminho e o custo total
    std::cout << "Menor caminho: ";
    for (auto it = caminho.rbegin(); it != caminho.rend(); ++it) {
        std::cout << *it;
        if (it != caminho.rend() - 1) std::cout << " -> ";
    }
    std::cout << std::endl;

    std::cout << "Custo total: " << dist[destino] << std::endl;
}
