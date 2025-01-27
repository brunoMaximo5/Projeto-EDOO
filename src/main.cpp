#include "Grafo.h"
#include "BuscaMenorCaminho.h"
#include <iostream>
#include <limits>

int main() {
    Grafo grafo;

    // Adicionando nós com identificadores não sequenciais
    grafo.adicionarNo(10, "A");
    grafo.adicionarNo(5, "B");
    grafo.adicionarNo(20, "C");
    grafo.adicionarNo(15, "D");
    grafo.adicionarNo(25, "E");

    // Adicionando arestas (origem, destino, peso)
    grafo.adicionarAresta(10, 5, 3.0);   // A -> B
    grafo.adicionarAresta(5, 20, 4.0);   // B -> C
    grafo.adicionarAresta(10, 20, 10.0); // A -> C
    grafo.adicionarAresta(20, 15, 2.0);  // C -> D
    grafo.adicionarAresta(15, 25, 6.0);  // D -> E
    grafo.adicionarAresta(25, 10, 7.0);  // E -> A

    std::cout << "Grafo atual:\n";
    grafo.imprimirGrafo();

    // Instanciando a classe derivada de Busca
    BuscaMenorCaminho busca;

    while (true) {
        int origem, destino;

        // Entrada do nó de origem
        std::cout << "\nDigite o ID do nó de origem (ou -1 para sair): ";
        std::cin >> origem;
        if (origem == -1) break;

        // Validar nó de origem
        if (!grafo.obterNo(origem)) {
            std::cout << "Nó de origem inválido! Tente novamente.\n";
            continue;
        }

        // Entrada do nó de destino
        std::cout << "Digite o ID do nó de destino: ";
        std::cin >> destino;

        // Validar nó de destino
        if (!grafo.obterNo(destino)) {
            std::cout << "Nó de destino inválido! Tente novamente.\n";
            continue;
        }

        // Calcular e exibir o menor caminho
        std::cout << "\nCalculando o menor caminho...\n";
        busca.encontrarCaminho(grafo, origem, destino); // Corrigido o nome do método
    }

    std::cout << "\nPrograma encerrado.\n";
    return 0;
}
