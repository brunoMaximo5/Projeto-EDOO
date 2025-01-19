#ifndef GRAFO_H
#define GRAFO_H

#include "No.h"
#include <unordered_map>
#include <vector>
#include <string>

class Grafo {
private:
    std::unordered_map<int, No> nos; // Mapeia IDs para objetos da classe No

public:
    // Adicionar um nó ao grafo
    void adicionarNo(int id, const std::string& nome);

    // Adicionar uma aresta com peso entre dois nós
    void adicionarAresta(int idOrigem, int idDestino, double peso);

    // Obter o nó pelo ID
    No* obterNo(int id);

    // Imprimir o grafo para depuração
    void imprimirGrafo();
};

#endif
