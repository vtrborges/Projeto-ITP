#include "imagem.h"
#include <fstream>
#include <iostream>


bool Imagem::alocar(int largura, int altura) {

    if (largura > 0 && altura > 0) {
        liberar();
        this->largura = largura;
        this->altura = altura;

        bitmap = new Pixel*[altura];

        for (int i = 0; i < altura; i++) {
            bitmap[i] = new Pixel[largura];
        }

        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                bitmap[i][j] = {0, 0, 0};
            }
        }

        return true;
    }

    std::cerr << "largura ou altura invalidas, [largura: " << largura << "] [altura: " << altura << "]\n";
    return false;

}

void Imagem::liberar() {
    
    if (bitmap != nullptr) {
        for (int i = 0; i < altura; i++) {
            delete[] bitmap[i];
        }
    }

    delete[] bitmap;
    bitmap = nullptr;
}

Imagem::Imagem(int largura, int altura): largura(0), altura(0), bitmap(nullptr) {
    alocar(largura, altura);
}


Imagem::~Imagem() {
    liberar();
}

bool Imagem::ehPixel(int i, int j) const {

    return i >= 0 && i < altura &&
    j >= 0 && j < largura;
}

Pixel Imagem::obterPixel(int j, int i) const {

    if (ehPixel(i,j)) {
        return bitmap[i][j];
    }

    return {-1, -1, -1};
}

bool Imagem::definePixel(int j, int i, Pixel cor) {

    if (ehPixel(i,j)) {
        bitmap[i][j] = cor;
        return true;
    }

    std::cerr << "pixel nao esta na matriz, li [j: " << j << "] [i: " << i << "]\n";
    return false;
}

bool Imagem::lerPPM(std::string nomeArquivo) {
    std::string linha;
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "nao abriu: " << nomeArquivo << "\n";
        return false;
    }

    if (!(arquivo >> linha) || linha != "P3") {
        std::cerr << "cabecalho invalido, li: [" << linha << "]\n";
        return false;
    }

    int novaLargura;
    int novaAltura;
    int valorMaximo;
    int subpixel[3];
   
    if (!(arquivo >> novaLargura >> novaAltura >> valorMaximo)) {
        std::cerr << "nao leu novaLargura, novaAltura ou valorMaximo\n";
        return false;
    }

    if (!alocar(novaLargura, novaAltura)) {
        std::cerr << "tentou alocar com alturas e larguras invalidas\n";
        return false;
    }
    
    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) {

            for (int k = 0; k <= 2; k++) {
                if (!(arquivo >> subpixel[k])) {
                    return false;
                }
                if (subpixel[k] < 0 || subpixel[k] > valorMaximo) {
                    return false;
                }
            }

            bitmap[i][j].r = subpixel[0];
            bitmap[i][j].g = subpixel[1];
            bitmap[i][j].b = subpixel[2];
        }
    }

    return true;
}

bool Imagem::salvarPPM(const std::string &nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            std::cerr << "nao abriu: " << nomeArquivo << "\n";
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

int Imagem::obterAltura() const{
    return altura;
}

int Imagem::obterLargura() const {
    return largura;
}