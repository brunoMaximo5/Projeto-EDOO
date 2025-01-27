#ifndef BUSCA_MENOR_CAMINHO_H
#define BUSCA_MENOR_CAMINHO_H

#include "busca.h"
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>

class BuscaMenorCaminho : public Busca {
public:
    void encontrarCaminho(Grafo& grafo, int origem, int destino) override;
};

#endif
