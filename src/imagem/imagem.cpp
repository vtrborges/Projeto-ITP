#include "imagem.h"
#include <fstream>

int converte (std::string numero) {
    int valor = 0;

    for (int i = 0; i < numero.length(); i++) {
        valor = valor * 10 + (numero[i] - '0');
    }

    return valor;
}

Imagem::Imagem(): largura(0), altura(0), bitmap(nullptr) {

}

Imagem::Imagem(int largura, int altura){
    this->largura = largura;
    this->altura = altura;

    bitmap = new Cor*[altura];

    for (int i = 0; i < altura; i++) {
        bitmap[i] = new Cor[largura];
    }

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            bitmap[i][j] = {0, 0, 0};
        }
    }
}

Imagem::~Imagem() {

    for (int i = 0; i < altura; i++) {
        delete[] bitmap[i];
    }

    delete[] bitmap;
}

Cor Imagem::obterPixel(int linha, int coluna) {
    return bitmap[coluna][linha];
}

bool Imagem::definePixel(int linha, int coluna, Cor cor) {

    if (coluna < altura && linha < largura && linha >= 0 && coluna >= 0) {
        bitmap[coluna][linha] = cor;
        return true;
    }
    return false;
}

bool Imagem::lerPPM(std::string nomeArquivo) {
    int valorMaximo;
    std::string linha;
    std::string dimensoes;
    std::ifstream arquivo(nomeArquivo);


    if (!arquivo.is_open()) {
        return false;
    }

    if (!getline(arquivo, linha) || linha != "P3") {
        return false;
    }

    int novaLargura;
    int novaAltura;
   
    if (!(arquivo >> novaLargura >> novaAltura >> valorMaximo)) {
        return false;
    }

    for (int i = 0; i < altura; i++) {
        delete[] bitmap[i];
    }
    delete[] bitmap;

    this->largura = novaLargura;
    this->altura = novaAltura;

    bitmap = new Cor*[novaAltura];

    for (int i = 0; i < novaAltura; i++) {
        bitmap[i] = new Cor[novaLargura];
    }
    
    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) {
            arquivo >> bitmap[i][j].r;
            arquivo >> bitmap[i][j].g;
            arquivo >> bitmap[i][j].b;
        }
    }

    return true;
}

bool Imagem::salvarPPM(const std::string &nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            return false;
        }
    
    arquivo << "P3\n";
    arquivo << largura << " " << altura << "\n";
    arquivo << 255 << "\n";

    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) {
            arquivo << bitmap[i][j].r << " ";
            arquivo << bitmap[i][j].g << " ";
            arquivo << bitmap[i][j].b << "\n";
        }
    }

    arquivo.close();
    return true;
}

int Imagem::obterAltura() {
    return altura;
}

int Imagem::obterLargura() {
    return largura;
}