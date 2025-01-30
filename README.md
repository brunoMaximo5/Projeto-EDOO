# Dijkstra - Algoritmo de Busca do Menor Caminho

## Objetivo do Projeto

Este projeto tem como objetivo a implementação do **Algoritmo de Dijkstra** para encontrar o menor caminho em um grafo ponderado. O grafo é representado por uma classe `Grafo`, e a busca pelo menor caminho é realizada por meio da classe `BuscaMenorCaminho`. O projeto utiliza conceitos de programação orientada a objetos (OOP) em C++, como classes, herança, polimorfismo e encapsulamento.

A aplicação permite que o grafo seja carregado a partir de um arquivo e, com base nesse grafo, o algoritmo de Dijkstra encontra o caminho mais curto entre dois nós. O sistema pode ser expandido para incluir diversas funcionalidades e otimizações, como diferentes tipos de grafos ou algoritmos de busca.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

- **Main.cpp**: Arquivo principal que inicializa o programa e executa a busca.
- **Grafo.cpp**: Implementação da classe `Grafo`, que manipula os vértices e arestas do grafo.
- **No.cpp**: Implementação da classe `No`, que representa os nós do grafo.
- **Busca.cpp**: Implementação da classe base `Busca`, que serve de base para os algoritmos de busca.
- **BuscaMenorCaminho.cpp**: Implementação do algoritmo de Dijkstra, que herda a classe `Busca` e encontra o menor caminho no grafo.
- **Grafo.h, No.h, Busca.h, BuscaMenorCaminho.h**: Arquivos de cabeçalho para as respectivas classes.

## Como Executar o Projeto

Para executar o projeto, siga as etapas abaixo:

### 1. Pré-requisitos

Certifique-se de que você tenha o compilador **g++** instalado em seu sistema e que o C++17 esteja habilitado para que o código funcione corretamente.

Se você estiver utilizando um ambiente baseado em Linux ou Windows com o MSYS2 ou MinGW, pode ser necessário instalar o **g++**. No Linux, você pode usar o seguinte comando para instalar o compilador:

```bash
sudo apt-get install g++

. Compilando o Projeto
Abra o terminal ou prompt de comando no diretório onde os arquivos do projeto estão localizados e execute o seguinte comando para compilar o código:

bash
g++ -o Dijkstra Main.cpp Grafo.cpp No.cpp Busca.cpp BuscaMenorCaminho.cpp -std=c++17
Esse comando compilará todos os arquivos e gerará um executável chamado Dijkstra.

3. Executando o Programa
Para executar o programa, basta rodar o seguinte comando:

bash
Copiar
Editar
./Dijkstra
Ou, se você estiver no Windows, use:

bash
Copiar
Editar
Dijkstra.exe
4. Carregar um Grafo
O programa carrega um grafo a partir de um arquivo. Você pode modificar o código para usar um arquivo de grafo específico ou ajustar o carregamento de dados no próprio código.

Explicação das Classes
Classe Grafo: Representa o grafo, contendo uma coleção de nós (Nos) e suas arestas. Oferece métodos para manipular o grafo, como adicionar nós e carregar o grafo de um arquivo.

Classe No: Representa um nó do grafo. Cada nó pode ter adjacentes (vizinhos) e armazena um identificador único.

Classe Busca: Classe base para os algoritmos de busca. A classe BuscaMenorCaminho herda dessa classe e implementa o algoritmo de Dijkstra.

Classe BuscaMenorCaminho: Implementa o algoritmo de Dijkstra para encontrar o menor caminho entre dois nós em um grafo ponderado.