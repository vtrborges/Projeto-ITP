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
    Pixel** bitmap;

private:

/**
* Aloca dinamicamente uma imagem (matriz de cores) com a largura igual ao num. de colunas 
* e altura igual ao num. de linhas.
* @param largura: largura da imagem (número de colunas), zero por padrão;
* @param altura: altura da imagem (número de linhas), zero por padrão;
* @return verdadeiro se alocou; falso se as dimensões forem inválidas.
*/
    bool alocar(int largura, int altura);

/**
* libera a memória alocada dinamicamente.
*/
    void liberar();

/**
* Função auxiliar para 'definePixel' e 'obterPixel' que verifica se um pixel está dentro dos limites de bitmap.
* @param i: linha i da matriz;
* @param j: coluna j da matriz;
* @return retorna verdadeiro se o pixel está dentro dos limites da matriz bitmap e falso caso contrário.
*/
    bool ehPixel(int i, int j) const;

public:

/**
* Construtor que aloca dinamicamente uma imagem (matriz de cores) com a largura igual ao num. de colunas 
* e altura igual ao num. de linhas.
* @param largura: largura da imagem (número de colunas), zero por padrão;
* @param altura: altura da imagem (número de linhas), zero por padrão;
*/
    Imagem(int largura = 0, int altura = 0);

/**
* Destrutor que libera a memória alocada dinamicamente.
*/
    ~Imagem();

/**
* Consulta o pixel dada a coordenada na matriz.
* @param j: coluna j da matriz;
* @param i: linha i da matriz;
* @return o pixel da respectiva linha e coluna. Retorna um "pixel sentinela" definido por {-1, -1, -1} se
* os valores de linha e coluna não estiverem dentro dos limites da matriz bitmap;
*/
    Pixel obterPixel(int j, int i) const;

/**
* Define o pixel dada a coordenada na matriz.
* @param j: coluna j da matriz;
* @param i: linha i da matriz;
* @param cor: a cor desejada para o pixel;
* @return retorna verdadeiro se foi possível alterar o pixel e falso caso contrário.
*/
    bool definePixel(int j, int i, Pixel cor);


/**
 * Lê uma imagem no formato PPM (P3) a partir de um arquivo. Se as dimensões da imagem no
 * arquivo forem diferentes das da imagem atual, a imagem é redimensionada e o conteúdo
 * anterior é descartado.
* @param nomeArquivo: nome do arquivo que representa uma imagem ppm do qual serão extraídas as informações.
* @return Retorna falso quando:
* - Não foi possível ler o arquivo;
* - Não se não se trata de um arquivo .ppm (não inicia com "P3").
* - Os valores de largura e altura e o trio RGB de cada pixel apresentam valores incoerentes.
* Retorna verdadeiro caso contrário.
*/
    bool lerPPM(std::string nomeArquivo);

/**
 * Salva a imagem em um arquivo no formato PPM (P3), com valor máximo 255. Se o arquivo já
 * existir, ele é sobrescrito.
 * @param nomeArquivo: nome do arquivo onde a imagem será salva.
 * @return verdadeiro se a imagem foi salva; falso se não foi possível abrir o arquivo para escrita.
 */
    bool salvarPPM(const std::string &nomeArquivo) const;

/**
* @return altura da imagem.
*/
    int obterAltura() const;

/**
* @return largura da imagem.
*/
    int obterLargura() const;
};

// Lembre-se de:
// 1. verificar no arquivo de teste o nome correto da classe, dos métodos que você deve implementar, bem como os
//    parâmetros e tipos de retorno de cada método.
// 2. documentar a classe e seus métodos, seguindo o padrão do arquivo paleta.h.
// 3. implementar no arquivo imagem.cpp os métodos da classe.
