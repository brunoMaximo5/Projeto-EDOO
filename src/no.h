#ifndef NO_H
#define NO_H

#include <string>
#include <vector>

// Classe que representa um nó no grafo
class No {
private:
    int id; // Identificador único do nó
    std::string nome; // Nome ou descrição do nó
    std::vector<std::pair<int, double>> adjacentes; // Lista de adjacências (idDestino, peso)

public:
    No(); // Construtor padrão
    No(int id, const std::string& nome); // Construtor com argumentos para inicializar o nó
    int getId() const; // Retorna o ID do nó
    std::string getNome() const; // Retorna o nome do nó
    void adicionarAdjacente(int idDestino, double peso); // Adiciona uma aresta saindo deste nó
    const std::vector<std::pair<int, double>>& getAdjacentes() const; // Retorna os nós adjacentes
};

#endif
