# GraphPAA

Repositório para estudo de grafos na disciplina Projeto e Análise de Algoritmos.

## Como compilar e executar

Primeiro é preciso que você tenha instalado o [CMake](https://cmake.org/) (versão mínima 3.11) em seu sistema.

É recomendável criar uma nova pasta para a compilação do projeto, para isso, execute o seguinte comando:

```bash
mkdir build
cd build
```

Agora, dentro da pasta build, execute o seguinte comando para gerar os arquivos de compilação:

```bash
cmake ..
```

Por fim, execute o seguinte comando para compilar o projeto:

```bash
make
```

Se a compilação for bem sucedida, você poderá executar o projeto com o seguinte comando:

```bash
./GraphPAA
```

## Estrutura do projeto

O projeto está dividido em 9 arquivos principais:

main.cpp: Arquivo de testes do projeto, onde é feito os testes de execução dos algoritmos.

Graph.cpp: Arquivo onde é implementado a estrutura de grafo. Essa estrutura é utilizada pelas classes GraphList e GraphMatrix. 

Graph.h: Arquivo onde é definido a classe Graph. Graph é uma classe abstrata, portanto, não é possível instanciar um objeto dessa classe.

GraphList.cpp: Arquivo onde é implementado a estrutura de grafo utilizando listas de adjacência.

GraphList.h: Arquivo onde é definido a classe GraphList.

GraphMatrix.cpp: Arquivo onde é implementado a estrutura de grafo utilizando matriz de adjacência.

GraphMatrix.h: Arquivo onde é definido a classe GraphMatrix.

GraphListWeighted.cpp: Arquivo onde é implementado a estrutura de grafo com pesos utilizando listas de adjacência.

GraphList.h: Arquivo onde é definido a classe GraphListWeighted.
