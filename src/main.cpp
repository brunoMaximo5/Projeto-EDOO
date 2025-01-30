#include "Grafo.h"
#include "BuscaMenorCaminho.h"
#include <iostream>
#include <limits>

int main() {
    Grafo grafo;

    // Carregar o grafo de um arquivo
    grafo.carregarDeArquivo("grafo.txt");

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
        busca.encontrarCaminho(grafo, origem, destino);
    }

    std::cout << "\nPrograma encerrado.\n";
    return 0;
}