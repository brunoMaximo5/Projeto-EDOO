#ifndef BUSCA_H
#define BUSCA_H

#include "Grafo.h"
#include <iostream>

// Classe abstrata que define a interface para as classes de busca no grafo
class Busca {
public:
    virtual ~Busca() = default; // Destrutor virtual para permitir a destruição correta das classes derivadas

    // Método virtual puro para encontrar o caminho entre dois nós
    virtual void encontrarCaminho(Grafo& grafo, int origem, int destino) = 0;

    // Método que exibe uma introdução ao processo de busca
    virtual void exibirIntroducao() const {
        std::cout << "Iniciando o processo de busca no grafo..." << std::endl;
    }
};


#endif