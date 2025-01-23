#include "Grafo.h"
#include "BuscaMenorCaminho.h"

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

    // Imprimindo o grafo
    grafo.imprimirGrafo();

    // Criando o objeto de busca e encontrando o menor caminho entre 10 (A) e 25 (E)
    BuscaMenorCaminho busca;
    busca.encontrarMenorCaminho(grafo, 10, 25);

    return 0;
}
