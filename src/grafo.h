#ifndef GRAFO_H
#define GRAFO_H

#include "No.h"
#include <unordered_map>
#include <string>

class Grafo {
private:
    std::unordered_map<int, No> nos; // Mapeia ID do nó para o nó

public:
    void adicionarNo(int id, const std::string& nome);  // Adiciona um nó
    void adicionarAresta(int idOrigem, int idDestino, double peso);  // Adiciona uma aresta
    No* obterNo(int id);  // Obtém um nó pelo ID
    const std::unordered_map<int, No>& getNos() const;  // Retorna todos os nós
    void imprimirGrafo();  // Exibe o grafo
};

#endif
