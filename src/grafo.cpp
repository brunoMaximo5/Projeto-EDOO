#include "Grafo.h"
#include <iostream>

// Adiciona um nó ao grafo, caso o ID não esteja em uso
void Grafo::adicionarNo(int id, const std::string& nome) {
    if (nos.find(id) == nos.end()) {
        nos[id] = No(id, nome);
    } else {
        std::cout << "Nó com ID " << id << " já existe." << std::endl;
    }
}

// Adiciona uma aresta entre dois nós existentes
void Grafo::adicionarAresta(int idOrigem, int idDestino, double peso) {
    if (nos.find(idOrigem) != nos.end() && nos.find(idDestino) != nos.end()) {
        nos[idOrigem].adicionarAdjacente(idDestino, peso);
    } else {
        std::cout << "Origem ou destino inválido." << std::endl;
    }
}

// Retorna um ponteiro para o nó com o ID especificado, ou nullptr se não encontrado
No* Grafo::obterNo(int id) {
    if (nos.find(id) != nos.end()) {
        return &nos[id];
    }
    return nullptr;
}

// Retorna todos os nós do grafo
const std::unordered_map<int, No>& Grafo::getNos() const {
    return nos;
}

// Imprime todos os nós e suas conexões no console
void Grafo::imprimirGrafo() {
    for (const auto& [id, no] : nos) {
        std::cout << "Nó " << no.getNome() << " (ID " << id << "): ";
        for (const auto& [destino, peso] : no.getAdjacentes()) {
            std::cout << "-> " << destino << " (peso " << peso << ") ";
        }
        std::cout << std::endl;
    }
}
