#ifndef NO_H
#define NO_H

#include <string>
#include <vector>

class No {
private:
    int id; // Identificador único do nó
    std::string nome; // Nome ou descrição do nó
    std::vector<std::pair<int, double>> adjacentes; // Lista de adjacências (idDestino, peso)

public:
    No(); // Construtor padrão
    No(int id, const std::string& nome); // Construtor com argumentos

    int getId() const;
    std::string getNome() const;

    void adicionarAdjacente(int idDestino, double peso);
    const std::vector<std::pair<int, double>>& getAdjacentes() const;
};

#endif
