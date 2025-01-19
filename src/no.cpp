#include "No.h"

// Construtor padrão
No::No() : id(-1), nome("") {}

// Construtor com argumentos
No::No(int id, const std::string& nome) : id(id), nome(nome) {}

int No::getId() const {
    return id;
}

std::string No::getNome() const {
    return nome;
}

void No::adicionarAdjacente(int idDestino, double peso) {
    adjacentes.push_back({idDestino, peso});
}

const std::vector<std::pair<int, double>>& No::getAdjacentes() const {
    return adjacentes;
}
