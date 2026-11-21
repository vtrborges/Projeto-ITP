/**
 * Declaração da classe Imagem.
 */

#pragma once

#include "../paleta/paleta.h"
#include <string>
using Pixel = Cor; // Pixel agora é outro nome para Cor, representando a cor de um pixel da imagem.

// Defina aqui a classe Imagem, conforme especificado na etapa 2 do projeto.
// Você pode reaproveitar o tipo Cor definido em paleta.h, para representar as cores dos pixels da imagem.
// Para isso, você pode definir um tipo Pixel como um alias para Cor, ou seja, Pixel será apenas outro nome para Cor.

class Imagem {
    int largura;
    int altura;
    Cor** bitmap;

public:

    Imagem();

/**
* Aloca dinamicamente uma imagem (matriz de cores) com a largura e altura especificadas e com todos os pixels de cor preta.
* {-1, -1, -1} é definido como uma cor sentinela para indicar que determinado pixel não foi preenchido. 
* @param largura: largura da imagem (número de colunas);
* @param altura: altura da imagem (número de linhas);
*/
    Imagem(int largura, int altura);

/**
* Destrutor que libera a memória alocada dinamicamente.
*/
    ~Imagem();

/**
* Consulta o pixel dada a coordenada na matriz.
* @param linha;
* @param coluna;
*/
    Cor obterPixel(int linha, int coluna);

/**
* Define o pixel dada a coordenada na matriz. Retorna verdadeiro se foi possível definir a cor do pixel e falso caso contrário.
* @param cor: a cor desejada para o pixel;
*/
    bool definePixel(int linha, int coluna, Cor cor);

    bool lerPPM(std::string nomeArquivo);

    bool salvarPPM(const std::string &nomeArquivo) const;

    int obterAltura();

    int obterLargura();
};

// Lembre-se de:
// 1. verificar no arquivo de teste o nome correto da classe, dos métodos que você deve implementar, bem como os
//    parâmetros e tipos de retorno de cada método.
// 2. documentar a classe e seus métodos, seguindo o padrão do arquivo paleta.h.
// 3. implementar no arquivo imagem.cpp os métodos da classe.
