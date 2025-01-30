#ifndef BUSCA_MENOR_CAMINHO_H
#define BUSCA_MENOR_CAMINHO_H

#include "busca.h"
#include <unordered_map> // Para armazenar as distâncias mínimas e predecessores
#include <queue>         // Para a fila de prioridade (usada no algoritmo de Dijkstra)
#include <vector>        // Para armazenar o caminho encontrado
#include <iostream>      // Para saída de dados

// Classe BuscaMenorCaminho, que herda de Busca e implementa a busca do menor caminho
class BuscaMenorCaminho : public Busca {
public:
    // Método que encontra o menor caminho entre dois nós no grafo
    void encontrarCaminho(Grafo& grafo, int origem, int destino) override;
};

#endif
