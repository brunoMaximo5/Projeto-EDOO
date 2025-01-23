#ifndef BUSCA_MENOR_CAMINHO_H
#define BUSCA_MENOR_CAMINHO_H

#include "Grafo.h"
#include <unordered_map>
#include <queue>
#include <vector>

class BuscaMenorCaminho {
public:
    void encontrarMenorCaminho(Grafo& grafo, int origem, int destino);
};

#endif
