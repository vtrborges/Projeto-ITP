#include "imagem.h"
#include <fstream>

int converte (std::string numero) {
    int valor = 0;

    for (int i = 0; i < numero.lenght(); i++) {
        valor = valor * 10 + (numero[i] - '0');
    }

    return valor;
}

Imagem::Imagem(int largura, int altura){
    largura = this->largura;
    altura = this->altura;

    bitmap = new Cor*[largura];

    for (int i = 0; i < largura; i++) {
        bitmap[i] = new Cor[altura];
    }

    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < altura; j++) {
            bitmap[i][j] = {0, 0, 0};
        }
    }
}

Imagem::~Imagem() {

    for (int i = 0; i < largura; i++) {
        delete[] bitmap[i];
    }

    delete[] bitmap;
}

Cor Imagem::obterPixel(int linha, int coluna) {
    return bitmap[linha][coluna];
}

bool Imagem::definePixel(int linha, int coluna, Cor cor) {

    if (linha < altura && coluna < largura) {
        bitmap[linha][coluna] = cor;
        return true
    }
    return false;
}

bool Imagem::lerPPM(std::string nomeArquivo) {
    char c;
    std::string linha;
    std::string dimensoes;
    std::ifstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            return false;
        }

        if (!getline(arquivo, linha) || linha != "P3") {
            return false;
        }

    while (arquivo.get(c) && c != ' ') {
        dimensoes += c;
    }

    this->largura = converte(dimensoes)


}