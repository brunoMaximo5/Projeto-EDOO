#ifndef GRAFO_H
#define GRAFO_H

#include "No.h"
#include <unordered_map>
#include <string>

class Grafo {
private:
    std::unordered_map<int, No> nos; // Mapeamento de ID para nós

public:
    void adicionarNo(int id, const std::string& nome); // Adiciona um nó ao grafo
    void adicionarAresta(int idOrigem, int idDestino, double peso); // Adiciona uma aresta entre dois nós
    No* obterNo(int id); // Obtém um ponteiro para um nó específico pelo ID
    const std::unordered_map<int, No>& getNos() const; // Retorna todos os nós no grafo
    void imprimirGrafo(); // Exibe o grafo no console
    void carregarDeArquivo(const std::string& caminhoArquivo); // Carrega o grafo de um arquivo
};

#endif