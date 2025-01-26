#ifndef BUSCA_MENOR_CAMINHO_H
#define BUSCA_MENOR_CAMINHO_H

#include "Grafo.h"
#include <unordered_map>
#include <queue>
#include <vector>

// Classe que implementa o algoritmo de Dijkstra para buscar o menor caminho
class BuscaMenorCaminho {
public:
    void encontrarMenorCaminho(Grafo& grafo, int origem, int destino); // Executa a busca
};

#endif
