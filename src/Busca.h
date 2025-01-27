#ifndef BUSCA_H
#define BUSCA_H

#include "Grafo.h"
#include <iostream>

class Busca {
public:
    virtual ~Busca() = default; // Destrutor virtual

    // Método virtual puro
    virtual void encontrarCaminho(Grafo& grafo, int origem, int destino) = 0;

    // Método não puro: exibe informações sobre a busca
    virtual void exibirIntroducao() const {
        std::cout << "Iniciando o processo de busca no grafo..." << std::endl;
    }
};

#endif
