#include "buscaMenorCaminho.h"
#include <limits>

void BuscaMenorCaminho::encontrarCaminho(Grafo& grafo, int origem, int destino) {
    exibirIntroducao(); // Chamando método da classe base

    std::unordered_map<int, double> dist; // Armazena a menor distância de origem até cada nó
    std::unordered_map<int, int> anterior; // Armazena o caminho percorrido

    // Inicializa as distâncias com infinito
    for (const auto& [id, _] : grafo.getNos()) {
        dist[id] = std::numeric_limits<double>::infinity();
    }
    dist[origem] = 0; // Distância da origem para ela mesma é 0

    // Criando a fila de prioridade para processar os nós com menor distância primeiro
    auto cmp = [&dist](int left, int right) { return dist[left] > dist[right]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> fila(cmp);
    fila.push(origem);

    while (!fila.empty()) {
        int atual = fila.top(); // Obtém o nó com menor distância
        fila.pop();

        if (atual == destino) break; // Se o destino foi alcançado, interrompe a busca

        // Percorre os vizinhos do nó atual
        for (const auto& [vizinho, peso] : grafo.obterNo(atual)->getAdjacentes()) {
            double novaDist = dist[atual] + peso; // Calcula a nova distância
            if (novaDist < dist[vizinho]) { // Se encontrou um caminho melhor, atualiza
                dist[vizinho] = novaDist;
                anterior[vizinho] = atual; // Registra o caminho percorrido
                fila.push(vizinho); // Adiciona o vizinho à fila para processamento
            }
        }
    }

    // Reconstruindo o caminho a partir do destino até a origem
    std::vector<int> caminho;
    for (int v = destino; v != origem; v = anterior[v]) {
        caminho.push_back(v);
    }
    caminho.push_back(origem);

    // Exibindo o menor caminho encontrado
    std::cout << "Menor caminho: ";
    for (auto it = caminho.rbegin(); it != caminho.rend(); ++it) {
        std::cout << *it;
        if (it != caminho.rend() - 1) std::cout << " -> ";
    }
    std::cout << std::endl;

    // Exibindo o custo total do caminho
    std::cout << "Custo total: " << dist[destino] << std::endl;
}
