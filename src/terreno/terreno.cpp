#include "terreno.h"
#include <iostream>


bool Terreno::alocar(int tamanho) {
    
    if (tamanho > 0) {
        liberar();
        this->tamanho = tamanho;

        mapa_altitudes = new int*[tamanho];

        for (int i = 0; i < tamanho; i++) {
            mapa_altitudes[i] = new int[tamanho];
        }

        return true;
    }

    std::cerr << "tamanho invalido, [tamanho: " << tamanho << "]\n";
    return false;
}

void Terreno::liberar() {
        
    if (mapa_altitudes != nullptr) {
        for (int i = 0; i < tamanho; i++) {
            delete[] mapa_altitudes[i];
        }
    }

    delete[] mapa_altitudes;
    mapa_altitudes = nullptr;
}

Terreno::Terreno(int tamanho): tamanho(0), mapa_altitudes(nullptr){
    alocar(tamanho);
}

Terreno::~Terreno() {
    liberar();
}

