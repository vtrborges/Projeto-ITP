#include "paleta.h"
#include <fstream>
#include <iostream>

// implemente aqui os métodos da classe Paleta, conforme especificado no arquivo de cabeçalho paleta.h

int converte (std::string corHex) {
    int cor = 0;
    char c;

    for (int i = 0; i < 2; i++) {
        char c = corHex[i];

        if (c >= '0' && c <= '9') {
            cor = cor * 16 + (c - '0');
        }
        else if (c >= 'A' && c <= 'F') {
            cor = cor * 16 + ( 10 + c - 'A' );
        }
        else if (c >= 'a' && c <= 'f') {
            cor = cor * 16 + ( 10 +  c - 'a' );
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

Paleta::~Paleta(){
    delete[] cores;
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