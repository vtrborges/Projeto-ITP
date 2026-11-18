#include "paleta.h"
#include <fstream>
#include <iostream>

// implemente aqui os métodos da classe Paleta, conforme especificado no arquivo de cabeçalho paleta.h

int converte (std::string corHex) {
    int cor = 0;
    int mult = 16;

    for (int i = 0; i < 2; i++, mult /= 16) {
        if ((int)corHex[i] >= 48 && (int)corHex[i] <= 57) {
            cor += ( (int)corHex[i] - 48 ) * mult;
        }
        else if ((int)corHex[i] >= 97 && (int)corHex[i] <= 102) {
            cor += (10 +(int)corHex[i] - 97 ) * mult;
        }
    }

    return cor;
}

Paleta::Paleta(int tamanho) {
    this->tamanho = tamanho;
    cores = new Cor[tamanho];
    quantidade = 0;
}

Paleta::Paleta(const std::string& nomeArquivo) {
    std::string linha;
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cout << "Erro de abertura";
        tamanho = 0;
        quantidade = 0;
        cores = nullptr;
        return;
    }

    tamanho = 0;

    while (std::getline(arquivo, linha)) {
        tamanho++;
    }

    arquivo.close();

    arquivo.open(nomeArquivo);

    cores = new Cor[tamanho];
    quantidade = 0;
    
    while (std::getline(arquivo, linha)) {
        cores[quantidade].r = converte(linha.substr(1,2));
        cores[quantidade].g = converte(linha.substr(3,2));
        cores[quantidade].b = converte(linha.substr(5,2));
        quantidade++;
    }

    arquivo.close();
}

int Paleta::obterTamanho() const {
    return tamanho;
}

int Paleta::obterQuantidade() const {
    return quantidade;
}

void Paleta::adicionarCor(const Cor& cor) {
    if (quantidade < tamanho) {
        cores[quantidade] = cor;
        quantidade++;
    }
}

Cor Paleta::obterCor(int indice) {
    if (indice >= 0 && indice < quantidade) {
        return cores[indice];
    }

    return {0, 0, 0};

}