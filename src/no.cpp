#include "No.h"

// Construtor padrão que inicializa o nó com valores padrão
No::No() : id(-1), nome("") {}

// Construtor que inicializa o nó com ID e nome fornecidos
No::No(int id, const std::string& nome) : id(id), nome(nome) {}

// Retorna o ID do nó
int No::getId() const {
    return id;
}

// Retorna o nome do nó
std::string No::getNome() const {
    return nome;
}

// Adiciona uma aresta para outro nó, especificando o peso
void No::adicionarAdjacente(int idDestino, double peso) {
    adjacentes.emplace_back(idDestino, peso);
}

// Retorna a lista de nós adjacentes e seus pesos
const std::vector<std::pair<int, double>>& No::getAdjacentes() const {
    return adjacentes;
}
