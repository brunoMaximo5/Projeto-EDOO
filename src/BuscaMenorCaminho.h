#ifndef BUSCA_MENOR_CAMINHO_H
#define BUSCA_MENOR_CAMINHO_H

#include "busca.h"
#include <unordered_map> // Para armazenar as distâncias mínimas e predecessores
#include <queue>         // Para a fila de prioridade (usada no algoritmo de Dijkstra)
#include <vector>        // Para armazenar o caminho encontrado
#include <iostream>      // Para saída de dados

// Classe que implementa a busca do menor caminho usando o algoritmo de Dijkstra
class BuscaMenorCaminho : public Busca {
public:
    // Implementação do método que encontra o menor caminho entre dois nós no grafo
    void encontrarCaminho(Grafo& grafo, int origem, int destino) override;
};

#endif
