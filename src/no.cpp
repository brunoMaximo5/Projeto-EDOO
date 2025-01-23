#include "No.h"

No::No() : id(-1), nome("") {}

No::No(int id, const std::string& nome) : id(id), nome(nome) {}

int No::getId() const {
    return id;
}

std::string No::getNome() const {
    return nome;
}

void No::adicionarAdjacente(int idDestino, double peso) {
    adjacentes.emplace_back(idDestino, peso);
}

const std::vector<std::pair<int, double>>& No::getAdjacentes() const {
    return adjacentes;
}
