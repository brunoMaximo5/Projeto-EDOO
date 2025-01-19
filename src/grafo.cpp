#include "Grafo.h"
#include <iostream>

// Adiciona um novo nó ao grafo
void Grafo::adicionarNo(int id, const std::string& nome) {
    if (nos.find(id) == nos.end()) {
        nos.emplace(id, No(id, nome));
    }
}

// Adiciona uma aresta entre dois nós
void Grafo::adicionarAresta(int idOrigem, int idDestino, double peso) {
    if (nos.find(idOrigem) != nos.end() && nos.find(idDestino) != nos.end()) {
        nos[idOrigem].adicionarAdjacente(idDestino, peso);
    }
}

// Retorna um ponteiro para o nó com o ID especificado
No* Grafo::obterNo(int id) {
    return (nos.find(id) != nos.end()) ? &nos[id] : nullptr;
}

// Imprime os nós e suas conexões para depuração
void Grafo::imprimirGrafo() {
    for (const auto& [id, no] : nos) {
        std::cout << "No " << no.getId() << " (" << no.getNome() << ") -> ";
        for (const auto& [idAdj, peso] : no.getAdjacentes()) {
            std::cout << "[" << idAdj << ", " << peso << "] ";
        }
        std::cout << std::endl;
    }
}
