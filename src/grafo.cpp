#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Adiciona um nó ao grafo, caso o ID não esteja em uso
void Grafo::adicionarNo(int id, const std::string& nome) {
    if (nos.find(id) == nos.end()) {
        nos[id] = No(id, nome);
    } else {
        std::cout << "Nó com ID " << id << " já existe." << std::endl;
    }
}

// Adiciona uma aresta entre dois nós existentes
void Grafo::adicionarAresta(int idOrigem, int idDestino, double peso) {
    if (nos.find(idOrigem) != nos.end() && nos.find(idDestino) != nos.end()) {
        nos[idOrigem].adicionarAdjacente(idDestino, peso);
    } else {
        std::cout << "Origem ou destino inválido." << std::endl;
    }
}

// Retorna um ponteiro para o nó com o ID especificado, ou nullptr se não encontrado
No* Grafo::obterNo(int id) {
    if (nos.find(id) != nos.end()) {
        return &nos[id];
    }
    return nullptr;
}

// Retorna todos os nós do grafo
const std::unordered_map<int, No>& Grafo::getNos() const {
    return nos;
}

// Imprime todos os nós e suas conexões no console
void Grafo::imprimirGrafo() {
    std::cout << "\n===== Estrutura do Grafo =====\n";
    std::cout << "No      | Conexões (Destino, Peso)\n";
    std::cout << "----------------------------------\n";

    for (const auto& [id, no] : nos) {
        std::cout << no.getNome() << " (" << id << ")  | ";
        
        const auto& adjacentes = no.getAdjacentes();
        if (adjacentes.empty()) {
            std::cout << "Sem conexoes";
        } else {
            for (size_t i = 0; i < adjacentes.size(); i++) {
                int destino = adjacentes[i].first;
                double peso = adjacentes[i].second;
                std::cout << destino << " (" << peso << ")";
                if (i < adjacentes.size() - 1) std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "==================================\n";
}

// Função para carregar o grafo de um arquivo
void Grafo::carregarDeArquivo(const std::string& caminhoArquivo) {
    std::ifstream arquivo(caminhoArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << std::endl;
        return;
    }

    std::string linha;
    bool lendoNos = false;
    bool lendoArestas = false;

    while (std::getline(arquivo, linha)) {
        // Ignorar linhas em branco
        if (linha.empty()) continue;

        // Verificar se estamos na seção de nós ou arestas
        if (linha == "nos") {
            lendoNos = true;
            lendoArestas = false;
            continue;
        } else if (linha == "arestas") {
            lendoNos = false;
            lendoArestas = true;
            continue;
        }

        // Ler nós
        if (lendoNos) {
            std::istringstream ss(linha);
            int id;
            std::string nome;
            ss >> id >> nome;
            adicionarNo(id, nome);
        }

        // Ler arestas
        if (lendoArestas) {
            std::istringstream ss(linha);
            int origem, destino;
            double peso;
            ss >> origem >> destino >> peso;
            adicionarAresta(origem, destino, peso);
        }
    }

    arquivo.close();
}