#pragma once

#include "../imagem/imagem.h"

class Terreno {
    int tamanho;
    int** mapa_altitudes;

    bool alocar(int tamanho);
    void liberar();
    bool diamond();
    bool square();

public:
    Terreno(int tamanho = 0);
    ~Terreno();
    bool gerarTerreno();
    int consultarAltitude();
    int obterLargura();
    int obterProfundidade();
};