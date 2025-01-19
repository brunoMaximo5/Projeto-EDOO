#include <iostream>
#include "Grafo.h"

int main() {
    Grafo grafo;

    // Adicionando nós ao grafo
    grafo.adicionarNo(1, "A");
    grafo.adicionarNo(2, "B");
    grafo.adicionarNo(3, "C");

    // Adicionando arestas entre os nós
    grafo.adicionarAresta(1, 2, 5.0); // A -> B com peso 5.0
    grafo.adicionarAresta(2, 3, 3.0); // B -> C com peso 3.0
    grafo.adicionarAresta(1, 3, 8.0); // A -> C com peso 8.0

    // Exibir grafo
    std::cout << "Grafo criado:" << std::endl;
    grafo.imprimirGrafo();

    return 0;
}
